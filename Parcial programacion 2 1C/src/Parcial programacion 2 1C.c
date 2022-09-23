/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#define TAM 20

int dejarPares(int* parray, int* tam);
int main(void)
{
	setbuf(stdout, NULL);
    int arrayEnteros[TAM]={1,2,3,4,5,6,7,8,9,10,12,11,13,14,15,16,17,18,19,20};
    int* pArray;
    int size = TAM;
    pArray=(int*)malloc(sizeof(int)*TAM);
    if(pArray!=NULL){
        for(int i=0;i<TAM;i++){
             *(pArray+i)=arrayEnteros[i];
            }
          dejarPares(pArray,&size);

    	   for(int i = 0;i<size;i++)
    	   {
    		   printf("%d-",*(pArray+i));
    	   }

    }
    return 0;
}
int dejarPares(int* parray,int* tam){
    int retorno=-1;
    int num;
    int itero = 0;
    int* pArrayAux = (int*)malloc(sizeof(int)*(*tam));
    int* pAux;
    if(parray!=NULL){
        for(int i =0;i<*tam;i++){
        	num = *(parray+i);
        	if(num % 2 == 0)
        	{
        		*(pArrayAux+itero) = num;
        		itero++;
        	}
        }

        pAux = (int*)realloc(pArrayAux,sizeof(int)*((*tam)-itero));
        *tam = itero;
        if(pAux != NULL)
        {
        	pArrayAux = pAux;
        	   for(int i = 0;i<*tam;i++)
			   {
        		   *(parray+i)=*(pArrayAux+i);
			   }
        	   free(pArrayAux);
        }
    }
    return retorno;
}
