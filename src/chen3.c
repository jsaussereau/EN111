// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#include <xc.h>

#define LEDS_RIGHT 0
#define LEDS_LEFT 4

#define LEDS_LEFT_STOP (1 << LEDS_LEFT)
#define LEDS_RIGHT_STOP (1 << LEDS_RIGHT)


unsigned char leds = LEDS_LEFT_STOP;


void init() {
    // Initialisation des entr�es/sorties
    TRISA = 0x00;
    
    // Initialisation du TIMER0
    //...
    
    // Initialisation des interruptions
    //...
}


void main() { 
    init();
    while (1) {  
        // on fait rien en boucle ! 
    }
}


void interrupt IT() {
    if (INTCONbits.T0IF == 1) {
        // faire clignoter la led
    }
}
