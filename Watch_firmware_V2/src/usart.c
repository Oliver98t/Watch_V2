#include "usart.h"


void USART0Init(int buad_rate) {
    // Set baud rate
    UBRR0 = (((F_CPU / (buad_rate * 16UL))) - 1);
    //UBRR0 = UBRR_VALUE;
    // Set frame format to 8 data bits, no parity, 1 stop bit
    UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
    //enable transmission and reception
    UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
}

void USART0SendByte(uint8_t u8Data) {
    //wait while previous byte is completed
    while(!(UCSR0A&(1<<UDRE0))){};
    // Transmit data
    UDR0 = u8Data;
}

void USART0SendString(char* string, uint8_t size){
    // loop through char array 
    for(uint8_t i = 0; i < size; i++){
        USART0SendByte( (uint8_t)string[i] );
    }
    USART0SendByte('\n');
    return;
}

void USART0Write(char* input){
    USART0SendString( input, strlen(input) );
}

uint8_t USART0ReceiveByte() {
    // Wait for byte to be received
    while(!(UCSR0A&(1<<RXC0))){};
    // Return received data
    return UDR0;
}
