/*
 * PWM _DRV8825.cpp
 *
 * Created: 17.08.2024 21:51:05
 * Author : Adrian
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16000000UL

#define DIR_PIN PINB0 
#define PWM_PIN PINB1

void init_PWM()
{
    
    TCCR1A = (1<<COM1A1) | (1<<WGM11);           
    TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS11);  

    ICR1 = 1999;  
    OCR1A = 999;  
    }

int main(void)
{
  
    DDRB = (1 << PB1) | (1 << DIR_PIN);  
    
    init_PWM(); 

    while (1)
    {
       
        PORTB |= (1 << DIR_PIN);  
        _delay_ms(10000); 
       
        PORTB &= ~(1 << DIR_PIN);  
        _delay_ms(10000);  
    }
}
