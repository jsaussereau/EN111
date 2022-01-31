
#include	<xc.h>  // inclut indirectement la définition des symboles et macros du PIC défini dans le projet
                    // (A mettre en tête de fichier en général, facultatif ici car le code ci-dessous n'utilise pas de registres propres au PIC)

void tempo() {
    unsigned long i;
    for (i=1 ; i<=16000 ; i++);
}
