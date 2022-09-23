/*
 ============================================================================
 Name        : 3-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int TomaDeNumero(void);
int main(void) {
	setbuf(stdout, NULL);
    int resultado;
	resultado = TomaDeNumero();
	printf("El numero es %d", resultado);


	return EXIT_SUCCESS;
}

int TomaDeNumero(void){
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
