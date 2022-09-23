#include "Biblioteca.h"
int PedirEntero(char mensaje[], int minimo, int maximo)
{
	int unNumero;
	printf("%s", mensaje);
	scanf("%d", &unNumero);
	while(unNumero<minimo || unNumero>maximo)
	{
		printf("Reingrese!!!: ");
		scanf("%d", &unNumero);
	}


	return unNumero;
}



