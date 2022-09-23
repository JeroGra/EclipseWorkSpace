/*
 ============================================================================
 Name        : Invertir.c
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

int main(void) {
	setbuf(stdout, NULL);
    char nombre[20]; //= {"Pe tes"};
    char nombreIngresado[20];
    char nombreInvertido[20];
    char nombreComodin[20];
	char comodin; //= 'o';
	int longitud;
	int aux;
	int len;
	int i;
	int j;
	//int espacio;
	//int posicion = 0;
	printf("coloque un nombre: \n");
	fflush(stdin);
	gets(nombre);
	longitud = strlen(nombre);
	while(longitud < 1 || longitud > 20 )
	{
		printf("Error coloque un nombre: \n");
		fflush(stdin);
		gets(nombre);
	}

	printf("Coloque un comodin de un caracter: \n");
	fflush(stdin);
	scanf("%c",&comodin);



	strcpy(nombreIngresado,nombre);
	strlwr(nombreIngresado);
	len = strlen(nombreIngresado);

	  for(j = 0;j<len;j++)
	    {
		  //espacio = isspace(nombreIngresado[j]);
		  if(nombreIngresado[j] == 32)
			{
				//posicion = posicion + 1;
				nombreIngresado[j+1] = toupper(nombreIngresado[j+1]);
			}
			/*else
			{
				posicion = posicion + 1;
				nombreIngresado[posicion] = toupper(nombreIngresado[posicion]);
			}*/
	    }
	  nombreIngresado[0] =  toupper(nombreIngresado[0]);
	  strcpy(nombreComodin,nombreIngresado);
	  strcpy(nombreInvertido,nombreIngresado);

    for(i = 0;i<len;i++)
    {
    	switch(nombreComodin[i])
    	{
    	case 'a':
    	case 'e':
    	case 'i':
    	case 'o':
    	case 'u':
    	case 'A':
    	case 'E':
    	case 'I':
    	case 'O':
    	case 'U':
    		nombreComodin[i] = comodin;
    	break;
    	}
    }

   for(int i=0;i<len-1;i++)
   {
      for(int j = i+1;j<len;j++)
	   {
		   aux = nombreInvertido[i];
		   nombreInvertido[i] =nombreInvertido[j];
		   nombreInvertido[j] = aux;
	   }
   }

	printf("Nombre con comodin %s\n",nombreComodin);
	printf("Nombre invertido %s\n",nombreInvertido);
	printf("Nombre ingresado %s\n",nombreIngresado);


	return EXIT_SUCCESS;
}
