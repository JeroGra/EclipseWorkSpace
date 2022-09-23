/*
 ============================================================================
 Name        : MyInputFunctions.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "input.h"
int main(void) {
	int min;
	int max;
	int myNum;
	char firstName[30];
	char lastName[30];
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	min = getInt("Coloque rango del numero menor a elegir",-1000000000,1000000000);
	max = getInt("Coloque numero rango de mayor a elegir",min,1000000000);

	myNum = getInt("Coloque un numero valido segun el rango elegido",min,max);
    getString(firstName,"Coloque un nombre",30);
    TrasnsformarNombres(firstName);
    getString(lastName,"Coloque un nombre",30);
    TrasnsformarNombres(lastName);


	return EXIT_SUCCESS;
}
