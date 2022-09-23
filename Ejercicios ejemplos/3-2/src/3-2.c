/*
 ============================================================================
 Name        : 3-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int ValidacionPar(int numeroIngresado);
int main(void)
{
	setbuf(stdout, NULL);
	int numeroIngresado;
	int mensaje;
	printf("Ingrese un numero: ");
	scanf("%d", &numeroIngresado);

	mensaje = ValidacionPar(numeroIngresado);
	printf("%d", mensaje);

	return EXIT_SUCCESS;
}

int ValidacionPar(int numeroIngresado)
{
	int procedimiento;
	int mensaje;
	procedimiento = numeroIngresado%2;

	if(procedimiento == 0)
	{
		mensaje = 1;
	}
	else
	{
		mensaje = 0;
	}

	return mensaje;
}
