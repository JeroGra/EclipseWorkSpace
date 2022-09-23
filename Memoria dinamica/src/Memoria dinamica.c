/*
 ============================================================================
 Name        : Memoria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
int getInt(int* entero, char* mensaje,int min, int max);
int ElegirNumeroYEliminarSusIguales(int* arrayEnteros, int size);
void CargarNumeroEnUnIndice(int* arrayEnteros,int size,int numero,int indice);
int main(void) {
	setbuf(stdout,NULL);
	int* arrayEnteros;
	arrayEnteros = (int*) malloc(sizeof(int)*TAM);
	int large;
	int nuevoNumero;
	int IndiceElegido;

	if(arrayEnteros != NULL)
	{
		printf("CARGAR 5 NUMEROS\n");
		for(int i = 0;i<TAM;i++)
		{
			getInt(arrayEnteros+i,"Coloque un numero: \n",1,100);
		}

		printf("SUS NUMEROS: \n");
		for(int i = 0;i<TAM;i++)
		{
			printf("%d\t",*(arrayEnteros+i));
		}
	}

	large = ElegirNumeroYEliminarSusIguales(arrayEnteros,TAM);

	getInt(&nuevoNumero,"\n\nColoque un numero nuevo para agregar: \n",1,100);
	printf("Usted eligio:\n"
		   "%d\n",nuevoNumero);
	getInt(&IndiceElegido,"Eliga el indice donde decea colocar el nuevo numero: \n",0,large-1);
	printf("Usted eligio el indice:\n"
		   "%d\n",IndiceElegido);
	CargarNumeroEnUnIndice(arrayEnteros,large,nuevoNumero,IndiceElegido);

	return EXIT_SUCCESS;
}
int ElegirNumeroYEliminarSusIguales(int* arrayEnteros, int size)
{
	int numero;
	int* arrayAux;
	int auxBurbujeo;
	int contador = 0;
	int newSize;
	if(arrayEnteros != NULL)
	{
		getInt(&numero,"\nColoque un numero para eliminar sus iguales: \n",1,100);
		printf("SU NUMERO A ELIMINAR ES:\n"
		 	   "%d\n",numero);
        for(int i = 0;i<size;i++)
        {
        	if(*(arrayEnteros+i) == numero)
        	{
        		*(arrayEnteros+i) = 0;
        		contador++;
        	}
        }

        for(int i = 0;i<size-1;i++)
        {
        	for(int j = i+1;j<size;j++)
        	{
        		if(*(arrayEnteros+i) < *(arrayEnteros+j))
        		{
        			auxBurbujeo = *(arrayEnteros+i);
        			*(arrayEnteros+i) = *(arrayEnteros+j);
        			*(arrayEnteros+j) = auxBurbujeo;
        		}
        	}
        }

        arrayAux = (int*)realloc(arrayEnteros,sizeof(int)*(size-contador));
        if(arrayAux != NULL)
        {
        	newSize = size-contador;
        	 for(int i = 0;i<newSize-1;i++)
				{
					for(int j = i+1;j<newSize;j++)
					{
						if(*(arrayEnteros+i) > *(arrayEnteros+j))
						{
							auxBurbujeo = *(arrayEnteros+i);
							*(arrayEnteros+i) = *(arrayEnteros+j);
							*(arrayEnteros+j) = auxBurbujeo;
						}
					}
				}
        	arrayEnteros = arrayAux;
        	printf("RESULTADOS DE LA OPERACION\n"
        		   "Sus numeros ahora son: \n");
        	for(int i = 0;i<newSize;i++)
        	{
        		printf("%d\t",*(arrayEnteros+i));
        	}
        }
	}

	return newSize;
}

void CargarNumeroEnUnIndice(int* arrayEnteros,int size,int numero,int indice)
{
	int* arrayAux;
	int auxBurbujeo;
	if(arrayEnteros != NULL)
	{
        arrayAux = (int*)realloc(arrayEnteros,sizeof(int)*(size+1));
        if(arrayAux != NULL)
        {
        	arrayEnteros = arrayAux;
        	*(arrayEnteros+size) = 0;
        	for(int i = indice;i<size;i++)
        	{
        		for(int j = i+1;j<size+1;j++)
        		{
        			if(*(arrayEnteros+i)>*(arrayEnteros+j))
        			{
        				auxBurbujeo = *(arrayEnteros+i);
        				*(arrayEnteros+i) = *(arrayEnteros+j);
        				*(arrayEnteros+j)= auxBurbujeo;
        			}
        		}
        	}
        	*(arrayEnteros+indice) = numero;
        	printf("RESULTADOS DE LA OPERACION\n"
				   "Sus numeros ahora son: \n");
			for(int i = 0;i<size+1;i++)
			{
				printf("%d\t",*(arrayEnteros+i));
			}
        }
	}
}

int getInt(int* entero, char* mensaje,int min, int max)
{
	int respuesta = 0;
	if(entero != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%d",entero);
		while(entero == NULL || *entero < min || *entero > max)
		{
			printf("Error!, coloque un entero: \n");
			fflush(stdin);
			scanf("%d",entero);
		}
	}
	return respuesta;
}
