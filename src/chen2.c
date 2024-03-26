// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#include <xc.h>

extern void tempo();       //prototypage si fonction tempo declaree dans un autre fichier

#define LEDS_RIGHT 0
#define LEDS_LEFT 4

#define LEDS_LEFT_STOP (1 << LEDS_LEFT)
#define LEDS_RIGHT_STOP (1 << LEDS_RIGHT)


unsigned char leds = LEDS_LEFT_STOP;


void init() {
    // Initialisation des entrees/sorties
    TRISA = 0x00;
    
    // Initialisation du TIMER0
    //...
}


void tempo_timer() {
    //...
}


void main() { 
    init();
    while (1) {  
        while (leds != LEDS_LEFT_STOP) {
            leds <<= 1;
            PORTA = ~leds;
            tempo();
        }
        while (leds != LEDS_RIGHT_STOP) {
            leds >>= 1;
            PORTA = ~leds;
            tempo();
        }
    }
}
