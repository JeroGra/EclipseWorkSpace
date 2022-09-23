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
#include <string.h>
typedef struct{
	int legajo;
	char nombre[20];
	int edad;
}eAlumno;

int getInt(int* entero, char* mensaje,int min, int max);
void OrdenarEnteros(int* entero,int tam);
int CargarEstudiante(eAlumno* alumno);
int main(void)
{
 setbuf(stdout, NULL);
 int miEntero;
 int Enteros[5];
 eAlumno listaAlumnos[3];
 eAlumno* punteroAlumnos;
 int* miEnteroPuntero;
 miEnteroPuntero = &miEntero;
 punteroAlumnos = listaAlumnos;

 for(int i = 0;i<5;i++)
 {
   getInt(miEnteroPuntero,"Coloque un entero: \n",0,10);
   Enteros[i]=miEntero;//o *miEnteroPuntero
 }

 miEnteroPuntero = Enteros;
 OrdenarEnteros(miEnteroPuntero,5);

 printf("Mis enteros Ordenados\n");
 for(int i = 0; i<5;i++)
 {
  printf("%-2d\t",*(miEnteroPuntero+i));
 }

 for(int i = 0;i<3;i++)
 {
	 CargarEstudiante((punteroAlumnos+i));
 }

 printf("\n|Legajo  \t|Nombre        \t|edad\n");
 for(int i = 0;i<3;i++)
 {
    printf("\n|%-5d\t|%-20s\t|%-5d",listaAlumnos[i].legajo,listaAlumnos[i].nombre,listaAlumnos[i].edad);
 }
 return EXIT_SUCCESS;
}

void OrdenarEnteros(int* entero,int tam)
{
	int aux;
	for(int i = 0;i<tam-1;i++)
	{
		for(int j = i+1;j<tam;j++)
		{
			if(*(entero+i) > *(entero+j))
			{
				aux = *(entero+i);
				*(entero+i) = *(entero+j);
				*(entero+j) = aux;
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

int CargarEstudiante(eAlumno* alumno)
{
	int respuesta = -1;
	if(alumno != NULL)
	{
	 respuesta = 0;
	 getInt(&(alumno)->legajo,"\nColoque el N° de legajo: \n",-1,100);
	 printf("Coloque el nombre: \n");
	 fflush(stdin);
	 gets((alumno)->nombre);
	 getInt(&(alumno)->edad,"Coloque la edad",11,19);
	}
	return respuesta;
}

