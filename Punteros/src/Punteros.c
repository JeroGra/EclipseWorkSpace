/*
 ============================================================================
 Name        : Punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void miFuncion(int array[], char mensaje[], int* numero);
int main(void) {
	setbuf(stdout, NULL);

    int arrayNumero[5] = {5,4,8,3,7};
	char cadena[10] = {"puntero"};
	int unEntero=50;

	//int* punteroNumero = NULL; //variable tipo puntero
  //  punteroNumero = &unEntero;

	//*punteroNumero = 6;


	miFuncion(arrayNumero, cadena, &unEntero);

	printf("\nmuestro cadena : %s ", cadena);
	printf("\nmuestro numero : %d ", unEntero);
	printf("\n\nmuestro array: ");


	for(int i=0; i<5; i++)
	{
		printf("%d  ", arrayNumero[i]);
	}

	printf("modificar valor de un numero: ");
	scanf("%d", &unEntero);

	printf("\ndireccion de un entero: %p", &unEntero);
	//printf("\n%d", unEntero);

	return EXIT_SUCCESS;
}

void miFuncion(int array[], char mensaje[], int* numero)
{
    int auxNumero;
    auxNumero = *numero;

    for(int i=0; i < 5; i++)
    {
        array[i] = array[i] * 2;
    }

    auxNumero = auxNumero * 2;
    *numero = auxNumero;

    strcpy(mensaje, "otra cosa");
}

