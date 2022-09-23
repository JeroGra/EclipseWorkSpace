#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"
#include "Input.h"
#define L 7 //Largo del vector listaProductos
#define SALIR 10 //Hace referencia al numero de la opcion salir
int main(void) {
    setbuf(stdout, NULL);
    eProductos listaProductos[L];
    int opcionMenu;
    int retorno;

    for(int i = 0; i<L;i++)
    	{
    		listaProductos[i].estado = SIN_CARGAR;
    		listaProductos[i].idProducto = 0;
    	}
    ListaProductosHardcode(listaProductos);
    do{

    	opcionMenu = PedirOpcionMenu();
    	switch(opcionMenu)
    	    	{
    	    	case 1:
    	    		retorno = AltaDeProductos(listaProductos,L);
    	    		switch(retorno)
    	    		{
    	    		case -1:
    	    		 printf("No hay espacio para cargar un producto\n");
    	    		break;
    	    		case -2:
    	    		 printf("Se cancelo la operacion...\n");
    	    		break;
    	    		default:
    	    		 printf("Operacion realizada con exito\n");
    	    		break;

    	    		}
    	        break;
    	    	case 2:
                    retorno = DarBajaProductos(listaProductos, L);
                    switch(retorno)
					{
					case -1:
					 printf("No Se encontro Producto para dar de Baja\n");
					break;
					case -2:
					 printf("Se cancelo la operacion...\n");
					break;
					default:
					 printf("Operacion realizada con exito\n");
					break;
					}
    	        break;
    	    	case 3:
    	    		retorno = ModificarProductos(listaProductos,L);
    	    		switch(retorno)
    	    		{
    	    		case -1:
    	    			printf("No se encontraron productos cargados para modificar\n");
    	    		break;
    	    		case -2:
    	    			 printf("Se cancelo la operacion...\n");
    	    		break;
    	    		}
    	        break;
    	    	case 4:
    	    		ListaDeProductos(listaProductos,L);
    	        break;
    	    	case 5:
    	    		ListaProductosOrdenadosPorPrecio(listaProductos,L);
    	        break;
    	    	case 6:
    	    		ListaProductosOrdenadosPorDescripcion(listaProductos,L);
    	        break;
    	    	case 7:

    	        break;
    	    	case 8:

    	        break;
    	    	case 9:

    	        break;
    	    	case 10:
    	    		printf("Hasta luego");
    	        break;
    	    	}

    }while(opcionMenu != SALIR);
	return EXIT_SUCCESS;
}
