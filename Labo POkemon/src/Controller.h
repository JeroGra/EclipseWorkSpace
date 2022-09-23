#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "PokeBag.h"
int Granadillo_controller_loadFromText(char* path, LinkedList* listaPokemon);
int Granadillo_controller_saveAsText(char* path , LinkedList* listaPokemon);
int Granadillo_controller_List(LinkedList* listaPokemon);
int Granadillo_controller_editElement(LinkedList* listaPokemon);
int Granadillo_controller_findElementById(LinkedList* listaPokemon,eMyPokemon* pokemon);
int Granadillo_obtenerIndiceElemento(LinkedList* listaPokemon,eMyPokemon* pokemon,int len, int idAux);
int Granadillo_controller_editElement(LinkedList* listaPokemon);
int Granadillo_controller_FiltrarTipofuego(LinkedList* listaPokemon);
int Granadillo_controller_FiltrarXL_TipoVeneno(LinkedList* listaPokemon);



#endif /* CONTROLLER_H_ */
