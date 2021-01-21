# Micro Utility Library (Versione 1.1 - 02 maggio 1999)

Libreria di routines di utilità generica per la programmazione in linguaggio C.<br>
La libreria è suddivisa nei seguenti moduli:

	Modulo      Acronimo         Descrizione
	----------  ---------------  --------------------------------------------------
	PROGRAM     MUL_PGM          Funzioni utilità di programma
	SYSTEM      MUL_SYSTEM       Funzioni di sistema e di ambiente
	DATE        MUL_DATE         Funzioni per la manipolazione delle date
	TEXT        MUL_TEXT         Funzioni per la manipolazione di campi di testo
	----------  ---------------  --------------------------------------------------

La distribuzione della libreria consiste dei seguenti files:

	MUL.TXT			documentazione della libreria (questo testo)
	MUL.H			include file della libreria
	LIBMUL.A                Micro Utility Library (mingw compatibile)
	LIMBULDJ.A		Micro Utility Library (djgpp compatibile)
	MAKEFILE		Makefile degli eseguibili di demo della lib
	PROGRAM_DEMO.C		file sorgente della demo del modulo program
	PROGRAM_DEMO.EXE	eseguibile della demo del modulo program
	SYSTEM_DEMO.C		file sorgente della demo del modulo system
	SYSTEM_DEMO.EXE		eseguibile della demo del modulo system
	DATE_DEMO.C		file sorgente della demo del modulo date
	DATE_DEMO.EXE		eseguibile della demo del modulo date
	TEXT_DEMO.C		file sorgente della demo del modulo text
	TEXT_DEMO.EXE		eseguibile della demo del modulo text



## Modulo PROGRAM (MUL_PRG) - Funzioni di utilità di programma

Modulo contenente alcune funzioni di utilità generica di programma.<br>
Per memorizzare le informazioni di programma si utilizza la struttura:

	MUL_PGM_INFO

contenente i campi:

	char *name;           nome del programma
	char *version;        versione del programma
	char *vendor;         proprietario del programma
	char *description;    descrizione dello scopo del programma
	char *usage;          stringa di utilizzo del programma
	int  noptions;        numero di parametri di input
	char **options;       descrizione d'uso dei parametri di input

Una volta riempita, la struttura viene inizializzata dalla funzione:

	void  MUL_PGM_initInfo(MUL_PGM_INFO*);

ed in seguito utilizzata dalle funzioni:

	void  MUL_PGM_info(MUL_PGM_INFO);
	void  MUL_PGM_usage(MUL_PGM_INFO);

Per recuperare i loghi testuali della libreria, si utilizza la funzione:

	char *MUL_PGM_logo(char *tab, int height);

alla quale viene passata la stringa tab contenente la tabulazione dalla
prima colonna, e l'altezza in righe del logo. Valori possibili di altezza
sono 1, 4 e 6 righe.

Esempio di utilizzo:

    +-------------------------------------------------------------+
    |MUL_PGM_INFO info;                                           |
    |MUL_PGM_initInfo(&info);                                     |
    |                                                             |
    |char *options[] = {"p1    parametro uno.",                   |
    |                   "p2    parametro due.",                   |
    |                   "p3    parametro tre.",                   |
    |                   "h     help di utilizzo dei parametri."}; |
    |                                                             |
    |info.description = "descrizione del programma bla bla...";   |
    |info.usage       = "pgm.exe [options]";                      |
    |info.noptions    = 4;                                        |
    |info.options     = options;                                  |
    |                                                             |
    |info.name        = "Pgm  programma bla bla bla";             |
    |info.version     = "1.0";                                    |
    |info.vendor      = MUL_PGM_logo("\t", 6);                    |
    |                                                             |
    |MUL_PGM_usage(info);                                         |
    +-------------------------------------------------------------+




## Modulo SYSTEM (MUL_SYSTEM) - Funzioni di sistema e di ambiente

Modulo contenente alcune funzioni di utilità generica relativa all'ambiente di
esecuzione del programma, tra cui il recupero dell'epsilon di macchina (o unità
di arrotondamento dell'elaboratore).

	float MUL_SYSTEM_epsilon(void);
	int   MUL_SYSTEM_pause(void);
	void  MUL_SYSTEM_cls(void); 




## Modulo DATE (MUL_DATE) - Funzioni per la manipolazione delle date

Modulo contenente alcune funzioni di utilità per la manipolazione delle date.<br>
Per memorizzare le informazioni di una data si utilizza la struttura:

	MUL_DATE

che corrisponde ad un puntatore alla struttura mul_date_struct di campi:

	char  d;		giorno
	char  m;		mese
	short y;		anno
	char  sep;		carattere separatore
	char  leapyear;		1=anno bisestile, altrimenti 0

Per creare un tipo MUL_DATE si hanno a disposizione le funzioni:

	int       MUL_DATE_checkstring(char*);
	MUL_DATE  MUL_DATE_atoDATE(char*);

che consentono di creare il campo data partendo da una stringa.<br>
Per la manipolazione di un campo MUL_DATE sono disponibili le funzioni:

	int	  MUL_DATE_daysofmonth(int)
	char	  MUL_DATE_leapyear(int)
	char	  MUL_DATE_leap(MUL_DATE)
	int 	  MUL_DATE_day(MUL_DATE)
	int	  MUL_DATE_month(MUL_DATE)
	int	  MUL_DATE_year(MUL_DATE)
	char	  MUL_DATE_separator(MUL_DATE)

	char     *MUL_DATE_toa(MUL_DATE);
	int       MUL_DATE_dayofyear(MUL_DATE);
	int       MUL_DATE_daysofcarry(MUL_DATE);
	int       MUL_DATE_diff(MUL_DATE, MUL_DATE);
	int       MUL_DATE_compare(MUL_DATE, MUL_DATE);
	MUL_DATE  MUL_DATE_adddays(MUL_DATE, int);

Da notare che per tutte le procedure del modulo DATE vale la logica per cui se
il campo MUL_DATE è il valore di ritorno della procedura allora la stessa si
occupa al suo interno dell'allocazione di memoria necessaria.




## Modulo TEXT (MUL_TEXT) - Funzioni per la manipolazione di campi di testo

Modulo contenente alcune funzioni di utilità generica relativa alla gestione di
campi di testo e manipolazione di stringhe.

	char *MUL_TEXT_shiftN(char*, int);
	char *MUL_TEXT_rot13(char*);
	char *MUL_TEXT_leftTrim(char*, char);
	char *MUL_TEXT_rightTrim(char*, char);
	char *MUL_TEXT_trim(char*, char);
	char *MUL_TEXT_inTrim(char*, char);




## Elenco e descrizione di tutte le funzioni della libreria

#### MUL_PGM
	#include mul.h
	void MUL_PGM_info(MUL_PGM_INFO info)

	Scrive sul dispositivo di standard output le informazioni contenute
        nella struttura puntata da info e relative alle sole informazioni
	generiche del programma: name, version, vendor.

    -----------------------------------------------------------------------
	#include mul.h
	void MUL_PGM_usage(MUL_PGM_INFO infousage)

	Scrive sul dispositivo di standard output le informazioni contenute
	nella struttura puntata da infousage.

    -----------------------------------------------------------------------
	#include mul.h
	char *MUL_PGM_logo(char *tab, int height)

	Alloca una stringa contenente il logo di libreria GoS'95, formattato
	per la stampa a video, e ritorna il puntatore a tale stringa.
	L'allocazione viene fatta una sola volta, quindi successive chiamate
	alla funzione sovrascrivono ogni precedente valore. Il parametro height
	specifica l'altezza in righe del logo.

	-----------------------------------------------------------------------

#### MUL_SYSTEM
	#include mul.h
	float MUL_SYSTEM_epsilon(void)

	Restituisce l'epsilon di macchina, o unità di arrotondamento
	dell'elaboratore. Rappresenta il più piccolo numero reale che sommato
	ad 1 da come risultato un numero floating maggiore di 1.

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_SYSTEM_pause(void)

	Arresta l'esecuzione del programma finchè non viene premuto un tasto,
	e ritorna il codice di scansione del tasto premuto.

    -----------------------------------------------------------------------
	#include mul.h
	void MUL_SYSTEM_cls(void)

	Esegue il clearscreen dell'intera area video.

    -----------------------------------------------------------------------

#### MUL_DATE
	#include mul.h
	int MUL_DATE_checkstring(char*)

	Controlla se la stringa è una data valida.

    -----------------------------------------------------------------------
	#include mul.h
	MUL_DATE MUL_DATE_atoDATE(char*)

	Converte la stringa in una data MUL_DATE. Se la conversione non è
	possibile (sarebbe sempre opportuno prima di eseguire la conversione
	richiamare la funzione MUL_DATE_checkstring) ritorna una data in cui
	tutti i campi hanno valore 0. La procedura si occupa di allocare la
	memoria necessaria.

    -----------------------------------------------------------------------
	#include mul.h
	char *MUL_DATE_toa(MUL_DATE)

	Converte la data MUL_DATE in una stringa di testo. La procedura si
	occupa di allocare la memoria necessaria.

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_DATE_dayofyear(MUL_DATE)

	Restituisce il numero di giorni passati dall'inizio dell'anno.

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_DATE_daysofcarry(MUL_DATE)

	Restituisce il numero di giorni che mancano alla fine dell'anno.

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_DATE_diff(MUL_DATE, MUL_DATE)

	Restituisce la differenza in giorni tra le due date MUL_DATE.
	Si presuppone che la prima data sia maggiore della seconda (si può
	usare la funzione MUL_DATE_compare() per questo).

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_DATE_compare(MUL_DATE, MUL_DATE)

	Restituisce il confronto tra due date come:
	   1 se  d1 > d2, 0 se  d1 = d2, -1 se  d1 < d2.

    -----------------------------------------------------------------------
	#include mul.h
	MUL_DATE  MUL_DATE_adddays(MUL_DATE, int)

	Restituisce la data ottenuta sommando i giorni specificati.<br>
	La procedura si	occupa di allocare la memoria necessaria.

    -----------------------------------------------------------------------
	#include mul.h
	char MUL_DATE_leapyear(int)

	Macro funzione.
	Restituisce 1 se l'anno specificato è bisestile, altrimenti 0.

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_DATE_daysofmonth(int)

	Macro funzione.
	Restituisce il numero di giorni del mese.

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_DATE_day(MUL_DATE)

	Macro funzione.
	Restituisce il giorno della data MUL_DATE.

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_DATE_month(MUL_DATE)

	Macro funzione.
	Restituisce il mese della data MUL_DATE.

    -----------------------------------------------------------------------
	#include mul.h
	int MUL_DATE_year(MUL_DATE)

	Macro funzione.
	Restituisce l'anno della data MUL_DATE.

    -----------------------------------------------------------------------
	#include mul.h
	char MUL_DATE_leap(MUL_DATE)

	Macro funzione.
	Restituisce 1 se la data MUL_DATE corrisponde ad un anno bisestile,
	altrimenti 0.

    -----------------------------------------------------------------------
	#include mul.h
	char MUL_DATE_separator(MUL_DATE)

	Macro funzione.
	Restituisce il carattere separatore della data MUL_DATE.

    -----------------------------------------------------------------------

#### MUL_TEXT
	#include mul.h
	char *MUL_TEXT_shiftN(char*, int)

	Esegue lo shift circolare di n posizioni dei caratteri della stringa.
	I caratteri validi per lo shift sono tutti i codici ascii da 32 a 126.
	La riapplicazione dell'algoritmo con n negativo restituisce la stringa
	di partenza.

    -----------------------------------------------------------------------
	#include mul.h
	char *MUL_TEXT_rot13(char*)

	Esegue lo shift circolare di 13 posizioni dei caratteri della stringa.
	I caratteri validi per lo shift sono soltanto i codici ascii
        corrispondenti ai caratteri alfabetici, tutti gli altri codici vengono
	lasciati inalterati dall'algoritmo.
	La riapplicazione dell'algoritmo restituisce la stringa di partenza.

    -----------------------------------------------------------------------
	#include mul.h
	char *MUL_TEXT_leftTrim(char*, char)

	Elimina tutte le occorrenze del carattere specificato alla sinistra
	della stringa.

    -----------------------------------------------------------------------
	#include mul.h
	char *MUL_TEXT_rightTrim(char*, char)

	Elimina tutte le occorrenze del carattere specificato alla destra
	della stringa.

    -----------------------------------------------------------------------
	#include mul.h
	char *MUL_TEXT_trim(char*, char)

	Elimina tutte le occorrenze del carattere specificato a destra ed a
	sinistra della stringa.

    -----------------------------------------------------------------------
	#include mul.h
	char *MUL_TEXT_inTrim(char*, char);

	Elimina tutte le occorrenze multiple del carattere specificato
	all'interno della stringa.

    -----------------------------------------------------------------------
