/*
 ============================================================================
 Author      : Granadillo Jeronimo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int FiltrarPar(int* pArrayEnteros, int size, int* reSize);
void AcomodarArray(int* pArrayEnteros, int size, int newSize, int* arrayAux );
int SaveAsBinary(int* pArrayEnteros, int size);
int LoadFromBinary( int size);

int main(void) {
	setbuf(stdout, NULL);
	int enterosHardcode[TAM] = {1,5,6,25,8,69,4,17,182,90};
	int size;

	int* pArrayEnteros = (int*) malloc(sizeof(int)*TAM);

	if(pArrayEnteros != NULL)
	{
		for(int i = 0;i<TAM;i++)
		{
		   *(pArrayEnteros+i)= enterosHardcode[i];
		}

		FiltrarPar(pArrayEnteros,TAM,&size);


		if(!SaveAsBinary(pArrayEnteros,size))
		{
			printf("Se a guardado el archivo\n");
			LoadFromBinary(size);
		}
	}

	return EXIT_SUCCESS;
}

int FiltrarPar(int* pArrayEnteros, int size, int* reSize)
{
	int isOk = -1;
	int newSize = 0;
	int arrayAux[size];
	int j = 0;
	if(pArrayEnteros != NULL && size > 0)
	{
		isOk = 0;
		for(int i = 0; i < size;i++)
		{
			if(*(pArrayEnteros+i) % 2 == 0)
			{
				newSize++;
			    arrayAux[j]= *(pArrayEnteros+i);
				j++;
			}
		}

		AcomodarArray(pArrayEnteros,size,newSize,arrayAux);
		*reSize = newSize;
	}
	return isOk;
}
void AcomodarArray(int* pArrayEnteros, int size, int newSize, int* arrayAux)
{
    int* pAux = NULL;
	for(int i = 0;i<newSize;i++)
	{

		*(pArrayEnteros+i) =  arrayAux[i];
	}

	pAux = (int*)realloc(pArrayEnteros,sizeof(int)*(newSize));
	if(pAux != NULL)
	{
		pArrayEnteros = pAux;
	}
}

int SaveAsBinary(int* pArrayEnteros, int size)
{
	int isOk = -1;
	FILE* pArchivo;
	if(pArrayEnteros != NULL && size > 0)
	{
		pArchivo = fopen("num.bin","wb");
		if(pArchivo != NULL)
		{
			for(int i = 0;i<size+1;i++)
			{
				fwrite(pArrayEnteros,sizeof(pArrayEnteros),i,pArchivo);
				isOk = 0;
			}
		}
		fclose(pArchivo);
	}
	return isOk;
}

int LoadFromBinary(int size)
{
	int isOk = -1;
	int arrayAux[size];
	int j = 0;
	FILE* pArchivo;
	if(size > 0)
	{
		pArchivo = fopen("num.bin","rb");
		while(!feof(pArchivo))
		{
			fread(arrayAux,sizeof(int),j,pArchivo);
			j++;
			isOk = 0;
		}
		fclose(pArchivo);
		for(int i = 0; i<size;i++)
		{
			printf("%d\n",arrayAux[i]);
		}
	}
	return isOk;
}
