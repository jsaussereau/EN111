
#include	<xc.h>  // inclut indirectement la d�finition des symboles et macros du PIC d�fini dans le projet
                    // (A mettre en t�te de fichier en g�n�ral, facultatif ici car le code ci-dessous n'utilise pas de registres propres au PIC)

void tempo() {
    unsigned long i;
    for (i=1 ; i<=16000 ; i++);
}
