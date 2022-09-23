
#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
/// @fn int parser_ElementFromText(FILE*, LinkedList*)
/// @brief parsea los elementos leidos de una rchivo de texto
///
/// @param pFile archivo cual se leera y extraera los datos
/// @param lista donde se quieren cargar los elementos
/// @return respuesta = -1 si ocurrio un error
/// respuesta = 1 si la operacion se logro realizar
int parser_ElementFromText(FILE* pFile , LinkedList* listaPokemon);

#endif /* PARSER_H_ */
