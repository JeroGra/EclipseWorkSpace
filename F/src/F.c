/*
 ============================================================================
 Name        : F.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int Sumar(int uno, int dos);
int main(void)
{
int uno;
int dos;
int resultado;

uno = 10;
dos = 20;

resultado = Sumar(uno, dos);
printf("El resultado es %d",resultado);

return EXIT_SUCCESS;
}

int Sumar (int uno, int dos)
{
	int resultado;
	resultado = uno + dos;
	return resultado;
}
