// On ajoute la configuration du PIC... (on peut la g�n�rer automatiquement comme ci-dessous selon la m�me proc�dure qu'en assembleur)

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

extern void tempo();       //prototypage si fonction tempo d�clar�e dans un autre fichier

// unsigned char cmpt;     // d�claration n�cessaire pour pouvoir utiliser _cmpt dans la routine en assembleur (voir illustration plus bas)

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

 --- on peut aussi �crire toute une routine en assembleur :
 
 #asm				// d�but de routine assembleur
 	BANKSEL(_cmpt)	// attention la gestion des BANK n'est plus assur�e dans une routine ASM (utiliser la macro BANKSEL)
 boucle             // on peut placer des �tiquettes pour les d�routements comme en assembleur
    movlw   10		
    movwf  _cmpt    // (notez le pr�fixe _, ne pas oublier de d�clarer cmpt en variable globale)
    goto boucle
  
 #endasm			// fin de routine assembleur									

--------- FONCTION D'INTERRUPTION (1 seule possible avec les PIC16XX !)
 
void __interrupt() isr() { // le nom 'IT' n'a pas d'importance tant qu'il y a le prefixe 'interrupt'	  

    if (INTCONbits.T0IF == 1) { // teste si c'est le timer qui a d�clench� l'IT
        // action � effectuer
        INTCONbits.T0IF = 0; // le contexte est sauvegard� mais il faut r�initialiser le flag de la source d'IT  autoris�es (flag xxIF)
    }

    if (INTCONbits.xxIF == 1) { // on fait de m�me pour traiter les autres IT autoris�es (flag xxIF)
        INTCONbits.xxIF = 0;					
    }
}

*/
