#ifndef USART_H
#define USART_H
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void USART0Init(int baud_rate);
void USART0SendByte(uint8_t u8Data);
void USART0SendString(char* string, uint8_t size);
void USART0Write(char* input);
uint8_t USART0ReceiveByte();




#endif