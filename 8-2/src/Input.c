#include "Productos.h"
#include "Input.h"

int PedirOpcionMenu()
{
	int opcion;

	printf("1.Dar alta de productos\n2.Dar baja de productos\n3.Modificar Productos\n4.Listado de productos\n5.Listado ordenado por precio\n6.Listado ordenado por descripcion\n10.Salir\n");
	opcion = getInt("Elija Una opcion: \n",1,10);

	return opcion;
}

int getInt(char mensaje[], int minimo, int maximo)
{
	int enteroObtenido = 0;
	int enteroValidado;
	int entero;
	int longitud;
	printf("%s",mensaje);
	fflush(stdin);
	longitud = strlen(mensaje);
	if(mensaje != NULL && longitud > 0)
	{
		scanf("%d",&entero);
		if(entero >= minimo && entero <= maximo)
		{
			enteroObtenido = entero;
		}
	}
	enteroValidado = ValidacionInt(enteroObtenido,minimo,maximo);
	return enteroValidado;
}

int ValidacionInt(int numero, int minimo, int maximo)
{

	while(numero == 0)
		{
			numero = getInt("Error Vuelva a ingresar un valor: \n",minimo,maximo);
		}
	return numero;
}

float getFloat(char mensaje[], int minimo, int maximo)
{
	float floatValidado;
	float floatObtenido = 0;
	int longitud;
	float flotante;
	printf("%s",mensaje);
	fflush(stdin);
	longitud = strlen(mensaje);
	if(mensaje != NULL && longitud > 0)
	{
		scanf("%f",&flotante);
		if(flotante >= minimo && flotante <= maximo)
		{
			floatObtenido = flotante;
		}
	}
	floatValidado = Validacionfloat(floatObtenido,minimo,maximo);
	return floatValidado;
}
float Validacionfloat(float numero, int minimo, int maximo)
{

	while(numero == 0)
		{
			numero = getFloat("Error Vuelva a ingresar un valor: \n",minimo,maximo);
		}
	return numero;
}

void getString(char descripcion[],char mensaje[], int maximo)
{
	int longitud;
	printf("%s",mensaje);
	fflush(stdin);
	gets(descripcion);
	longitud = strlen(descripcion);

    while(strcmp(descripcion,"") == 0|| longitud > maximo)
    {
    	printf("ERROR Coloque una descripcion valida: \n");
    	fflush(stdin);
    	gets(descripcion);
    }
}
