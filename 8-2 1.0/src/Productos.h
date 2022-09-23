#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define de nacionalidades
#define EEUU  1
#define CHINA 2
#define OTRO  3
//Define de tipos de producto
#define IPHONE 10
#define MAC 11
#define IPAD 12
#define ACCSESORIOS 13
//Define estados
#define CARGADO 1
#define SIN_CARGAR 0
#define DE_BAJA -1

typedef struct{
	int idProducto;
	char descripcion[200];
	int nacionalidad;
	int tipo;
	float precio;

	int estado;//ESTADO CARGADO, SIN_CARGAR, DE_BAJA


}eProductos;
int AltaDeProductos(eProductos listaProductos[], int sizeProductos);
int ModificarProductos(eProductos listaProductos[], int sizeProductos);
int DarBajaProductos(eProductos listaProductos[], int sizeProductos);
int BuscarEspacioLibre(eProductos listaProductos[], int sizeProductos);
int BuscarEspacioOcupado(eProductos listaProductos[], int sizeProductos);
eProductos CargarProducto(eProductos listaProductos[], int sizeProductos);
void ListaDeProductos(eProductos listaProductos[], int sizeProductos);
void OrdenarPorId(eProductos listaProductos[], int sizeProductos);
void MostrarProducto(eProductos listaProductos);
void ListaProductosOrdenadosPorPrecio(eProductos listaProductos[],int sizeProductos);//Criterio ordenado de mas caro a mas barato
void ListaProductosOrdenadosPorDescripcion(eProductos listaProductos[],int sizeProductos);//Criterio ordenado por mayor cantidad de descripcion a menor cantidad
int GeneradorId(eProductos listaProductos[], int sizeProductos);
int DefinirProducto();
int DefinirNacionalidad();
void ListaProductosHardcode(eProductos listaProductos[]);
#endif /* PRODUCTOS_H_ */
