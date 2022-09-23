/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int P(int numero1, int numero2);
int main(void) {
	int numeroIg1;
	int numeroIg2;
	int resultado;

	numeroIg1 = 10;
	numeroIg2 = 15;

	resultado = P(numeroIg1, numeroIg2);
	printf("resultado: %d", resultado);

	return EXIT_SUCCESS;
}

int P(int numero1, int numero2)
{
	int resultado;
	resultado  = numero2 - numero1;
	return resultado;
}
