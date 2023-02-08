
#include "p16f84a.inc"        ; insertion du fichier de d�finition des symboles 

; CONFIG
; __config 0xFFF2
 __CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _CP_OFF    ; d�finit logiciellement la valeur qui sera charg�e  
                                                        ; � la programmation dans le registre CONFIG

; ATTENTION : Si l'ent�te ci-dessus est g�n�r�e automatiquement avec la commande "Generate Source Code to Output"
;             cela va provoquer une erreur � la compilation sous UNIX car le fichier "p16F84A.inc"
;             est en fait nomm� en lettres minuscules "p16f84a.inc" dans le r�pertoire d'installation.
;             Comme UNIX est sensible � la casse il faut donc effectuer cette rectification...manuellement !                    
                            
;**********************************************************************
;                      DEMARRAGE SUR RESET                            *
;**********************************************************************

    org        0x000        ; fixe l'adresse d'implantation (m�moire programme) 
                            ; du bloc d'instructions qui suit

;*********************************************************************
;                       INITIALISATION                               *
;*********************************************************************
    
    bsf        STATUS, RP0
    clrf    TRISA
    bcf        STATUS, RP0

;*********************************************************************
;                      PROGRAMME PRINCIPAL                           *
;*********************************************************************

debut                ; �tiquette (� placer en 1�re colonne)
            
    movlw   0x0A
    movwf   PORTA
;    comf    PORTA,f  ; instruction � d�commenter lors de la simu (leds en logique invers�e)
    goto debut

END                  ; directive de fin de fichier

