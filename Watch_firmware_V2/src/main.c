/*
--------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------

Author: Oliver Tattersfied
Date: 09/02/2022

* Firmware for watch based on atmega328p. Displays time, data, day of week and time in binary using following format:
  Hour: binary number
  Minute: binary number
  Second: binary number

* Can configure time, date and day of week

* deep sleep will be triggered after ten seconds and can be woken up from left button

--------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------
*/

// built in libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <avr/sleep.h>
#include <avr/power.h>


// user defined libraries
#include "lcd.h"
#include "usart.h"
#include "DS3231_rtc.h"
#include "debounce.h"


// macros
#define SET_PIN_HIGH(port, pin) port |= (1 << pin)
#define SET_PIN_LOW(port, pin) port &= ~(1 << pin)
#define READ_PIN(port_input_addr, pin) (1<<pin) & port_input_addr
#define TOGGLE(port, pin) port ^= (1<<pin)
#define SLEEP_STATE_COUNT 1220 // number of timer1 overflows equal to 10 seconds with prescaler set at 1
#define ERROR 100
#define PARAMETERS 6 // how many time parameters
#define PAGE_NUM 3

// functions
void init(void); // initialise all peripherals for watch
void main_menu(void); // main menu
void binary_time(void); // displays current time in binary
void settings(void); // calibrate time settings
char* format_weekday(uint8_t input); // return day of week as string 
void print_state(uint16_t input); // debug output for printing numbers to terminal
uint8_t check_button_states(); // check button states
void page_select_control(); // select which page you are on
void decimal_to_binary(uint8_t input, char binary_buffer[]); // converts input decimal number and outputs as binary string
void goToSleep(void); // will put atmega328p into deep sleep
void INT0init(void); // intitialise INT0 interrupt
void timer1Init(void); // intitialise timer 1 to keep track when atmega328p is put to sleep

// global variables
char buffer[20]; // buffer for formatting characters into SSD1306 RAM
rtc_time time; // store time and date
int8_t page_select = 0; // counter to select which page to select 
uint8_t parameter_select = 0; // variable to hold which time parameter is selected
uint8_t parameter_increment = 0; // increment selected parameter
uint16_t sleep_state_counter = 0; // counter to keep track of how many times timer 1 has overflown
volatile uint8_t sleep_state = 0; // flag to tell when to put atmega328p to sleep



int main(void) {
    init();

    sei(); // enable global interrupts
    while(1){

      // check if sleep state is active  
      if( sleep_state == 1 ){
          lcd_sleep(YES);
          goToSleep();
          sleep_state = 0;
          init();
      }
      
      if( page_select == 0 ){
        main_menu();
      }

      if( page_select == 1 ){
        binary_time();
      }

      if( page_select == 2 ){
        settings();
      }
      
      page_select_control();

      lcd_display();
      _delay_ms(10);
      lcd_clear_buffer();
    }
}


void goToSleep(void) {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    cli();                         //stop interrupts to ensure the BOD timed sequence executes as required
    power_all_disable();
    sleep_enable();
    sleep_bod_disable();           //for AVR-GCC 4.3.3 and later, this is equivalent to the previous 4 lines of code  
    sei();                         //ensure interrupts enabled so we can wake up again
    sleep_cpu();                   //go to sleep
    sleep_disable();               //wake up here

    power_twi_enable();
    power_timer1_enable();

    // set all pins to output so no floating pins will cause current drain
    DDRB = 0xff;
    PORTB = 0xff;
    
    DDRC = 0xff;
    PORTC = 0xff;
    
    DDRD = 0Xff;
    PORTD = 0xff;

}


void main_menu(void) {
  get_rtc_time(&time);
  lcd_drawRect(0, 0, 127, 63, WHITE); // set up border
  lcd_drawRect(3, 3, 124, 60, WHITE); // set up border 
  uint8_t y_pos = 1;
  uint8_t x_pos = 4;

  // print time
  lcd_gotoxy(x_pos, y_pos);
  sprintf(buffer, "Time: %d-%d-%d", time.hours, time.minutes, time.seconds);
  lcd_puts(buffer);

  // print date
  lcd_gotoxy(x_pos, y_pos+2);
  sprintf(buffer, "Date: %d-%d-%d", time.year, time.month, time.date);
  lcd_puts(buffer);

  // print day of week
  lcd_gotoxy(x_pos, y_pos+4);
  sprintf(buffer, "Day: %s", format_weekday( time.weekday ) );
  lcd_puts(buffer);
}


void binary_time(void) {
  get_rtc_time(&time);
  lcd_drawRect(0, 0, 127, 63, WHITE); // set up border
  lcd_drawRect(3, 3, 124, 60, WHITE); // set up border
  uint8_t y_pos = 1;
  uint8_t x_pos = 4;
  
  
  char binary_hour_string[] = "00000000";
  lcd_gotoxy(x_pos, y_pos);
  decimal_to_binary( time.hours, binary_hour_string );
  sprintf(buffer, "Hour: %s", binary_hour_string);
  lcd_puts(buffer);

  char binary_min_string[] = "00000000";
  lcd_gotoxy(x_pos, y_pos+2);
  decimal_to_binary( time.minutes, binary_min_string );
  sprintf(buffer, "Min:  %s", binary_min_string);
  lcd_puts(buffer);

  char binary_sec_string[] = "00000000";
  lcd_gotoxy(x_pos, y_pos+4);
  decimal_to_binary( time.seconds, binary_sec_string );
  sprintf(buffer, "Sec:  %s", binary_sec_string);
  lcd_puts(buffer);
  
}


void decimal_to_binary(uint8_t input, char binary_buffer[]) {
    // counter for binary array
    int i = 0;
    while (input > 0) {
 
        // storing remainder in binary array
        if(input % 2){
          binary_buffer[i] = '1';
        }
        else{
          binary_buffer[i] = '0';
        }
       
        input = input / 2;
        i++;
    }
 
    // reverse binary string to be MSB
    binary_buffer = strrev( binary_buffer );
}


void settings(void) {
  lcd_drawRect(0, 0, 127, 63, WHITE); // set up border
  lcd_drawRect(3, 3, 124, 60, WHITE); // set up border
  uint8_t y_pos = 1;
  uint8_t x_pos = 6;

  lcd_gotoxy(x_pos, y_pos);
  lcd_puts("Settings");
  lcd_gotoxy(x_pos+1, y_pos+2);

  switch ( parameter_select )
  {
  case 0:
    lcd_gotoxy(x_pos, y_pos+2);
    sprintf(buffer, "Hour: < %d >", time.hours);
    lcd_puts(buffer);
    if(parameter_increment){
      time.hours++;
      if(time.hours > 23){
        time.hours = 1;
      }
    }
    break;
    
  case 1:
    lcd_gotoxy(x_pos-2, y_pos+2);
    sprintf(buffer, "Minute: < %d >", time.minutes);
    lcd_puts(buffer);
    if(parameter_increment){
      time.minutes++;
      if(time.minutes > 59){
        time.minutes = 1;
      }
    }
    break;

  case 2:
    lcd_gotoxy(x_pos-2, y_pos+2);
    sprintf(buffer, "Second: < %d >", time.seconds);
    lcd_puts(buffer);
    if(parameter_increment){
      time.seconds++;
      if(time.seconds > 59){
        time.seconds = 1;
      }
    }
    break;

  case 3:
    lcd_gotoxy(x_pos, y_pos+2);
    sprintf(buffer, "Date: < %d >", time.date);
    lcd_puts(buffer);
    if(parameter_increment){
      time.date++;
      if(time.month == 1 || time.month == 3 || time.month == 5 || time.month == 7 || time.month == 8 || time.month == 10 || time.month == 12){
        if(time.date > 31){
          time.date = 1;
        }
      }
      if(time.month == 4 || time.month == 6 || time.month == 9 || time.month == 11){
        if(time.date > 30){
          time.date = 1;
        }
      }
      else{
        if(time.date > 29){
          time.date = 1;
        }
      }
    }
    break;

  case 4:
    lcd_gotoxy(x_pos-1, y_pos+2);
    sprintf(buffer, "Month: < %d >", time.month);
    lcd_puts(buffer);
    if(parameter_increment){
      time.month++;
      if(time.month > 12){
        time.month = 1;
      }
    }
    break;

  case 5:
    lcd_gotoxy(x_pos-1, y_pos+2);
    sprintf(buffer, "Year: < %d >", time.year);
    lcd_puts(buffer);
    if(parameter_increment){
      time.year++;
      if(time.year > 2030){
        time.year = 2020;
      }
    }
    break;

  case 6:
    lcd_gotoxy(x_pos-4, y_pos+2);
    sprintf(buffer, "Day: < %s >", format_weekday(time.weekday) );
    lcd_puts(buffer);
    if(parameter_increment){
      time.weekday++;
      if(time.weekday > 7){
        time.weekday = 1;
      }
    }
    break;
  
  default:
    break;
  }

  set_rtc_date(&time);
  set_rtc_time(&time);
  set_rtc_weekday(&time);

}


char* format_weekday(uint8_t input) {
  switch (input)
  {
  case 1:
    return "Monday";
    break;
  
  case 2:
    return "Tuesday";
    break;

  case 3:
    return "Wednesday";
    break;
  
  case 4:
    return "Thursday";
    break;

  case 5:
    return "Friday";
    break;

  case 6:
    return "Saturday";
    break;

  case 7:
    return "Sunday";
    break;

  default:
    return "ERROR";
    break;

  }


}


uint8_t check_button_states() {
  uint8_t right_state = button_down(RIGHT_BUTTON);
  uint8_t left_state = button_down(LEFT_BUTTON);
  

  if( right_state == 1 && left_state == 1 ){
    sleep_state_counter = 0;
    return 0;
  }
  
  else{
    if( right_state == 1 ){
      sleep_state_counter = 0;
      return 1;
    }

    if( left_state == 1){
      sleep_state_counter = 0;
      return 2;
    }

    else{
      return ERROR;
    }
    
  }

}


void page_select_control() {
  uint8_t state = check_button_states();
  
  if(page_select == 2){
    switch (state)
    {
    case 0:
      page_select++;
      break;

    case 1:
      parameter_select++;
      break;

    case 2:
      parameter_increment = 1;
      break;
    
    default:
      parameter_increment = 0;
      break;
    }

    if(parameter_select > PARAMETERS){
      parameter_select = 0;
    }

  }
  else {
    parameter_select = 0;
    
    if(state == 0){
      page_select++;
    }

    if(page_select > PAGE_NUM - 1){
      page_select = 0;
    }

  }
}


void INT0init(void) {
    SET_PIN_LOW(DDRD, PD2); // enable PD2 as input
    SET_PIN_HIGH(PORTD, PD2); // enable pullup on PD2
    
    // set INT0 to interrupt on falling edge 
    SET_PIN_LOW( EICRA, ISC00 ); 
    SET_PIN_HIGH( EICRA, ISC01 );

    SET_PIN_HIGH( EIMSK, INT0 ); // enable interrupt bit
}


void timer1Init(void) {
    // set timer 1 to normal mode
    SET_PIN_LOW( TCCR1A, WGM10 );
    SET_PIN_LOW( TCCR1A, WGM11 );
    SET_PIN_LOW( TCCR1B, WGM12 );
    SET_PIN_LOW( TCCR1B, WGM13 );

    // set prescaler to 256
    SET_PIN_HIGH( TCCR1B, CS10 );
    SET_PIN_LOW( TCCR1B, CS11 );
    SET_PIN_LOW( TCCR1B, CS12 );

    // enable interrupt bit
    SET_PIN_HIGH( TIMSK1, TOIE1 );
}


void init(void) {
  debounce_init();  
  timer1Init();
  INT0init();
  rtc_init();
  lcd_init(LCD_DISP_ON);
  lcd_clrscr();
  lcd_set_contrast(0x00);
}

// internal timer 1 overflow interrupt
ISR(TIMER1_OVF_vect) {

  debounce();
   
  sleep_state_counter++;
  if( sleep_state_counter >= SLEEP_STATE_COUNT ){
    sleep_state = 1;
    sleep_state_counter = 0;
  }
  

  
}


ISR(INT0_vect) {

}

