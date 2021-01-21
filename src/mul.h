/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 * @(#)mul.h  1.0  1999/05/02
 *   ________        _________________.________
 *  /  _____/  ____ /   _____/   __   \   ____/
 * /   \  ___ /  _ \\_____  \\____    /____  \
 * \    \_\  (  <_> )        \  /    //       \
 *  \______  /\____/_______  / /____//______  /
 *         \/              \/               \/
 *
 * Autore....: Alessandro Fraschetti
 * Libreria..: FGoS'95 Micro Utility Library
 * Descriz...: header file della libreria
 * Note......:
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#ifndef _MUL_H_
#define _MUL_H_

#ifdef __cplusplus
extern "C" {
#endif 


#ifndef TRUE
#define TRUE   1
#endif

#ifndef FALSE
#define FALSE  0
#endif



/* 
 * tipi predefiniti e prototipi delle funzioni del modulo PGM
 */


/* attributi di programma */
typedef struct mul_pgm_info {
	char *name;
	char *version;
	char *vendor;
	char *description;
	char *usage;
	int  noptions;
	char **options;
} MUL_PGM_INFO;


void  MUL_PGM_initInfo(MUL_PGM_INFO*);
void  MUL_PGM_info(MUL_PGM_INFO);
void  MUL_PGM_usage(MUL_PGM_INFO);
char *MUL_PGM_logo(char *tab, int height);



/* 
 * tipi predefiniti e prototipi delle funzioni del modulo SYSTEM
 */
float MUL_SYSTEM_epsilon(void);
int   MUL_SYSTEM_pause(void);
void  MUL_SYSTEM_cls(void); 



/* 
 * tipi predefiniti e prototipi delle funzioni del modulo DATE
 */


#define MUL_DATE_SEPARATORS  "/-.,"    /* caratteri separatori ammessi */
#define MUL_DATE_STRLEN      10        /* lunghezza della stringa 'data' */

/* struttura campo data */
struct mul_date_struct {
    char  d;
    char  m;
    short y;
    char  sep;
    char  leapyear;
};
typedef struct mul_date_struct mul_date;
typedef mul_date* MUL_DATE;


#define MUL_DATE_daysofmonth( m )  ( 30 + ((m)+(m)/8)%2 - 2*((2/(m))%2) )
#define MUL_DATE_leapyear( y )  ( !( ( ((y)%4)) && ((y)%100) ) || !((y)%400) ) 
#define MUL_DATE_leap( date ) date->leapyear
#define MUL_DATE_day( date ) date->d
#define MUL_DATE_month( date ) date->m
#define MUL_DATE_year( date ) date->y
#define MUL_DATE_separator( date ) date->sep


int       MUL_DATE_checkstring(char*);
MUL_DATE  MUL_DATE_atoDATE(char*);
char     *MUL_DATE_toa(MUL_DATE);
int       MUL_DATE_dayofyear(MUL_DATE);
int       MUL_DATE_daysofcarry(MUL_DATE);
int       MUL_DATE_diff(MUL_DATE, MUL_DATE);
int       MUL_DATE_compare(MUL_DATE, MUL_DATE);
MUL_DATE  MUL_DATE_adddays(MUL_DATE, int);



/* 
 * tipi predefiniti e prototipi delle funzioni del modulo DATE
 */

char *MUL_TEXT_shiftN(char*, int);
char *MUL_TEXT_rot13(char*);
char *MUL_TEXT_leftTrim(char*, char);
char *MUL_TEXT_rightTrim(char*, char);
char *MUL_TEXT_trim(char*, char);
char *MUL_TEXT_inTrim(char*, char);


#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

#endif /* !defined(_MUL_H_) */
