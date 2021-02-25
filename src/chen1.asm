#include "p16f84a.inc"

; CONFIG
; __config 0x3FF2
 __CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _CP_OFF


;*********************************************************************
;                              ASSIGNATIONS                          *
;*********************************************************************

TRISA_VAL	EQU	H'00'	; Valeur à charger dans registre TRISA 
TRISB_VAL	EQU	H'01'	; Valeur à charger dans registre TRISB 
INIT_PORTA	EQU	H'FF'	; Valeur initiale à charger dans registre PORTA 
INIT_PORTB	EQU	H'00'	; Valeur initiale à charger dans registre PORTB 

;*********************************************************************
;                             DEFINE                                 *
;*********************************************************************

#DEFINE BOUTON	PORTB, 0	; pour désigner le bouton poussoir de façon plus lisible

;*********************************************************************
;                             MACRO                                  *
;*********************************************************************

BANK0	macro			; défini une macro "BANK0"
	bcf	STATUS, RP0	; passer en banque0
	endm			; fin de la macro

BANK1	macro
	bsf	STATUS, RP0	; passer en banque1
	endm

;*********************************************************************
;                   DECLARATIONS DE VARIABLES                        *
;*********************************************************************

CBLOCK 0x00C		; début de la zone de variables (pour exemple)

    VAR : 1		; déclare une variable "VAR" de 1 octet (adresse 0x00C)
    TABLEAU : 10	; réserve une zone mémoire de 10 octets (0x00D - 0x017)
			; (TABLEAU est l'adresse du 1er élément)
    cmpt1 : 1		; compteur de boucles 1
    cmpt2 : 1		; compteur de boucles 2
    cmpt3 : 1		; compteur de boucles 3

ENDC			; Fin de la zone                        

;**********************************************************************
;                      DEMARRAGE SUR RESET                            *
;**********************************************************************

    org	    0x000 	; fixe l'adresse d'implantation en mémoire programme
			; de l'instruction qui suit
reset			
    goto    start		

;*********************************************************************
;                       INITIALISATIONS                              *
;*********************************************************************

init
	
    BANK1			; le bloc d'instructions de la macro BANK1 est inséré à la compilation
    movlw   TRISA_VAL	
    movwf   TRISA		
    movlw   TRISB_VAL
    movwf   TRISB	
    
    BANK0			; le bloc d'instructions de la macro BANK0 est inséré à la compilation
    movlw   INIT_PORTA
    movwf   PORTA
    movlw   INIT_PORTB
    movwf   PORTB
    return		

;*********************************************************************
;                   SOUS-PROGRAMME DE TEMPORISATION                  *
;*********************************************************************

tempo
    movlw   2		
    movwf   cmpt3		
boucle3
    clrf    cmpt2		
boucle2
    clrf    cmpt1		
boucle1
    nop			
    decfsz  cmpt1, f	
    goto    boucle1	
    decfsz  cmpt2, f
    goto    boucle2		
    decfsz  cmpt3, f	
    goto    boucle3		
    return	
		
;*********************************************************************
;                      PROGRAMME PRINCIPAL                           *
;*********************************************************************

start
    call    init
boucle
    call    tempo
    goto    boucle

END 			; directive fin de fichier

