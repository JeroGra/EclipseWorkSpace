/*
 ============================================================================
 Name        : RecuP1.c
 Author      : Jeronimo Granadillo
 Copyright   : Your copyright notice
 Description : Recuperatorio Programacion 1
 ============================================================================
 1. Realizar una función que reciba como parámetro un número entero.
 La misma deberá retornar la cantidad de divisores del numero que hay entre la unidad (incluida) y el mismo numero (incluido).

 3. Crear una función que reciba como parámetro una cadena. Dicha función  deberá ordenar alfabéticamente la cadena y LUEGO reemplazará las vocales por un asterisco.
 La función retornará si la cantidad de reemplazos que se llevaron a cabo fueron par o impar.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DivisorDeInt(int numero);
int Ordenar(char cadena[],char comodin);
int Reemplazar(char cadena[],char comodin, int size);

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int retorno;
	char cadena[15];
	char comodin = '*';
	strcpy(cadena,"Hola Mundo");


	printf("Coloque un numero: \n");
	scanf("%d",&numero);
	retorno = DivisorDeInt(numero);
	printf("El numero %d, tine %d divisores\n", numero, retorno);

	retorno = Ordenar(cadena,comodin);
	if(retorno == 1)
	{
		printf("La cantidad de reemplazos de vocales es par\n");
	}
	else
	{
		printf("La cantidad de reemplazos de vocales es inpar\n");
	}


	return EXIT_SUCCESS;
}

int DivisorDeInt(int numero)
{
	int divisores = 0;
	for(int i = 1;i<=numero;i++)
	{
		if(numero%i==0)
		{
			divisores++;
		}
	}
	return divisores;
}

int Ordenar(char cadena[],char comodin)
{
	int reemplazos;
	int size;
	char auxCadena;

	size = strlen(cadena);
	strlwr(cadena);

	for(int i = 0;i<size-1;i++)
	{
		for(int j = i+1;j<size;j++)
		{
			if(cadena[i] > cadena[j])
			{
				auxCadena = cadena[i];
				cadena[i] = cadena[j];
				cadena[j] = auxCadena;
			}
		}
	}
	reemplazos = Reemplazar(cadena,comodin,size);
	return reemplazos;
}
int Reemplazar(char cadena[],char comodin, int size)
{
	int reemplazos=0;
	int cont=0;
	for(int i = 0;i<size;i++)
	{
		switch(cadena[i])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		cadena[i]=comodin;
		cont++;
		break;
		}
	}
	if(cont%2==0)
	{
		reemplazos = 1;
	}
	return reemplazos;
}
void ReemplazarEspacios(char cadena[],char comodin, int size)
{
	for(int i = 0;i<size;i++)
	{
	  if(cadena[i]==32)
	  {
		  cadena[i] = comodin;
	  }
	}

}
