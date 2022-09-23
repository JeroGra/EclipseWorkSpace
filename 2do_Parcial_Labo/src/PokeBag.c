#include "PokeBag.h"
#include "Input.h"
#include "LinkedList.h"

void MainMenuOptions(int* option)
{
 printf("\n|                                          MENU                                          |\n"
		  "|________________________________________________________________________________________|\n"
		  "|1. Cargar archivo pokemons(modo texto).                                                 |\n"
		  "|2. Eliminar pokemon.                                                                    |\n"
		  "|3. Imprimir pokemons.                                                                   |\n"
		  "|4. Filtrar por tipo Agua variocolor.                                                    |\n"
		  "|5. El dia esta despejado! mapear ataque cargado.                                        |\n"
		  "|6. Salir.                                                                               |\n"
		  "|----------------------------->>>Seleccione una opcion<<<--------------------------------|\n");
           *option = getInt("Seleccione la opcion\n",1,6);
}

eMyPokemon* Element_newParametros(char* numero, char* nombre, char* tipo,char* tamanio,char* ataqueCargado,char* valorAtaque,char* esVariocolor)
{
	eMyPokemon* pokemon = NULL;
	pokemon = Element_new();
	if(pokemon != NULL)
	{
           SetterElement(pokemon,numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
	}
	return pokemon;
}
eMyPokemon* Element_new()
{
	eMyPokemon* indice = (eMyPokemon*) malloc(sizeof(eMyPokemon)*1);
	if(indice != NULL)
	{
		indice->numero = 0;
		strcpy(indice->nombre,"");
		strcpy(indice->tipo,"");
		strcpy(indice->tamanio,"");
		strcpy(indice->ataqueCargado,"");
		indice->valorAtaque = 0;
		indice->esVariocolor = 0;
	}
	return indice;
}

void Element_delete(eMyPokemon* this)
{
	  if(this != NULL)
	  {
		  free(this);
		  this = NULL;
	  }
}

int FiltrarPorAguaVariocolor(void* pokemon)
{
	int isOk = -1;
	char tipo[50];
	int varicolor;
	if(pokemon != NULL)
	{
		Element_getTipo(pokemon,tipo);
		Element_getEsVariocolor(pokemon,&varicolor);
		if((strcmp(tipo,"Water")==0)&& varicolor == 1)
		{
			isOk = 1;
		}
	}
		return isOk;
}
int FiltrarPorGroundsGrassFire(void* pokemon)
{
	int isOk = -1;
	char tipo[50];
	if(pokemon != NULL)
	{
		Element_getTipo(pokemon,tipo);
		if((strcmp(tipo,"Ground")==0)||(strcmp(tipo,"Grass")==0)||(strcmp(tipo,"Fire")==0))
		{
			isOk = 1;
		}
	}
		return isOk;
}

void MapearAtaque(void* pokemon)
{
	int ataqueCargado;
	char tipo[50];
	int aumento;
	Element_getValorAtaque(pokemon,&ataqueCargado);
	Element_getTipo(pokemon,tipo);

	aumento = ataqueCargado* 0.10;
	ataqueCargado = ataqueCargado+aumento;

	if((strcmp(tipo,"Ground")==0)||(strcmp(tipo,"Grass")==0)||(strcmp(tipo,"Fire")==0))
	{
		SetNew_ValorAtaque(pokemon,&ataqueCargado);
	}
}
//////////////////// Setters //////////////////////////////////
int Element_setNum(eMyPokemon* this,char* numero)
{
	int isOk = 0;
	if(this != NULL)
	{
		this->numero = atoi(numero);
		isOk = 1;
	}
	return isOk;
}
int Element_setNombre(eMyPokemon* this,char* nombre)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->nombre,nombre);
		isOk = 1;
	}
	return isOk;
}
int Element_setTipo(eMyPokemon* this,char* tipo)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->tipo,tipo);
		isOk = 1;
	}
	return isOk;
}
int Element_setTamanio(eMyPokemon* this,char* tamanio)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->tamanio,tamanio);
		isOk = 1;
	}
	return isOk;
}
int Element_setAtaqueCargado(eMyPokemon* this,char* ataqueCargado)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->ataqueCargado,ataqueCargado);
		isOk = 1;
	}
	return isOk;
}
int Element_setValorAtaque(eMyPokemon* this,char* valorAtaque)
{
	int isOk = 0;
	if(this != NULL)
	{
		this->valorAtaque = atoi(valorAtaque);
		isOk = 1;
	}
	return isOk;
}
int Element_setEsVariocolor(eMyPokemon* this,char* esVariocolor)
{
	int isOk = 0;
	if(this != NULL)
	{
		this->esVariocolor = atoi(esVariocolor);
		isOk = 1;
	}
	return isOk;
}
int SetterElement(eMyPokemon* pasajero,char* numero, char* nombre, char* tipo,char* tamanio,char* ataqueCargado,char* valorAtaque,char* esVariocolor )
{
	int isOk = 0;
	if((Element_setNum(pasajero,numero)==1)                  &&
	   (Element_setNombre(pasajero,nombre)==1)               &&
	   (Element_setTipo(pasajero,tipo)==1)                   &&
	   (Element_setTamanio(pasajero,tamanio)==1)               &&
	   (Element_setAtaqueCargado(pasajero,ataqueCargado)==1) &&
	   (Element_setValorAtaque(pasajero,valorAtaque)==1)     &&
	   (Element_setEsVariocolor(pasajero,esVariocolor)==1))
	{
		isOk = 1;
	}

	return isOk;
}

int SetNew_ValorAtaque(eMyPokemon* this,int* valorAtaqueAux)
{
	int isOk = 0;
	if(this != NULL && valorAtaqueAux != NULL)
	{
		this->valorAtaque = *valorAtaqueAux;
		isOk = 1;
	}
	return isOk;
}

////////////////// Getters //////////////////////////////////

int Element_getNum(eMyPokemon* this,int* numero)
{
   int isOk = 0;
   if(this != NULL && numero != NULL)
   {
	   *numero = this->numero;
	   isOk = 1;
   }
   return isOk;
}
int Element_getNombre(eMyPokemon* this,char* nombre)
{
	   int isOk = 0;
	   if(this != NULL && nombre != NULL)
	   {
		   strcpy(nombre,this->nombre);
		   isOk = 1;
	   }
	   return isOk;
}
int Element_getTipo(eMyPokemon* this,char* tipo)
{
	   int isOk = 0;
	   if(this != NULL && tipo != NULL)
	   {
		   strcpy(tipo,this->tipo);
		   isOk = 1;
	   }
	   return isOk;
}
int Element_getTamanio(eMyPokemon* this,char* tamanio)
{
	   int isOk = 0;
	   if(this != NULL && tamanio != NULL)
	   {
		   strcpy(tamanio,this->tamanio);
		   isOk = 1;
	   }
	   return isOk;
}
int Element_getAtaqueCargado(eMyPokemon* this,char* ataqueCargado)
{
	   int isOk = 0;
	   if(this != NULL && ataqueCargado != NULL)
	   {
		   strcpy(ataqueCargado,this->ataqueCargado);
		   isOk = 1;
	   }
	   return isOk;
}
int Element_getValorAtaque(eMyPokemon* this,int* valorAtaque)
{
	   int isOk = 0;
	   if(this != NULL && valorAtaque != NULL)
	   {
		   *valorAtaque = this->valorAtaque;
		   isOk = 1;
	   }
	   return isOk;
}
int Element_getEsVariocolor(eMyPokemon* this,int* esVariocolor)
{
	   int isOk = 0;
	   if(this != NULL && esVariocolor != NULL)
	   {
		   *esVariocolor = this->esVariocolor;
		   isOk = 1;
	   }
	   return isOk;
}
int GetterElement(eMyPokemon* pokemon, int*numero, char*nombre, char*tipo, char*tamanio, char*ataqueCargado, int*valorAtaque, int* esVariocolor)
{
	int isOk = 0;
	if((Element_getNum(pokemon,numero))                  &&
	   (Element_getNombre(pokemon,nombre))               &&
	   (Element_getTipo(pokemon,tipo))                   &&
	   (Element_getTamanio(pokemon,tamanio))             &&
	   (Element_getAtaqueCargado(pokemon,ataqueCargado)) &&
	   (Element_getValorAtaque(pokemon,valorAtaque))     &&
	   (Element_getEsVariocolor(pokemon,esVariocolor))
	)
	{
	   isOk = 1;
	}
	return isOk;
}

//////////////////Print/////////////////////////////////

void Element_print(eMyPokemon* pokemon)
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;

	if(GetterElement(pokemon,&numero,nombre,tipo,tamanio,ataqueCargado,&valorAtaque,&esVariocolor) == 1)
	{
	printf("|%-5d\t|%-25s\t|%-25s\t|%-25s\t|%-25s\t|%-5d\t|%-5d\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
	}
}

void cabeceraLista()
{
	printf("|Numero |Nombre                         |Tipo                           |Tamanio                        |AtaqueCargado                  |Ataque |Es shiny?\n");
}



