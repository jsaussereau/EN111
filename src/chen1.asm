#include "p16f84a.inc"

; CONFIG
; __config 0xFFF2
 __CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _CP_OFF	; d�finit logiciellement la valeur qui sera charg�e  
							; � la programmation dans le registre CONFIG


;*********************************************************************
;                              ASSIGNATIONS                          *
;*********************************************************************

TRISA_VAL	EQU	H'00'	; Valeur � charger dans registre TRISA 
TRISB_VAL	EQU	H'01'	; Valeur � charger dans registre TRISB 
INIT_PORTA	EQU	H'FF'	; Valeur initiale � charger dans registre PORTA 
INIT_PORTB	EQU	H'00'	; Valeur initiale � charger dans registre PORTB 

;*********************************************************************
;                             DEFINE                                 *
;*********************************************************************

#DEFINE BOUTON	PORTB, 0	; pour d�signer le bouton poussoir de façon plus lisible

;*********************************************************************
;                             MACRO                                  *
;*********************************************************************

BANK0	macro			; d�fini une macro "BANK0"
	bcf	STATUS, RP0	; passer en banque0
	endm			; fin de la macro

BANK1	macro
	bsf	STATUS, RP0	; passer en banque1
	endm

;*********************************************************************
;                   DECLARATIONS DE VARIABLES                        *
;*********************************************************************

CBLOCK 0x00C		; d�but de la zone de variables (pour exemple)

    VAR : 1		; d�clare une variable "VAR" de 1 octet (adresse 0x00C)
    TABLEAU : 10	; r�serve une zone m�moire de 10 octets (0x00D - 0x017)
			; (TABLEAU est l'adresse du 1er �l�ment)
    cmpt1 : 1		; compteur de boucles 1
    cmpt2 : 1		; compteur de boucles 2
    cmpt3 : 1		; compteur de boucles 3

ENDC			; Fin de la zone                        

;**********************************************************************
;                      DEMARRAGE SUR RESET                            *
;**********************************************************************

    org	    0x000 	; fixe l'adresse d'implantation en m�moire programme
			; de l'instruction qui suit
reset			
    goto    start		

;*********************************************************************
;                       INITIALISATIONS                              *
;*********************************************************************

init
	
    BANK1			; le bloc d'instructions de la macro BANK1 est ins�r� � la compilation
    movlw   TRISA_VAL	
    movwf   TRISA		
    movlw   TRISB_VAL
    movwf   TRISB	
    
    BANK0			; le bloc d'instructions de la macro BANK0 est ins�r� � la compilation
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

