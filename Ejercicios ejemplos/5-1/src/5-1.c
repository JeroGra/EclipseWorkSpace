/*
 ============================================================================
 Name        : 5-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void CargarVector(int numeros[], int size);
int Suma(char[]);
int Promedio(int, int);
int main(void) {
	setbuf(stdout, NULL);
    int promedio;
    int suma;

    suma = Suma("Coloque un numero: ");
    promedio = Promedio(suma,TAM);

    printf("La suma de los numero es %d, el promedio total es %d", suma,promedio);
	return EXIT_SUCCESS;
}
int Suma(char mensaje[])
{
	 int suma;
	 int numero[TAM];
	 for(int i = 0;i<5;i++)
	     {
	     	printf("%s", mensaje);
	     	fflush(stdin);
	     	scanf("%d",&numero[i]);
	     	suma = suma+numero[i];

	     }
	 CargarVector(numero, TAM);
	 return suma;
}

int Promedio(int suma, int divisor)
{
	int promedio;
	promedio = suma/divisor;
    return promedio;
}
void CargarVector(int numeros[], int size)
{
	for(int i = 0;i<size;i++)
	{
		printf("su %d° numero es %d\n",i + 1, numeros[i]);
	}
}


