
#include "p16f84a.inc"	    ; insertion de fichier

; CONFIG
; __config 0xFFF2
 __CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _CP_OFF	; définit logiciellement la valeur qui sera chargée  
							; à la programmation dans le registre CONFIG


;**********************************************************************
;                      DEMARRAGE SUR RESET                            *
;**********************************************************************

    org	    0x000 		; fixe l'adresse d'implantation (mémoire programme) 
 				; du bloc d'instructions qui suit

;*********************************************************************
;                       INITIALISATION                               *
;*********************************************************************
	
    bsf	    STATUS, RP0
    clrf    TRISA
    bcf	    STATUS, RP0

;*********************************************************************
;                      PROGRAMME PRINCIPAL                           *
;*********************************************************************

debut				; étiquette (à placer en 1ère colonne)
			
    movlw   0x0A
    movwf   PORTA
;    comf    PORTA,f		; instruction à décommenter lors de la simu (leds en logique inversée)
    goto debut

END				; directive de fin de fichier

