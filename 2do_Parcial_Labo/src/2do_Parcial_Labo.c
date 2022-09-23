/*
 ============================================================================
 Name        : 2do_Parcial_Labo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Input.h"
#include "Controller.h"
#include "PokeBag.h"

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* listaPokemon = ll_newLinkedList();
    int option;
    int banderaCambios = 0;

    do{
    	MainMenuOptions(&option);
    	switch(option)
    	{
    	case 1:
    		if(Granadillo_controller_loadFromText("Data_Pokemones.csv",listaPokemon)!=-1)
    		{
    			printf("Pokemons Cargados\n");
    		}
    		else
    		{
    			printf("Ocurrio un error en la Carga\n");
    		}
    	break;
    	case 2:
    		if(!ll_isEmpty(listaPokemon))
    		{
				if(Granadillo_controller_remove(listaPokemon)==1)
				{
					banderaCambios = 1;
				}
    		}
    		else
			{
				printf("\n|-->No hay datos para modificar.\n");
			}
    	break;
    	case 3:
    		if(!ll_isEmpty(listaPokemon))
    		{
    			Granadillo_controller_List(listaPokemon);
    		}
    		else
			{
				printf("\n|-->No hay datos para modificar.\n");
			}
    	break;
    	case 4:
    		if(!ll_isEmpty(listaPokemon))
    		{
    			Granadillo_controller_Filtrar_TipoAgua_Variocolor(listaPokemon);
    		}
    		else
			{
				printf("\n|-->No hay datos para modificar.\n");
			}
    	break;
    	case 5:
    		if(!ll_isEmpty(listaPokemon))
    		{
    			if(Granadillo_controller_map_ataqueCargado(listaPokemon)==1)
    			{
    				banderaCambios = 1;
    			}
    		}
    		else
			{
				printf("\n|-->No hay datos para modificar.\n");
			}
    	break;
    	case 6:
    		if(banderaCambios == 1)
    		{
    			printf("Se realizaron cambios, desea salir sin guardar?\n");
    			if(getInt("1.Si\n"
    					  "2.Guardar\n"
    					  "Seleccione la respuesta: \n",1,2)==2)
    			{
    				if(Granadillo_controller_saveAsText("Data_Pokemones.csv",listaPokemon)==1)
    				{
    					printf("Se Guardaron los cambios en el archivo\n");
    					printf("Hasta luego entrenador/a!\n");
    				}
    			}
    			else
    			{
    				printf("Hasta luego entrenador/a!\n");
    			}
    		}
    	break;
    	}
    }while(option!=6);
	return EXIT_SUCCESS;
}
