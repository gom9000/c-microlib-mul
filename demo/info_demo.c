/*-----------------------------------------------------------------------------
* File            : test.c
* Autore          : Alessandro Fraschetti
* Funzione        : Test delle funzioni info/usage della libreria MUL PGM
* Parametri in    :
* Parametri out   :
* Note            :
*-----------------------------------------------------------------------------*/


#include <stdlib.h>
#include <stdio.h>
#include "mul.h" 


int main(void) {

    MUL_PGM_INFO info;
	MUL_PGM_initInfo(&info);

	char *options[] = {"file    file o elenco di files di cui visualizzare il contenuto.", 
		               "x       opzione per la visualizzazione in formato esadecimale.",
		               "o       opzione per la visualizzazione in formato ottale.",
		               "a       opzione per la visualizzazione in formato ascii.",
	                   "h       visualizza l'help sull'utilizzo dei parametri."};

	info.description = "Esegue il test delle routines di info/usage contenute nella libreria GoS'95 Micro Utility Library.";
    info.usage       = "info.exe [options]";
    info.noptions    = 5;
	info.options     = options;

	info.name        = "Info  GosUtil Library demo-test Utility";
	info.version     = "1.0";
	info.vendor      = "GoS'95 Gomma Software 1995";
	info.vendor      = MUL_PGM_logo("  ", 6);

    MUL_PGM_usage(info);

	return 0;
}
