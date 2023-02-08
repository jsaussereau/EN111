// On ajoute la configuration du PIC... (on peut la générer automatiquement comme ci-dessous selon la même procédure qu'en assembleur)

//------------------------------------------------------------------------------------------

// PIC16F84A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is enabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#include <xc.h>

//------------------------------------------------------------------------------------------

extern void tempo();       //prototypage si fonction tempo déclarée dans un autre fichier

// unsigned char cmpt;     // déclaration nécessaire pour pouvoir utiliser _cmpt dans la routine en assembleur (voir illustration plus bas)

void init() {

}

void main() { 
    init();

    while (1) {          // boucle infinie indispensable dans la fonction main () !
        tempo();
    }
}


/*			ILLUSTRATIONS	
  
--------- EXEMPLES DE MACROs		

 asm("sleep");                      // permet d'introduire une instruction assembleur (exemple avec SLEEP)			

 --- on peut aussi écrire toute une routine en assembleur :
 
 #asm				// début de routine assembleur
 	BANKSEL(_cmpt)	// attention la gestion des BANK n'est plus assurée dans une routine ASM (utiliser la macro BANKSEL)
 boucle             // on peut placer des étiquettes pour les déroutements comme en assembleur
    movlw   10		
    movwf  _cmpt    // (notez le préfixe _, ne pas oublier de déclarer cmpt en variable globale)
    goto boucle
  
 #endasm			// fin de routine assembleur									

--------- FONCTION D'INTERRUPTION (1 seule possible avec les PIC16XX !)
 
void __interrupt() isr() { // le nom 'IT' n'a pas d'importance tant qu'il y a le prefixe 'interrupt'	  

    if (INTCONbits.T0IF == 1) { // teste si c'est le timer qui a déclenché l'IT
        // action à effectuer
        INTCONbits.T0IF = 0; // le contexte est sauvegardé mais il faut réinitialiser le flag de la source d'IT  autorisées (flag xxIF)
    }

    if (INTCONbits.xxIF == 1) { // on fait de même pour traiter les autres IT autorisées (flag xxIF)
        INTCONbits.xxIF = 0;					
    }
}

*/
