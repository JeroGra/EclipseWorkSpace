/*
 ============================================================================
 Name        : 4-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"


int main(void)
{
	setbuf(stdout, NULL);
	int numeroIngresado;
	int factorial;


	numeroIngresado = TomaDeNumero();
	factorial = CalcularFactorial(numeroIngresado);


	printf("El factorial del numero %d, es: %d", numeroIngresado, factorial);



	return EXIT_SUCCESS;
}


