/*
 ============================================================================
 Name        : Clase.c
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
	int nota;
	int edad;

	nota = PedirEntero("Ingrese la nota: ", 1, 10);
	edad = PedirEntero("Ingrese la edad: ", 18, 99);

	printf("La nota es: %d\n", nota);
	printf("La edad es: %d\n", edad);

	return EXIT_SUCCESS;
}

