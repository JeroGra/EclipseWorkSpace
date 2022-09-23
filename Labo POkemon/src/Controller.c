#include "LinkedList.h"
#include "PokeBag.h"
#include "Input.h"
#include "Controller.h"
#include "parser.h"

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
	eMyPokemon* pokemon;
	for(int i = 0; i<ll_len(listaPokemon); i++)
	{
		pokemon = (eMyPokemon*) ll_get(listaPokemon, i);
		Element_print(pokemon);
	}
    return 1;
}

int Granadillo_controller_editElement(LinkedList* listaPokemon)
{
	int isOk = -1;
	eMyPokemon* pokemon = NULL;
	int indicePoke;
	int valorAtaqueAux;
	int option;
	int BanderaCambios = 0;
	if(listaPokemon != NULL)
	{
		indicePoke = Granadillo_controller_findElementById(listaPokemon,pokemon);
		pokemon = ll_get(listaPokemon,indicePoke);
		printf("Este es el pokemon seleccionado para Modificar?\n");
		Element_print(pokemon);
	    if(getInt("1.Si\n"
				 "2.No\n"
				 "Seleccione la respuesta: \n",1,2)==1)
	    {
		do {
			option = getInt("\n|     MENU MODIFICACIONES     |\n"
								 "|_____________________________|\n"
								 "|1.valorAtaque                |\n"
								 "|2.Salir                      |\n"
								 "|--->Seleccione una opcion<---|\n",1,2);
			   switch(option)
			   {
			   case 1:
				   valorAtaqueAux = getInt("Coloque el nuevo valor del ataque\n",0,1000);
				   if(SetNew_ValorAtaque(pokemon,&valorAtaqueAux)==1)
				   {
					   BanderaCambios = 1;
				   }
			   break;
			   case 2:
				   if(BanderaCambios == 0)
				   {
					   printf("No se realizaron Cambios");
				   }
				   else
				   {
					   printf("Este es el resultado de los cambios\n");
					   Element_print(pokemon);
					   if(getInt("Son correctos?\n"
								 "1.Si\n"
								 "2.No\n",1,2)==2)
					   {
						   if(getInt("Deseas modificar devuelta?\n"
									 "1.Si\n"
									 "2.No\n",1,2)==1)
						   {
							   option = 0;
						   }
					   }
				   }
			   break;
			   }
			   if(BanderaCambios == 1 && option != 6 && option != 0)
			   {
				   printf("Se realizo el cambio\n");
				   isOk = 1;
			   }
			   }while(option != 2);
	    }
	    else
	    {
			printf("Se cancelo la operacion\n");
			Element_delete(pokemon);
	    }

	}
	return isOk;
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

int Granadillo_controller_FiltrarXL_TipoVeneno(LinkedList* listaPokemon)
{
   int isOk = -1;
   LinkedList* listaAux;
   if(listaPokemon != NULL)
   	{
	   listaAux = ll_filter(listaPokemon,FiltrarPorXlyVeneno);
	   if(Granadillo_controller_saveAsText("Pokemons_XL_Tipo_Veneno.csv",listaAux))
		{
		  printf("Se creo un nuevo archivo csv con el filtro\n");
		  printf("LISTADO DE POKEMONS XL TIPO VENENO\n");
		  Granadillo_controller_List(listaAux);
		}
		else
		{
		  printf("Ocurrio un Error\n");
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

