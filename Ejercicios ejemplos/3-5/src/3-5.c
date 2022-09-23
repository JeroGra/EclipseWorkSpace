/*
 ============================================================================
 Name        : 3-5.c
 Author      : Jeronimo Granadillo
 Version     : 1.0
 Copyright   : Your copyright notice
 Description :  Decidi variar un poco los datos y no solo usar enteros, Mas que nada para experimentar.
 ============================================================================
 */
 // (-_-)/ "HE VOO!" - \(-O-)/ "Esto fue programado en eclipse"
#include <stdio.h>
#include <stdlib.h>

int Sumar1(int numero1, int numero2);
int Sumar2(void);
void Sumar3(float numero1 , float numero2);
void Sumar4(void);

int main(void)
{
	setbuf(stdout, NULL);
	int primerNumeroIngresado;
	int segundoNumeroIngresado;
	int resultado;
	int resultado2;
	float primerFlotante;
	float segundoFlotante;

	printf("Coloque un primer numero: ");
	scanf("%d", &primerNumeroIngresado);

	printf("Coloque un segundo numero: ");
    scanf("%d", &segundoNumeroIngresado);

    resultado = Sumar1(primerNumeroIngresado, segundoNumeroIngresado);
    printf("La suma de los numero es: %d \n", resultado);
    resultado2 = Sumar2();
    printf("La suma de los numero es: %d \n", resultado2);

    printf("Coloque un primer numero flotante: ");
    scanf("%f", &primerFlotante);

    printf("Coloque un segundo numero flotante: ");
    scanf("%f", &segundoFlotante);

    Sumar3(primerFlotante,segundoFlotante);

    Sumar4();

    return EXIT_SUCCESS;
}

int Sumar1(int numero1, int numero2)
{
	int suma;
	suma = numero1 + numero2;
	return suma;
}

int Sumar2(void)
{
  int num1;
  int num2;
  int suma;

  printf("Coloque un primer numero mayor a 100: ");
  scanf("%d", &num1);
  while(num1 < 100)
  {
	  printf("PORFAVOR! Coloque un primer numero mayor a 100: ");
	  scanf("%d", &num1);
  }

  printf("Coloque un segundo numero menor a 100: ");
  scanf("%d", &num2);
  while(num2 > 100)
  {
	  printf("PORFAVOR! Coloque un segundo numero menor a 100: ");
	  scanf("%d", &num2);
  }

  suma = num1 + num2;
  return suma;

}

void Sumar3(float numero1 , float numero2)
{
	float suma;
	suma = numero1 + numero2;
	printf("La suma de los flotantes es: %f \n", suma);
}

void Sumar4(void)
{
	int primerNegativo;
	int segundoNegativo;
	int suma;

	printf("Coloque un numero negativo: ");
	scanf("%d", &primerNegativo);
	while(primerNegativo > -1)
	{
		printf("LE DIJE QUE! Coloque un numero negativo: ");
	    scanf("%d", &primerNegativo);
	}


	printf("Coloque otro numero negativo: ");
	scanf("%d", &segundoNegativo);
	while(segundoNegativo > -1)
	{
		printf("LE DIJE QUE! Coloque un numero negativo: ");
	    scanf("%d", &segundoNegativo);
	}

	suma = primerNegativo + segundoNegativo;
	printf("La suma de los negativos da: %d", suma);
}






