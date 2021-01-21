/*-----------------------------------------------------------------------------
* File            : test.c
* Autore          : Alessandro Fraschetti
* Funzione        : Test delle funzioni del modulo PGM TEXT
* Parametri in    :
* Parametri out   :
* Note            :
*-----------------------------------------------------------------------------*/


#include <stdlib.h>
#include <stdio.h>
#include "mul.h" 


int main(void) {
	char str[80] = "GoS'95 MUL - Micro Utility Library";
	char str2[80] = "GoS'95 MUL - Micro Utility Library";
	char str3[80] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,;-'";
	char str4[80] = "___Micro___Utility___Library___";
	char str5[80] = "___Micro___Utility___Library___";

    MUL_SYSTEM_cls();
	printf("Demo-test delle procedure del modulo TEXT\ndella libreria GoS'95 MUL - Micro Utility Library\n\n");

    printf("shiftN(\"%s\", 18) = ", str);
    printf("\n %s", MUL_TEXT_shiftN(str, 18));

    printf("\n\nshiftN(\"%s\", -18) = ", str);
    printf("\n %s", MUL_TEXT_shiftN(str, -18));


    printf("\n\n\nrot13(\"%s\") = ", str2);
    printf("\n %s", MUL_TEXT_rot13(str2));

    printf("\nrot13(\"%s\") = ", str2);
    printf("\n %s", MUL_TEXT_rot13(str2));


    printf("\n\nrot13(\"%s\") = ", str3);
    printf("\n %s", MUL_TEXT_rot13(str3));

    printf("\nrot13(\"%s\") = ", str3);
    printf("\n %s\n", MUL_TEXT_rot13(str3));

    printf("\n\nleftTrim(%s) = ", str4);
	printf("#%s#\n", MUL_TEXT_leftTrim(str4, '_'));

    printf("\n\nleftTrim(%s) = ", str4);
	printf("#%s#\n", MUL_TEXT_leftTrim(str4, '_'));

    printf("\n\nrightTrim(%s) = ", str4);
	printf("#%s#\n", MUL_TEXT_rightTrim(str4, '_'));

    printf("\n\nrightTrim(%s) = ", str4);
	printf("#%s#\n", MUL_TEXT_rightTrim(str4, '_'));

    printf("\n\nTrim(%s) = ", str5);
	printf("#%s#\n", MUL_TEXT_trim(str5, '_'));

    printf("\n\nTrim(%s) = ", str5);
	printf("#%s#\n", MUL_TEXT_trim(str5, '_'));

    printf("\n\ninTrim(%s) = ", str5);
	printf("#%s#\n", MUL_TEXT_inTrim(str5, '_'));

    printf("\n\ninTrim(%s) = ", str5);
	printf("#%s#\n", MUL_TEXT_inTrim(str5, '_'));

	return 0;
}
