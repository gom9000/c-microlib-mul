/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 * @(#)mulsystem.c  1.0  1999/05/02
 *   ________        _________________.________
 *  /  _____/  ____ /   _____/   __   \   ____/
 * /   \  ___ /  _ \\_____  \\____    /____  \
 * \    \_\  (  <_> )        \  /    //       \
 *  \______  /\____/_______  / /____//______  /
 *         \/              \/               \/
 *
 * Autore....: Alessandro Fraschetti
 * Libreria..: GoS'95 Micro Utility Library - Modulo SYSTEM
 * Note......:
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "mul.h"


/*
 * Ritorna l'epsilon di macchina, o unità di arrotondamento dell'elaboratore.
 * Rappresenta il più piccolo numero reale che sommato ad 1 da come risultato
 * un numero floating maggiore di 1.
 * i = numero di cifre decimali della mantissa, e = epsilon di macchina.
 */
float MUL_SYSTEM_epsilon(void) {
	float epsilon = 1.0F;
    int   i = 0;

    while ( 1+epsilon > 1 ) {
		epsilon = epsilon/2;
		i++;
    }

    return 2*epsilon;
}


/*
 * Attende la pressione di un tasto.
 */
int MUL_SYSTEM_pause(void) {
    return getch();
}


/*
 * Richiama il comando cls di sistema.
 */
void MUL_SYSTEM_cls(void) {
    system("cls");
}
