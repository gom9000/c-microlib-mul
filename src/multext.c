/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 * @(#)multext.c  1.0  1999/05/02
 *   ________        _________________.________
 *  /  _____/  ____ /   _____/   __   \   ____/
 * /   \  ___ /  _ \\_____  \\____    /____  \
 * \    \_\  (  <_> )        \  /    //       \
 *  \______  /\____/_______  / /____//______  /
 *         \/              \/               \/
 *
 * Autore....: Alessandro Fraschetti
 * Libreria..: GoS'95 Micro Utility Library - Modulo TEXT
 * Note......:
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include <stdio.h>
#include "mul.h"


/*
 * Esegue lo shift circolare di N posizioni della stringa specificata.
 * le posizioni valide per lo shift sono tutti i codici ascii da 32 a 126.
 */
char *MUL_TEXT_shiftN(char *txt, int n)
{
    char min_ascii_text_code = 32;
	char max_ascii_text_code = 126;
	char *s = txt;
	int tmp;

    while ( (tmp = *s) ) {
		if (tmp >= min_ascii_text_code && tmp <= max_ascii_text_code) {
			tmp += (char)n;
			if (tmp > max_ascii_text_code)
			    tmp = min_ascii_text_code + (tmp - max_ascii_text_code);
		    if (tmp < min_ascii_text_code)
			    tmp = max_ascii_text_code - (min_ascii_text_code - tmp);
		}
		*s = (char)tmp;
		s++;
	}
    return txt;
}


/*
 * Esegue lo shift circolare di 13 posizioni della stringa specificata.
 * le posizioni valide per lo shift sono tutti i codici ascii corrispondenti
 * a caratteri alfabetici.
 */
char *MUL_TEXT_rot13(char *txt)
{
	char *s = txt;
	int tmp, delta;

    while ( (tmp = *s) ) {
		delta = ( tmp >= 'a'? 'a' - 'A' : 0);
		if ( (tmp-delta) >= 'A' && (tmp-delta) <= 'Z' ) {
			tmp += 13;
			if ( (tmp-delta) > 'Z')
			    tmp = 'A' + ((tmp-delta) - 'Z') + delta-1;
		}

		*s = (char)tmp;
		s++;
	}
    return txt;
}


/*
 * elimina tutti i caratteri ch alla sinistra della stringa di testo.
 */
char *MUL_TEXT_leftTrim(char* txt, char ch) {
	char *s, *s1;

    s = s1 = txt;
    while ( *s && *s == ch ) s++;
	while ( *s ) *s1++ = *s++;
	*s1 = '\0';

    return txt;
}


/*
 * elimina tutti i caratteri ch alla destra della stringa di testo.
 */
char *MUL_TEXT_rightTrim(char* txt, char ch) {
	char *s = txt;

    while ( *s ) s++;
    while ( --s > txt && *s == ch ) *s = '\0';

    return txt;
}


/*
 * elimina tutti i caratteri ch a destra e sinistra della stringa di testo.
 */
char *MUL_TEXT_trim(char* txt, char ch) {
	char *s, *s1;

    s = s1 = txt;
    while ( *s && *s == ch ) s++;
	while ( *s ) *s1++ = *s++;
	*s1 = '\0';
    while ( --s1 > txt && *s1 == ch ) *s1 = '\0';

    return txt;
}


/*
 * elimina tutti i caratteri ch ripetuti all'interno della stringa di testo.
 */
char *MUL_TEXT_inTrim(char* txt, char ch) {
	char *s, *s1;
	short flag = 0;

    s = s1 = txt;
	while ( *s )
		if ( *s == ch ) {
		    if ( flag ) {
		        s++;
            } else {
				flag++;
		        *s1++ = *s++;
			}
	    } else {
			flag = 0;
			*s1++ = *s++;
		}
	*s1 = '\0';

    return txt;
}
