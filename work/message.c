// Ajouter la configuration du PIC...

__EEPROM_DATA (0x07,0x60,0xBE,0x8E,0xFE,0x66,0x00,0);	/* valeur initiale du registre OPTION (vitesse)
                                                           puis les codes du message "16F84 " puis 0 (+ caractère \0 de fin de chaîne)   */

// unsigned char cmpt;     // déclaration nécessaire pour pouvoir utiliser _cmpt dans la routine en assembleur (voir illustration plus bas)

void init() {

}

void main() { 
    init ();

    while (1) { // boucle infinie indispensable dans la fonction main () !

    }
}


/*			ILLUSTRATIONS	
  
 EXEMPLES DE MACROs		

 valeur = eeprom_read(ADRESSE);     // permet de lire l'EEPROM 	avec 0x00 =< ADRESSE <= 0x3F   		
 eeprom_write (0x00, tempo);        // permet d'écrire dans l'EEPROM 		"	"	"	"
 
 asm("sleep");                      // permet d'introduire une instruction assembleur			

  #asm				// on peut aussi écrire toute					
 	movlw   10		// une routine en assembleur
    movwf  _cmpt    // (noter le préfixe _, ne pas oublier de déclarer cmpt en variable globale)
  #endasm															

FONCTION D'INTERRUPTION (1 seule possible avec les PIC16XX !)
 
void interrupt IT() { // le nom 'IT' n'a pas d'importance tant qu'il y a le prefixe 'interrupt'	  

    if (T0IF == 1) { // teste si c'est le timer qui a déclenché l'IT
        // action à effectuer
        T0IF = 0; // le contexte est sauvegardé mais il faut réinitialiser le flag de la source d'IT
    }

    if (..IF == 1) { // on fait de même pour traiter les autres IT autorisées
        ..IF = 0;					
    }
}
 
*/
