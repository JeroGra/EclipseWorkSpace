#ifndef POKEBAG_H_
#define POKEBAG_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{

	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;

}eMyPokemon;

eMyPokemon* Element_newParametros(char* numero, char* nombre, char* tipo,char* tamanio,char* ataqueCargado,char* valorAtaque,char* esVariocolor);
eMyPokemon* Element_new();
void MainMenuOptions(int* option);
void Element_print(eMyPokemon* pokemon);
void Element_delete(eMyPokemon* this);
int FiltrarPorGroundsGrassFire(void* pokemon);
int FiltrarPorAguaVariocolor(void* pokemon);
void MapearAtaque(void* pokemon);

///setters///
int Element_setNum(eMyPokemon* this,char* numero);
int Element_setNombre(eMyPokemon* this,char* nombre);
int Element_setTipo(eMyPokemon* this,char* tipo);
int Element_setTamanio(eMyPokemon* this,char* tamanio);
int Element_setAtaqueCargado(eMyPokemon* this,char* ataqueCargado);
int Element_setValorAtaque(eMyPokemon* this,char* valorAtaque);
int Element_setEsVariocolor(eMyPokemon* this,char* esVariocolor);
int SetterElement(eMyPokemon* pasajero,char* numero, char* nombre, char* tipo,char* tamanio,char* ataqueCargado,char* valorAtaque,char* esVariocolor );

int SetNew_ValorAtaque(eMyPokemon* this,int* valorAtaqueAux);
///getters//
int Element_getNum(eMyPokemon* this,int* numero);
int Element_getNombre(eMyPokemon* this,char* nombre);
int Element_getTipo(eMyPokemon* this,char* tipo);
int Element_getTamanio(eMyPokemon* this,char* tamanio);
int Element_getAtaqueCargado(eMyPokemon* this,char* ataqueCargado);
int Element_getValorAtaque(eMyPokemon* this,int* valorAtaque);
int Element_getEsVariocolor(eMyPokemon* this,int* esVariocolor);
int GetterElement(eMyPokemon* pokemon, int*numero, char*nombre, char*tipo, char*tamanio, char*ataqueCargado, int*valorAtaque, int* esVariocolor);

void cabeceraLista();

#endif /* POKEBAG_H_ */
