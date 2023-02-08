// Ajouter la configuration du PIC...


__EEPROM_DATA (0x07,0x61,0xBF,0x8F,0xFF,0x67,0x01,0);	/* valeur initiale du registre OPTION (vitesse)
                                                           puis les codes du message "16F84 " puis 0 (+ caract�re \0 de fin de chaine)   */

// unsigned char cmpt;     // d�claration n�cessaire pour pouvoir utiliser _cmpt dans la routine en assembleur (voir illustration plus bas)

void init() {

}

void __interrupt() ISR_timer0() {	// une seule IT d�clench�e par le TIMER0
 
}

void main() { 
    init ();

    while (1) { // boucle infinie indispensable dans la fonction main () !

    }
}

/*
--------- Exemple de macros pour acc�der � l'EEPROM	

 valeur = eeprom_read(ADRESSE);     // permet de lire l'EEPROM 	avec 0x00 <= ADRESSE <= 0x3F   		
 eeprom_write (0x00,0xFF);         // permet d'�crire dans l'EEPROM (ici la valeur 0xFF � l'adresse 0x00)	
 
 */
