/*-----------------------------------------------------------------------------
* File            : date_demo.c
* Autore          : Alessandro Fraschetti
* Funzione        : demo test delle routines MUL_DATE della libreria MUL
* Parametri in    :
* Parametri out   :
* Note            :
*-----------------------------------------------------------------------------*/


#include <stdlib.h>
#include <stdio.h>
#include "mul.h" 


int main(void)
{
    MUL_DATE d, d2;
	int gg = 15;
    char str[11];
	char *comp[] = {"minore", "uguale", "maggiore"};

    MUL_SYSTEM_cls();
	printf("Demo-test delle procedure del modulo SYSTEM\ndella libreria GoS'95 MUL - Micro Utility Library\n\n");

    printf("\nInserire una data in formato dd-mm-yyyy: ");
    scanf("%s", str);

    while (!MUL_DATE_checkstring(str)) {
		printf("\nFormato errato, reinserire una data in formato dd-mm-yyyy: ");
        scanf("%s", str);
	}
    d = MUL_DATE_atoDATE(str);
	d2 = MUL_DATE_atoDATE("01/01/1980");

    printf("\nla data inserita e': %s", MUL_DATE_toa(d));
    printf("\nil separatore utilizzato e' il carattere: %c", MUL_DATE_separator(d));
    printf("\ngiorni dall'inizio dell'anno    : %d", MUL_DATE_dayofyear(d) );
    printf("\ngiorni fino alla fine dell'anno : %d", MUL_DATE_daysofcarry(d) );
    printf("\nl'anno %d %s e' bisestile", MUL_DATE_year(d), MUL_DATE_leap(d)? "":"non");
    printf("\nil mese %d e' composto di %d giorni", MUL_DATE_month(d), MUL_DATE_daysofmonth(MUL_DATE_month(d)));

	printf("\nla data %s e' %s della data %s", MUL_DATE_toa(d), comp[MUL_DATE_compare(d, d2)+1], MUL_DATE_toa(d2));
	printf("\nla differenza tra %s e %s e': %d giorni", MUL_DATE_toa(d), MUL_DATE_toa(d2), MUL_DATE_diff(d,d2));
    printf("\naggiungendo %d giorni a %s di ottiene %s", gg, MUL_DATE_toa(d), MUL_DATE_toa(MUL_DATE_adddays(d, gg)));
	printf("\n");

    return 0;
}
