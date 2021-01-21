/*-----------------------------------------------------------------------------
* File            : test.c
* Autore          : Alessandro Fraschetti
* Funzione        : Test della routine epsilon della libreria MUL SYSTEM
* Parametri in    :
* Parametri out   :
* Note            :
*-----------------------------------------------------------------------------*/


#include <stdlib.h>
#include <stdio.h>
#include "mul.h" 


int main(void) {

    char ch;

    MUL_SYSTEM_cls();
	printf("Demo-test delle procedure del modulo SYSTEM\ndella libreria GoS'95 MUL - Micro Utility Library\n\n");
    printf("\npremere un tasto per continuare...");
	ch = MUL_SYSTEM_pause();
	printf("\n ...e' stato premuto il tasto [%c]\n", ch);
	printf("\nepsilon macchina = %e", MUL_SYSTEM_epsilon());
    printf("\n");

    return 0;
}
