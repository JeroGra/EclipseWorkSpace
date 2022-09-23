/*
 ============================================================================
 Name        : 3-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void Flotante(float flotaneUno);
int main(void)
{
	setbuf(stdout, NULL);
    float flotaneUno;
    flotaneUno = 3.5;

    Flotante(flotaneUno);


    return 0;
}
void Flotante(float flotaneUno)
{
    printf("El flotante es: %f", flotaneUno);
}

