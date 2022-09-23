#include "BibliotecaValidacion.h"

int ValidacionF(char mensaje[],int min ,int max)
{
	int numeroFahrenheit;
	printf("%s", mensaje);
	scanf("%d", &numeroFahrenheit);
	while(numeroFahrenheit < min || numeroFahrenheit > max)
	{
		printf("REINGRESE, respete el rango °F de ebullicion y congelacion del agua: ");
		scanf("%d", &numeroFahrenheit);
	}

	return numeroFahrenheit;
}

int ValidacionC(char mensaje[],int min ,int max)
{
	int numeroCelsius;
    printf("%s", mensaje);
	scanf("%d", &numeroCelsius);
	while(numeroCelsius < min || numeroCelsius > max)
	{
		printf("REINGRESE, respete el rango °C de ebullicion y congelacion del agua: ");
		scanf("%d", &numeroCelsius);
	}

	return numeroCelsius;
}

