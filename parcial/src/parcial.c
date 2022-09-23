/*
 ============================================================================
 Name        : parcial.c
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
int ImporteFinal(char cliente[], int importe);
void RecibeCadena(char cadena[]);
int main()
{
    int precioBruto = 1500;
    int precioFinalP;
    int precioFinalV;
    int precioFinalN;
    char vip[10] = "vip";
    char premium[10] = "premium";
    char normal[10] = "normal";
    char cadena[40] = "aer DHZZZ aer ";

    RecibeCadena(cadena);

    precioFinalP= ImporteFinal(premium,precioBruto);
    precioFinalV= ImporteFinal(vip,precioBruto);
    precioFinalN= ImporteFinal(normal,precioBruto);

    printf("Su precio final de premium es de:  %d\n",precioFinalP);
    printf("Su precio final de vip es de:  %d\n",precioFinalV);
    printf("Su precio final sin ser vip o premium es de:  %d\n",precioFinalN);

    return 0;
}

int ImporteFinal(char cliente[],int importe)
{
    int descuento;
    int resultado;
    char clienteC[10];
    strcpy(clienteC,cliente);

    if(strcmp(clienteC,"vip")==0)
    {
        descuento = 30;
    }
    else
    {
        if(strcmp(clienteC,"premium")==0)
        {
            descuento = 20;
        }
        else
        {
            descuento = 10;
        }
    }

     resultado = (importe*descuento)/100;
     importe = importe-resultado;
     return importe;
}

void RecibeCadena(char cadena[])
{
    char auxiliar;
    int z;
    int espacios;
    int len;
    len = strlen(cadena);
    strlwr(cadena);
    for(int i = 0;i<len-1;i++)
    {
        for(int j = i+1;j<len;j++)
        {
            if(cadena[i] > cadena[j])
            {
              auxiliar = cadena[i];
              cadena[i] = cadena[j];
              cadena[j] = auxiliar;
            }
        }
    }

    for(z = 0;z<len;z++)
    {
        espacios = isspace(cadena[z]);
        if(espacios == 0)
        {

        }
        else
        {
           cadena[z] = '*';
        }
    }

    printf("La cadena es: %s\n",cadena);
}
