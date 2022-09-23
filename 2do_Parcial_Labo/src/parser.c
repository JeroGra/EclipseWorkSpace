#include "controller.h"
#include "input.h"
#include "LinkedList.h"
#include "PokeBag.h"


int parser_ElementFromText(FILE* pFile,LinkedList* listaPokemon)
{
	int respuesta = -1;
	int retorno;
	eMyPokemon* nuevoPokemon;
	char numero[128];
	char nombre[128];
	char tipo[128];
	char tamanio[128];
	char ataqueCargado[128];
	char valorAtaque[128];
	char esVariocolor[128];
	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
			nuevoPokemon = Element_newParametros(numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
			if(nuevoPokemon != NULL)
			{
				retorno = ll_add(listaPokemon,nuevoPokemon);
				retorno = retorno+0;
			}
		}
          if(retorno == 0)
          {
        		respuesta = 1;
          }
	}
    return respuesta;
}

