/*
 ============================================================================
 Name        : 6-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {
	setbuf(stdout, NULL);
	char nombre[20];
	char apellido[20];
	char nombreApellido[40];
	int len;
	int i;
	int espacio;
	int posicion = 0;



	printf("Ingrese su nombre: \n");
	fflush(stdin);
	fgets(nombre,20,stdin);
	printf("Ingrese su apellido: \n");
    fflush(stdin);
	fgets(apellido,20,stdin);
	strtok(nombre, "\n");
	strtok(apellido, "\n");

	strcpy(nombreApellido,nombre);
	strcat(nombreApellido,", ");
	strcat(nombreApellido,apellido);

	strlwr(nombreApellido);

	len = strlen(nombreApellido);
	printf("%d\n",len);
	for(i = 0; i < len;i++)
	{
		espacio= isspace(nombreApellido[i]);

		if(espacio == 0)
		{
			posicion = posicion + 1;
		}
		else
		{
			posicion = posicion + 1;
			nombreApellido[posicion] = toupper(nombreApellido[posicion]);
		}
		printf("\nespacio = %d\n", posicion);
	}


	nombreApellido[0] = toupper(nombreApellido[0]);




	printf("%s",nombreApellido);

	return EXIT_SUCCESS;
}
