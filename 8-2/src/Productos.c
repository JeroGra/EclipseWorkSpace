#include "Productos.h"
#include "Input.h"
eProductos CargarProducto(eProductos listaProductos[], int sizeProductos)
{
	eProductos Producto;
    Producto.idProducto = GeneradorId(listaProductos,sizeProductos);

	Producto.tipo = DefinirProducto();

    getString(Producto.descripcion,"Coloque una descripcion: \n",200);

	Producto.nacionalidad = DefinirNacionalidad();

    Producto.precio = getFloat("Coloque el precio: \n",0,1000000);

	Producto.estado = CARGADO;

	return Producto;
}
int GeneradorId(eProductos listaProductos[], int sizeProductos)
{
	int nuevoId = 0;
	OrdenarPorId(listaProductos,sizeProductos);
	nuevoId = listaProductos[0].idProducto + 1;

     return nuevoId;
}

void OrdenarPorId(eProductos listaProductos[], int sizeProductos)
{
	eProductos auxiliar;

		for(int i = 0; i < sizeProductos-1; i++)
		{
			for(int j = i+1; j < sizeProductos;j++)
			{
				if(listaProductos[i].idProducto < listaProductos[j].idProducto)
				{
					auxiliar = listaProductos[i];
					listaProductos[i] = listaProductos[j];
					listaProductos[j] = auxiliar;
				}
			}
		}
}

void ListaProductosHardcode(eProductos listaProductos[])
{
	eProductos auxiliar[5]={{1,"I5",EEUU,IPAD,300,CARGADO},{2,"PRO",OTRO,MAC,300,CARGADO},{4,"I5",CHINA,IPHONE,500,CARGADO},{10,"negro",EEUU,ACCSESORIOS,56,CARGADO},{3,"trucho",OTRO,IPAD,33,CARGADO}};
	for(int i = 0; i<5; i++)
	{
		listaProductos[i]=auxiliar[i];
	}
}

int DefinirProducto()
{
	int opcionMenuProductos = 0;
	opcionMenuProductos = getInt("1.IPHONE\n2.MAC\n3.IPAD\n4.ACCESORIO\nIngrese la opcion a cargar: \n",1,4);
	switch(opcionMenuProductos)
	{
	case 1:
		opcionMenuProductos = IPHONE;
	break;
	case 2:
		opcionMenuProductos = MAC;
	break;
	case 3:
		opcionMenuProductos = IPAD;
	break;
	case 4:
		opcionMenuProductos = ACCSESORIOS;
	break;

	}
	return opcionMenuProductos;
}

int DefinirNacionalidad()
{
	int opcionMenuNacionalidad = 0;
	opcionMenuNacionalidad = getInt("1.EE.UU\n2.CHINA\n3.OTRO\nIngrese la nacionalidad a cargar: \n",1,3);
	switch(opcionMenuNacionalidad)
	{
	case 1:
		opcionMenuNacionalidad = EEUU;
	break;
	case 2:
		opcionMenuNacionalidad = CHINA;
	break;
	case 3:
		opcionMenuNacionalidad = OTRO;
	break;
	}
	return opcionMenuNacionalidad;
}

int BuscarEspacioLibre(eProductos listaProductos[], int sizeProductos)
{
	int respuesta;
	respuesta  = -1;// hace refrencia al indice del vector
	for(int i = 0; i < sizeProductos; i++)
	{
		if(listaProductos[i].estado == SIN_CARGAR)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}
int BuscarEspacioOcupado(eProductos listaProductos[], int sizeProductos)
{
	int respuesta;
	respuesta  = -1;// hace refrencia al indice del vector
	for(int i = 0; i < sizeProductos; i++)
	{
		if(listaProductos[i].estado == CARGADO)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}

int AltaDeProductos(eProductos listaProductos[], int sizeProductos)
{
	int respuesta;
	respuesta = BuscarEspacioLibre(listaProductos, sizeProductos); // recibe el indice del vector donde hay espacio para cargar datos
	if(respuesta != -1)
	{
		switch(getInt("1.Cargar Producto\n2.Cancelar Operacion\nElija una opcion: \n", 1, 2))
		{
		case 1:
			 listaProductos[respuesta] = CargarProducto(listaProductos,sizeProductos);
		break;
		case 2:
			 respuesta = -2;
		break;
		}
	}
	return respuesta;
}

int ModificarProductos(eProductos listaProductos[], int sizeProductos)
{
	int respuesta;
	int opcionMenuModificar;
	int idProducto;
	int productoIdMayor;
	int i = 0;
	respuesta = BuscarEspacioOcupado(listaProductos,sizeProductos);
	{
		switch(getInt("1.Modificar un Producto\n2.Cancelar Operacion\nElija una opcion: \n", 1, 2))
		{
		case 1:
			 OrdenarPorId(listaProductos,sizeProductos);
			 productoIdMayor = listaProductos[0].idProducto;
			 ListaDeProductos(listaProductos,sizeProductos);
			 idProducto = getInt("Seleccione el id del producto a modificar: \n",1,productoIdMayor);
			 for(;i < sizeProductos;i++)
			 {
				 if(idProducto == listaProductos[i].idProducto)
				 {
					 break;
				 }
			 }
			do{
				 switch(opcionMenuModificar = getInt("Que desea modificar?\n1.Modificar tipo de Producto\n2.Modificar Nacionalidad\n3.Modificar Descripcion\n4.Modificar Precio\n5.Salir\nElija una opcion: \n", 1, 5))
				 {
				 case 1:
					 listaProductos[i].tipo = DefinirProducto();
					 printf("Tipo de producto Modificado\n");
				 break;

				 case 2:
					 listaProductos[i].nacionalidad = DefinirNacionalidad();
					 printf("Nacionalidad Modificada\n");
				 break;

				 case 3:
					 getString(listaProductos[i].descripcion,"Coloque una descripcion: \n",50);
					 printf("Descripcion Modificada\n");
				 break;

				 case 4:
					 listaProductos[i].precio =  getFloat("Coloque el precio: \n",0,1000000);
					 printf("Precio Modificado\n");
				 break;

				 case 5:
					 printf("Saliendo...\n");
				 break;
			     }
			}while(opcionMenuModificar != 5);
		break;
		case 2:
			 respuesta = -2;
		break;
		}
	}
	return respuesta;
}

int DarBajaProductos(eProductos listaProductos[], int sizeProductos)
{
	int respuesta;
	int idProducto;
	int productoIdMayor;
	int i = 0;
	respuesta = BuscarEspacioOcupado(listaProductos,sizeProductos);
	{
		switch(getInt("1.Dar de Baja un Producto\n2.Cancelar Operacion\nElija una opcion: \n", 1, 2))
		{
		case 1:
			 OrdenarPorId(listaProductos,sizeProductos);
			 productoIdMayor = listaProductos[0].idProducto;
			 ListaDeProductos(listaProductos,sizeProductos);
			 idProducto = getInt("Seleccione el id del producto a modificar: \n",1,productoIdMayor);
			 for(;i < sizeProductos;i++)
			 {
				 if(idProducto == listaProductos[i].idProducto)
				 {
					 listaProductos[i].estado = DE_BAJA;
					 break;
				 }
			 }
		break;
		case 2:
			respuesta = -2;
		break;
		}
	}
	return respuesta;
}
void ListaDeProductos(eProductos listaProductos[], int sizeProductos)
{
	for(int i = 0; i < sizeProductos; i++)
	{
		MostrarProducto(listaProductos[i]);
	}
}

void ListaProductosOrdenadosPorPrecio(eProductos listaProductos[],int sizeProductos)
{
	eProductos auxiliar;

		for(int i = 0; i < sizeProductos-1; i++)
		{
			for(int j = i+1; j < sizeProductos;j++)
			{
				if(listaProductos[i].precio < listaProductos[j].precio)
				{
					auxiliar = listaProductos[i];
					listaProductos[i] = listaProductos[j];
					listaProductos[j] = auxiliar;
				}
				else
				{
					if(listaProductos[i].precio == listaProductos[j].precio)
					{
						if(listaProductos[i].idProducto > listaProductos[j].idProducto)
						{
							auxiliar = listaProductos[i];
							listaProductos[i] = listaProductos[j];
							listaProductos[j] = auxiliar;
						}
					}
				}
			}
		}

	   ListaDeProductos(listaProductos,sizeProductos);
}

void ListaProductosOrdenadosPorDescripcion(eProductos listaProductos[],int sizeProductos)
{
	eProductos auxiliar;
	int stringI;
	int stringJ;

		for(int i = 0; i < sizeProductos-1; i++)
		{
			for(int j = i+1; j < sizeProductos;j++)
			{
				stringI = strlen(listaProductos[i].descripcion);
		        stringJ = strlen(listaProductos[j].descripcion);
				if(stringI < stringJ)
				{
					auxiliar = listaProductos[i];
					listaProductos[i] = listaProductos[j];
					listaProductos[j] = auxiliar;
				}
				else
				{
					if(stringI == stringJ)
					{
						if(listaProductos[i].idProducto > listaProductos[j].idProducto)
						{
							auxiliar = listaProductos[i];
							listaProductos[i] = listaProductos[j];
							listaProductos[j] = auxiliar;
						}
					}
				}
			}
		}

	   ListaDeProductos(listaProductos,sizeProductos);
}

void MostrarProducto(eProductos listaProductos)
{
      if(listaProductos.estado == CARGADO)
      {
    	  switch(listaProductos.tipo)
    	  {
    	  case IPHONE :
    		  switch(listaProductos.nacionalidad)
    		  {
    		  case EEUU:
    			  printf("Id:%d - IPHONE - EEUU - '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
    		  break;
    		  case CHINA:
    			  printf("Id:%d - IPHONE - CHINA - '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
    		  break;
    		  case OTRO:
    			  printf("Id:%d - IPHONE - OTRO - '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
    		  break;
    		  }
    	  break;
    	  case MAC :
		  switch(listaProductos.nacionalidad)
			  {
			  case EEUU:
				  printf("Id:%d - MAC - EEUU -  '%s.' -  Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  case CHINA:
				  printf("Id:%d - MAC - CHINA -  '%s.' -  Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  case OTRO:
				  printf("Id:%d - MAC - OTRO -  '%s.' -  Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  }
    	  break;
    	  case IPAD :
		  switch(listaProductos.nacionalidad)
			  {
			  case EEUU:
				  printf("Id:%d - IPAD - EEUU - '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  case CHINA:
				  printf("Id:%d - IPAD - CHINA -  '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  case OTRO:
				  printf("Id:%d - IPAD - OTRO - '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  }
          break;
    	  case ACCSESORIOS :
		  switch(listaProductos.nacionalidad)
			  {
			  case EEUU:
				  printf("Id:%d - ACCSESORIO - EEUU - '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  case CHINA:
				  printf("Id:%d - ACCSESORIO - CHINA - '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  case OTRO:
				  printf("Id:%d - ACCSESORIO - OTRO - '%s.' - Precio: USD%.2f\n", listaProductos.idProducto, listaProductos.descripcion, listaProductos.precio );
			  break;
			  }
    	  break;
    	  }
      }
}
