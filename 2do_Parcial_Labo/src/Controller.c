#include "LinkedList.h"
#include "Input.h"
#include "Controller.h"
#include "parser.h"
#include "PokeBag.h"

int Granadillo_controller_loadFromText(char* path, LinkedList* listaPokemon)
{
	int respuesta = -1;
	int retorno;
	FILE* pArchivo;
	if(path != NULL && listaPokemon != NULL)
	{
	 pArchivo = fopen(path,"r");
	 retorno = parser_ElementFromText(pArchivo,listaPokemon);
	 if(retorno == 1)
	 {
		 respuesta = 1;
	 }
	 fclose(pArchivo);
	}
    return respuesta ;
}

int Granadillo_controller_List(LinkedList* listaPokemon)
{
	int isOk = -1;
	eMyPokemon* pokemon;
	if(listaPokemon != NULL)
	{
		isOk = 1;
		cabeceraLista();
		for(int i = 0; i<ll_len(listaPokemon); i++)
		{
		pokemon = (eMyPokemon*) ll_get(listaPokemon, i);
		Element_print(pokemon);
		}
	}
    return isOk;
}

int Granadillo_controller_remove(LinkedList* listaPokemon)
{
	int respuesta = 0;
    int indiceP;
    eMyPokemon* pokemon = NULL;

    indiceP= Granadillo_controller_findElementById(listaPokemon,pokemon);
    pokemon = ll_get(listaPokemon,indiceP);

	printf("Este es el pasajero seleccionado para eliminar?\n");
	cabeceraLista();
	Element_print(pokemon);
	if(getInt("1.Si\n"
			  "2.No\n"
			  "Seleccione la respuesta: \n",1,2)==1)
	{
		pokemon = ll_pop(listaPokemon,indiceP);
		printf("Se ah eliminado a \n");
		cabeceraLista();
		Element_print(pokemon);
		respuesta = 1;
	}
	else
	{
		printf("Se cancelo la operacion\n");
	}
    return respuesta;
}

int Granadillo_controller_findElementById(LinkedList* listaPokemon,eMyPokemon* pokemon)
{
	int index = -1;
	int len;
	int IdAux;
	len = ll_len(listaPokemon);
	printf("\nPOKEMONS\n");
	Granadillo_controller_List(listaPokemon);
	IdAux = getInt("Seleccione el id del pasajero: \n",1,100000);
	index = Granadillo_obtenerIndiceElemento(listaPokemon,pokemon,len,IdAux);
	while(index == -1)
	{
		IdAux = getInt("Seleccione el id del pasajero: \n",1,100000);
		index = Granadillo_obtenerIndiceElemento(listaPokemon,pokemon,len,IdAux);
	}

	return index;
}
int Granadillo_obtenerIndiceElemento(LinkedList* listaPokemon,eMyPokemon* pokemon,int len, int idAux)
{
	int index;
	for(int i = 0;i<len;i++)
		{
		pokemon = ll_get(listaPokemon,i);
			if(idAux == pokemon->numero )
			{
				index = i;
				break;
			}
		}
	return index;
}

int Granadillo_controller_Filtrar_TipoAgua_Variocolor(LinkedList* listaPokemon)
{
   int isOk = -1;
   LinkedList* listaAux;
   if(listaPokemon != NULL)
   	{
	   listaAux = ll_filter(listaPokemon,FiltrarPorAguaVariocolor);
	   if(listaAux!= NULL)
	   {
		   printf("LISTADO DE POKEMONS DE TIPO AGUA SHINY\n");
		   Granadillo_controller_List(listaAux);
		   isOk = 1;
	   }
	   ll_deleteLinkedList(listaAux);
   	}
   return isOk;
}
int Granadillo_controller_saveAsText(char* path , LinkedList* listaPokemon)
{
	int retorno = -1;
	int i;
	int longitud;
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;
	FILE* pArchivo;
	eMyPokemon* pokemon = NULL;
	if(path != NULL && listaPokemon != NULL)
	{
		pArchivo = fopen(path,"w");
		longitud = ll_len(listaPokemon);
		if(pArchivo != NULL && longitud > 0)
		{
			for(i = 0; i<longitud;i++)
			{
				pokemon = (eMyPokemon*) ll_get(listaPokemon,i);
				if(pokemon != NULL)
				{
					if(GetterElement(pokemon,&numero,nombre,tipo,tamanio,ataqueCargado,&valorAtaque,&esVariocolor)==1)
					{
						fprintf(pArchivo,"%d,%s,%s,%s,%s,%d,%d\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
						retorno = 1;
					}
					else
					{
						Element_delete(pokemon);
					}
				}
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}

int Granadillo_controller_map_ataqueCargado(LinkedList* listaPokemon)
{
	int isOk = -1;
	LinkedList* listaAux;
	if(listaPokemon != NULL)
	{
		if(!ll_map(listaPokemon,MapearAtaque))
		{
			printf("Se mapearon los ataques! Ahora los siguientes pokemon tienen un Buff del 10%c en su ataque\n",37);
			isOk = 1;
		}
	}

	listaAux = ll_filter(listaPokemon,FiltrarPorGroundsGrassFire);
	if(listaAux != NULL)
	{
     printf("LISTADO DE POKEMONS MAPEADOS\n");
     Granadillo_controller_List(listaAux);
	}
	ll_deleteLinkedList(listaAux);
	return isOk;
}
