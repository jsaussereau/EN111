// Ajouter la configuration du PIC...


__EEPROM_DATA (0x07,0x61,0xBF,0x8F,0xFF,0x67,0x01,0);	/* valeur initiale du registre OPTION (vitesse)
                                                           puis les codes du message "16F84 " puis 0 (+ caractère \0 de fin de chaîne)   */

// unsigned char cmpt;     // déclaration nécessaire pour pouvoir utiliser _cmpt dans la routine en assembleur (voir illustration plus bas)

void init() {

}

void __interrupt() ISR_timer0() {	// une seule IT déclenchée par le TIMER0
 
}

void main() { 
    init ();

    while (1) { // boucle infinie indispensable dans la fonction main () !

    }
}

/*
--------- Exemple de macros pour accéder à l'EEPROM	

 valeur = eeprom_read(ADRESSE);     // permet de lire l'EEPROM 	avec 0x00 <= ADRESSE <= 0x3F   		
 eeprom_write (0x00,0xFF);         // permet d'écrire dans l'EEPROM (ici la valeur 0xFF à l'adresse 0x00)	
 
 */
