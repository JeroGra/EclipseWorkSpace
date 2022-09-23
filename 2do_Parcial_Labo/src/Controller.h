#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "PokeBag.h"

/// @fn int Granadillo_controller_loadFromText(char*, LinkedList*)
/// @brief Cargar datos de un archivo externo hacia una lista en memoria
///
/// @param path directorio del archivo de texto
/// @param lista donde queremos cargar los datos en memoria
/// @return devuelve respuesta = -1 si el directorio y la lista son iguales a NULL
/// devuelve 1 si se logro realizar la operacion
int Granadillo_controller_loadFromText(char* path, LinkedList* listaPokemon);

/// @fn int Granadillo_controller_saveAsText(char* path, LinkedList*)
/// @brief Toma los datos de una lista en memoria para guardarlos en un archivo de texto
///
/// @param path directorio del archivo de texto
/// @param lista que posee los datos en memoria a guardar
/// @return devuelve respuesta = -1 si el directorio y la lista son iguales a NULL
/// devuelve 1 si se logro realizar la operacion
int Granadillo_controller_saveAsText(char* path , LinkedList* listaPokemon);

/// @fn int Granadillo_controller_List(LinkedList*)
/// @brief toma la lista de elementos para ir obteniendo cada elemento de la lista y pasarlos a una funcion que lo printee
///
/// @param lista con elementos a printear
/// @return retorna isOk = -1 si la lista es = NULL, sino isOk = 1
int Granadillo_controller_List(LinkedList* listaPokemon);

/// @fn int Granadillo_controller_findElementById(LinkedList*, eMyPokemon*)
/// @brief busca un el elemento de la lista y devuele su indice
///
/// @param lista donde se encuentran los elementos
/// @param elemento al cual usaremos para encontrar el indice deseado
/// @return devuelve el indice del elemento deseado
int Granadillo_controller_findElementById(LinkedList* listaPokemon,eMyPokemon* pokemon);

/// @fn int Granadillo_obtenerIndiceElemento(LinkedList*, eMyPokemon*, int, int)
/// @brief comapra indices de los elementos hasta encontrar la primera similitud segun el id seleccionado
///
/// @param lista donde se encuentran los elementos
/// @param elemento al cual usaremos para encontrar el indice deseado
/// @param largo de la lista
/// @param idAux id que se usa como referencia para machear los indices de los elementos
/// @return devuelve el indice del elemento
int Granadillo_obtenerIndiceElemento(LinkedList* listaPokemon,eMyPokemon* pokemon,int len, int idAux);

int Granadillo_controller_remove(LinkedList* listaPokemon);


int Granadillo_controller_Filtrar_TipoAgua_Variocolor(LinkedList* listaPokemon);

int Granadillo_controller_map_ataqueCargado(LinkedList* listaPokemon);



#endif /* CONTROLLER_H_ */
