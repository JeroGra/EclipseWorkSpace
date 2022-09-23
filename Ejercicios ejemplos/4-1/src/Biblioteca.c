/*
 * Biblioteca.c
 *
 *  Created on: 6 abr. 2022
 *      Author: jerob
 */
#include "Biblioteca.h"
int TomaDeNumero(void)
{
	int unNumero;
	printf("Ingrese un numero del 0 al 10: ");
	scanf("%d", &unNumero);
	while(unNumero < 0 || unNumero > 10)
	{
		printf("Reingrese un numero del 0 al 10: ");
	    scanf("%d", &unNumero);
	}

	return unNumero;
}

int CalcularFactorial(int numeroIngresado)
{
	int factorial;

	if(numeroIngresado == 0)
	{
		factorial = 1;
	}
	else
	{
		factorial = numeroIngresado*CalcularFactorial(numeroIngresado - 1);
	}

	return factorial;
}

