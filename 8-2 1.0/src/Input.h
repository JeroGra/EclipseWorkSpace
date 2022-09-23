#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int PedirOpcionMenu();
int getInt(char mensaje[], int minimo, int maximo);
int ValidacionInt(int numero, int minimo, int maximo);
float getFloat(char mensaje[], int minimo, int maximo);
float Validacionfloat(float numero, int minimo, int maximo);
void getString(char descripcion[],char mensaje[], int maximo);
#endif /* INPUT_H_ */
