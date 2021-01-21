/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 * @(#)muldate.c  1.0  1999/05/02
 *   ________        _________________.________
 *  /  _____/  ____ /   _____/   __   \   ____/
 * /   \  ___ /  _ \\_____  \\____    /____  \
 * \    \_\  (  <_> )        \  /    //       \
 *  \______  /\____/_______  / /____//______  /
 *         \/              \/               \/
 *
 * Autore....: Alessandro Fraschetti
 * Libreria..: GoS'95 Micro Utility Library - Modulo DATE
 * Note......:
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mul.h"


mul_date MUL_DATE_DUMMY={0,0,0,'/',0};


/*
 * Controlla se la stringa è una data valida.
 */
int MUL_DATE_checkstring(char *str)
{
    short d, m, y=0, c=10000;
    char *s = str;

    if( strlen(s) != MUL_DATE_STRLEN )
        return FALSE;
    d = (*s - '0')*10 + (*++s - '0');
    ++s;
    m = (*++s - '0')*10 + (*++s - '0');
    ++s;
    while( *++s ) {
        if( !isdigit(*s) ) 
            return FALSE;
        y += (*s -'0')*(c /= 10);
    }
    if( ( d<1 )  ||  ( d>(MUL_DATE_daysofmonth(m)+MUL_DATE_leapyear(y)) )  ||  ( m<1 )  ||  ( m>12 ) )
        return FALSE;
    return TRUE;
}


/*
 * Converte la stringa in una data MUL_DATE.
 * !! il ptr_data di ritorno è allocato dalla funz. !!
 */
MUL_DATE MUL_DATE_atoDATE(char *str)
{
   char *s = str;
   MUL_DATE d = (MUL_DATE)malloc( sizeof(MUL_DATE) );

   if( strlen(s) != MUL_DATE_STRLEN )
      return &MUL_DATE_DUMMY;
   MUL_DATE_day(d) = (*s - '0')*10 + (*++s - '0');
   MUL_DATE_separator(d) = strchr( MUL_DATE_SEPARATORS,( MUL_DATE_separator(d) = *++s ) ) ? MUL_DATE_separator(d) : '/' ;
   MUL_DATE_month(d) = (*++s - '0')*10 + (*++s - '0');
   ++s;
   MUL_DATE_year(d) = (*++s - '0')*1000+(*++s -'0')*100+(*++s -'0')*10+(*++s - '0'); 
   MUL_DATE_leap(d) = MUL_DATE_leapyear(MUL_DATE_year(d));
   if( MUL_DATE_day(d)<1  ||  MUL_DATE_day(d) > ( MUL_DATE_daysofmonth( MUL_DATE_month(d) ) + MUL_DATE_leap(d) )    
                                          || MUL_DATE_month(d)<1 || MUL_DATE_month(d)>12 )
      return &MUL_DATE_DUMMY;
   return d;
}


/*
 * Converte la data MUL_DATE in stringa.
 * !! il ptr_data di ritorno è allocato dalla funz. !!
 */
char *MUL_DATE_toa(MUL_DATE d)
{
   short y1, y2;
   char *str, *s = (char*)malloc( sizeof(char)*(MUL_DATE_STRLEN+1) );
   
   str = s;
   *s   = MUL_DATE_day(d) / 10 + '0';
   *++s = MUL_DATE_day(d) % 10 + '0'; 
   *++s = MUL_DATE_separator(d);
   *++s = MUL_DATE_month(d) / 10 + '0';
   *++s = MUL_DATE_month(d) % 10 + '0';
   *++s = MUL_DATE_separator(d);
   *++s = y1 = MUL_DATE_year(d) /1000 + '0'; 
   *++s = y1 = ( y2 = (MUL_DATE_year(d) - (y1-'0')*1000) )/100 + '0'; 
   *++s = y1 = ( y2 = ( y2 - (y1-'0')*100 ) )/10 + '0'; 
   *++s = y2 % 10 + '0';
   *++s = '\0';
   return str;
}


/*
 * Ritorna i giorni dall'inizio dell'anno.
 */
int MUL_DATE_dayofyear(MUL_DATE d)
{
   int i, gg=0;

   for(i=1; i<MUL_DATE_month(d); i++)
      gg += MUL_DATE_daysofmonth(i);
   gg += MUL_DATE_day(d);
   if( MUL_DATE_leap(d) && MUL_DATE_month(d)>2 ) 
      gg += 1; 
   return gg;
}


/*
 * Ritorna i giorni che mancano alla fine dell'anno.
 */
int MUL_DATE_daysofcarry(MUL_DATE d)
{
   int i, gg=0;

   for(i=MUL_DATE_month(d)+1; i<=12; i++)
      gg += MUL_DATE_daysofmonth(i);
   gg += MUL_DATE_daysofmonth( MUL_DATE_month(d) ) - MUL_DATE_day(d);
   if( MUL_DATE_leap(d) && MUL_DATE_month(d)<=2 )
      gg += 1;
   return gg;
}


/*
 * Esegue la differenza in giorni tra due date MUL_DATE.
 */
int MUL_DATE_diff(MUL_DATE d1, MUL_DATE d2)
{
    int i, gg;

    gg = MUL_DATE_dayofyear(d1) + MUL_DATE_daysofcarry(d2);
        for ( i=(MUL_DATE_year(d2)+1); i<MUL_DATE_year(d1); i++ )
            gg += 365 + MUL_DATE_leapyear(i);
    return gg; 
}


/*
 * confronta due date: 1 0 -1  d1 > = < d2.
 */
int MUL_DATE_compare(MUL_DATE d1, MUL_DATE d2)
{
   if( MUL_DATE_year(d1) == MUL_DATE_year(d2) ) 
      if( MUL_DATE_year(d1) == MUL_DATE_year(d2) )
         return (MUL_DATE_day(d1)==MUL_DATE_day(d2)) ? 0:(MUL_DATE_day(d1)>MUL_DATE_day(d2) ? 1:-1);
      else 
         return (MUL_DATE_month(d1)>MUL_DATE_month(d2)) ? 1:-1;
   else
      return (MUL_DATE_year(d1)>MUL_DATE_year(d2)) ? 1:-1;
}


/*
 * somma giorni alla data MUL_DATE
 * !! il ptr_data di destinazione è allocato dalla funz. !!
 */
MUL_DATE MUL_DATE_adddays(MUL_DATE d, int gg)
{
    int g_res;
/*   MUL_DATE d2 = (MUL_DATE)malloc( sizeof(MUL_DATE) ); */
  
/*   *d2 = *d; */

    MUL_DATE d2 = MUL_DATE_atoDATE(MUL_DATE_toa(d));

    while( gg )
        if(  gg > ( g_res = MUL_DATE_daysofmonth(MUL_DATE_month(d2)) + (MUL_DATE_leap(d2)? (MUL_DATE_month(d2)==2? 1:0) :0) - MUL_DATE_day(d2) )  ) {
            if( MUL_DATE_month(d2) == 12 ) {
                MUL_DATE_year(d2) += 1;
                MUL_DATE_month(d2) = 1;
            } else
                MUL_DATE_month(d2) += 1;
            MUL_DATE_day(d2) = 1;
            gg -= g_res;
        } else {
			MUL_DATE_day(d2) = MUL_DATE_day(d2) + (MUL_DATE_day(d2)==1? gg-1 : gg);
			break;
		}
    return d2;
}
