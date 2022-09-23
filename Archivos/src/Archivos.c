/*
 ============================================================================
 Name        : Archivos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
	int id;
	char nombre[20];
	char apellido[20];
	char email[50];

}eParticipantes;

int main(void) {
	setbuf(stdout, NULL);
	FILE* pArchivo;
	eParticipantes listaParticipantes[100];
	eParticipantes lectura;
	char id[20];
	char nombre[20];
	char apellido[20];
	char email[50];
	int i = 0;

	pArchivo = fopen("listaParticipantes.csv","r");
	while(!feof(pArchivo))
	{
		fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, apellido, email);
		lectura.id = atoi(id);
		strcpy(lectura.nombre,nombre);
		strcpy(lectura.apellido,apellido);
		strcpy(lectura.email,email);

		listaParticipantes[i] = lectura;
		i++;
	}
	fclose(pArchivo);
	printf("|ID\t |NOMBRE\t         |APELLIDO\t         |EMAIL\n"
		   "|--------|-----------------------|-----------------------|-----------------------------------|\n");
	for(int i = 0;i<100;i++)
	{
		printf("|%-5d\t |%-20s\t |%-20s\t |%-20s\n",listaParticipantes[i].id, listaParticipantes[i].nombre, listaParticipantes[i].apellido, listaParticipantes[i].email);
	}
	//char nombre[30]={"Jeronimo"};
	//char apellido[30]={"Granadillo"};
	//char lectura[60];
	//char cadena[30];
	/*pArchivo = fopen("Jero_Crack.txt","w");
	if(pArchivo != NULL)
	{
		fprintf(pArchivo,"Jero es un cruck");
		fclose(pArchivo);
	}
	else
	{
		printf("No se econtro el directorio del archivo");
	}*/

	/*pArchivo = fopen("Jero_Crack.txt","r");

	fgets(cadena,30,pArchivo);
	fclose(pArchivo);
	puts(cadena);*/

	/*pArchivo = fopen("Jero_Crack.txt","w");
	if(pArchivo != NULL)
	{
		fprintf(pArchivo,"%s\n%s",nombre,apellido);
		fclose(pArchivo);
	}
	else
	{
		printf("No se econtro el directorio del archivo");
	}

	pArchivo = fopen("Jero_Crack.txt","r");
	while(!feof(pArchivo))//No sea el final del archivo
	{
		fgets(lectura,60,pArchivo);
		puts(lectura);

	}
	fclose(pArchivo);*/



	return EXIT_SUCCESS;
}
