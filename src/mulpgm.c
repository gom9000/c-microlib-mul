/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 * @(#)mulpgm.c  1.0  1999/05/02
 *   ________        _________________.________
 *  /  _____/  ____ /   _____/   __   \   ____/
 * /   \  ___ /  _ \\_____  \\____    /____  \
 * \    \_\  (  <_> )        \  /    //       \
 *  \______  /\____/_______  / /____//______  /
 *         \/              \/               \/
 *
 * Autore....: Alessandro Fraschetti
 * Libreria..: GoS'95 Micro Utility Library - Modulo PGM
 * Note......:
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include <stdio.h>
#include "mul.h"


char logo[80*6];

char *MUL_PGM_LOGO_1 = "%sGoS'95 Gomma Software 1995";

char *MUL_PGM_LOGO_4 = "%s  ___     ___ ___ ___ \n"    \
                       "%s / __|___/ __/ _ \\ __|\n"   \
                       "%s| (_-/ _ \\__ \\_, /__ \\\n" \
					   "%s \\___\\___/___//_/|___/\n";

char *MUL_PGM_LOGO_6 = "%s  ________               ________.________\n"       \
                       "%s /  _____/  ____  ______/   __   \\   ____/\n"      \
                       "%s/   \\  ___ /  _ \\/  ___/\\____    /____  \\ \n"   \
                       "%s\\    \\_\\  (  <_> )___ \\    /    //       \\\n"  \
                       "%s \\______  /\\____/____  >  /____//______  /\n"     \
                       "%s        \\/           \\/                \\/ \n\n";


/*
 * Inizializza la struttura PGMINFO.
 */
void MUL_PGM_initInfo(MUL_PGM_INFO *info) {

	info->name        = "\0";
	info->version     = "\0";
	info->vendor      = "\0";
	info->description = "\0";
	info->usage       = "\0";
	info->noptions    = 0;

    return;
}


/*
 * Scrive sul dispositivo di standard output le informazioni contenute nella
 * struttura PGMINFO.
 */
void MUL_PGM_info(MUL_PGM_INFO info) {

    if (*info.name) printf("%s", info.name);
	if (*info.version) printf("   Version %s\n", info.version);
	if (*info.vendor) printf("%s\n", info.vendor);

    return;
}


/*
 * Scrive sul dispositivo di standard output le informazioni contenute nella
 * struttura PGMINFO.
 */
void MUL_PGM_usage(MUL_PGM_INFO info) {
    int i;

    MUL_PGM_info(info);
    if (*info.description) printf("%s\n", info.description);
    if (*info.usage) printf("\n  usage: %s\n", info.usage);
	for (i=0; i<info.noptions; i++)
	    if (info.options[i]) printf("\n      %s\n", info.options[i]);

    return;
}


/*
 * Alloca una stringa contenente il logo GoS'95 formattata per la stampa a video.
 */
char *MUL_PGM_logo(char *tab, int height) {

	switch ( height ) {

		case 1:
  	    sprintf(logo, MUL_PGM_LOGO_1, tab);
		break;

		case 4:
  	    sprintf(logo, MUL_PGM_LOGO_4, tab, tab, tab, tab);
		break;

		case 6:
  	    sprintf(logo, MUL_PGM_LOGO_6, tab, tab, tab, tab, tab, tab);
		break;

		default:
  	    sprintf(logo, MUL_PGM_LOGO_1, "");
		break;

	}

    return logo;
}
