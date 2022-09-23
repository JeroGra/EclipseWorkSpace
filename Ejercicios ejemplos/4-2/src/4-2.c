/*
 ============================================================================
 Name        : 4-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaValidacion.h"
#include "BibliotecaPasages.h"
int main(void) {
	setbuf(stdout, NULL);
	int gradosFahrenheitIngresados;
	int gradosCelsiusIngresados;
	int pasageAC;
	int pasageAF;

	gradosFahrenheitIngresados = ValidacionF("Ingrese los grados °F: ", 32, 212);
	gradosCelsiusIngresados = ValidacionC("Ingrese los grados °C: ", 0, 100);
	pasageAC =  PasageACelcius(gradosFahrenheitIngresados);
	pasageAF =  PasageAFahrenheit(gradosCelsiusIngresados);

	printf("Los %d°F ingresados, en Celcius son %d°C\n", gradosFahrenheitIngresados,pasageAC);
	printf("Los %d°C ingresados, en Fahrenheit son %d°F",gradosCelsiusIngresados ,pasageAF);
	return EXIT_SUCCESS;
}
