#include "ServiciosYMecanicos.h"
#include "FuncionesInputValidaciones.h"
void InicializarServicio(eServicio listaServicios[],int sizeS)
{
	for(int i = 0; i<sizeS;i++)
	{
		listaServicios[i].idServicio = 0;
		listaServicios[i].idMecanicoEncargado = 0;
		listaServicios[i].idDiagnostico = 0;
		listaServicios[i].estado = SIN_ASIGNAR;
	}
}

void ServicioHardcode(eServicio listaServicios[])
{
	eServicio servicioHard[7]={{1,"Martin",{10,07,2022},1,1,3000,ASIGNADO},{2,"Maria",{11,07,2022},2,2,2500,ASIGNADO},
			{5,"Tomas",{9,07,2022},3,3,1500,ASIGNADO},{9,"Ana",{30,06,2022},2,5,5000,ASIGNADO},{15,"Juan",{05,07,2022},0,0,0,ASIGNADO}
	,{19,"Matias Perez",{11,11,2022},1,2,3500,ASIGNADO},{20,"Belen Az",{20,2,2023},2,2,5000,ASIGNADO}};
    for(int i = 0;i<7;i++)
    {
    	listaServicios[i] = servicioHard[i];
    }
}
int BuscarEspacioOcupadoMasServicioDiagnosticado(eServicio listaServicios[], int sizeS)
{
	int respuesta;
	respuesta  = -1;
	for(int i = 0; i < sizeS; i++)
	{
		if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idDiagnostico != 0)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}
int BuscarEspacioLibre(eServicio listaServicios[], int sizeS)
{
	int respuesta;
	respuesta  = -1;
	for(int i = 0; i < sizeS; i++)
	{
		if(listaServicios[i].estado == SIN_ASIGNAR)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}
int BuscarEspacioOcupadoSinDiagnosticar (eServicio listaServicios[], int sizeS)
{
	int respuesta;
		respuesta  = -1;
		for(int i = 0; i < sizeS; i++)
		{
			if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idDiagnostico < 1)
			{
				respuesta = i;
				break;
			}
		}
		return respuesta;

}
int BuscarEspacioOcupado(eServicio listaServicios[], int sizeS)
{
	int respuesta;
	respuesta  = -1;
	for(int i = 0; i < sizeS; i++)
	{
		if(listaServicios[i].estado == ASIGNADO)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}

eServicio CargarServicio(eServicio listaServicios[],int sizeS)
{
	eServicio Servicio;
	Servicio.idServicio = GeneradorId(listaServicios,sizeS);
	getString(Servicio.nombreCliente,"Coloque el nombre del cliente: \n",50);
	TrasnsformarNombres(Servicio.nombreCliente);

    Servicio.fecha.anio = getInt("Coloque el anio \n",2022,2023);
	Servicio.fecha.mes = getInt("Coloque el mes: \n",1,12);
	Servicio.fecha.dia = ValidarDiaFecha(Servicio.fecha.mes);

	Servicio.idDiagnostico = 0;
	Servicio.idMecanicoEncargado = 0;
	Servicio.cotizacion = 0;
	Servicio.estado = ASIGNADO;
	return Servicio;
}
int GeneradorId(eServicio listaServicios[], int sizeS)
{
	int nuevoId = 0;
	OrdenarPorIdMayor(listaServicios,sizeS);
	nuevoId = listaServicios[0].idServicio + 1;

     return nuevoId;
}
void OrdenarPorIdMayor(eServicio listaServicios[], int sizeS)
{
	eServicio auxiliar;

		for(int i = 0; i < sizeS-1; i++)
		{
			for(int j = i+1; j < sizeS;j++)
			{
				if(listaServicios[i].idServicio < listaServicios[j].idServicio)
				{
					auxiliar = listaServicios[i];
					listaServicios[i] = listaServicios[j];
					listaServicios[j] = auxiliar;
				}
			}
		}
}

void ordenarPorFecha(eServicio listaServicios[], int sizeS)
{
	eServicio auxiliar;
	for(int i = 0;i<sizeS-1;i++)
	{
		for(int j = i+1;j<sizeS;j++)
		{
			if(listaServicios[i].fecha.anio > listaServicios[j].fecha.anio)
			{
				auxiliar = listaServicios[i];
				listaServicios[i] = listaServicios[j];
				listaServicios[j] = auxiliar;
			}
			else
			{
				if(listaServicios[i].fecha.anio == listaServicios[j].fecha.anio)
				{
					if(listaServicios[i].fecha.mes > listaServicios[j].fecha.mes)
					{
						auxiliar = listaServicios[i];
						listaServicios[i] = listaServicios[j];
						listaServicios[j] = auxiliar;
					}
					else
					{
						if(listaServicios[i].fecha.mes == listaServicios[j].fecha.mes)
						{
							if(listaServicios[i].fecha.dia > listaServicios[j].fecha.dia)
							{
								auxiliar = listaServicios[i];
								listaServicios[i] = listaServicios[j];
								listaServicios[j] = auxiliar;
							}
						}

					}

				}
			}

		}

	}

}

int AltaServicio(eServicio listaServicios[],int sizeS)
{
	int respuesta = -1;
	respuesta = BuscarEspacioLibre(listaServicios,sizeS);
	if(respuesta != -1)
	{
		listaServicios[respuesta] = CargarServicio(listaServicios,sizeS);
	}
	return respuesta;
}
int DefinirMecanico(eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[], int sizeE)
{
	int idMecanico;
	int i;
	MostrarListaMecanicos(Mecanico,sizeM,especialidades,sizeE);
	idMecanico = getInt("Seleccione el mecanico colocando su id: \n",1,sizeM);
	 for( i = 0;i<sizeM;i++)
	  {
		  if(idMecanico == Mecanico[i].id)
		  {
			  break;
		  }
	  }

	  while(idMecanico != Mecanico[i].id)
	  {
		  idMecanico = getInt("ERROR, Coloque el id del mecanico: \n",1,sizeM);
		  for( i = 0;i<sizeM;i++)
		   {
		 	  if(idMecanico == Mecanico[i].id)
		 	  {
		 		  break;
		 	  }
		   }
	  }
	return idMecanico;
}
int DefinirEspecialidad(eEspecialidad especialidades[], int sizeE)
{
	int idEspecialidad;
	int i;

	printf("--Especialidades--\n");
		for(int e = 0;e<sizeE;e++)
		{
			printf("Id: %d -- %s\n",especialidades[e].id,especialidades[e].especialidad);
		}
	idEspecialidad = getInt("Seleccione la especialidad colocando su id: \n",1,sizeE);
	 for( i = 0;i<sizeE;i++)
	  {
		  if(idEspecialidad == especialidades[i].id)
		  {
			  break;
		  }
	  }

	  while(idEspecialidad != especialidades[i].id)
	  {
		  idEspecialidad = getInt("ERROR, Coloque el id del mecanico: \n",1,sizeE);
		  for( i = 0;i<sizeE;i++)
		   {
		 	  if(idEspecialidad == especialidades[i].id)
		 	  {
		 		  break;
		 	  }
		   }
	  }
	return idEspecialidad;
}
void MostrarListaMecanicosSinServicios(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[], int sizeE)
{
	int bandera;
	for(int j = 0; j<sizeM;j++)
	{

			bandera = 0;
			for(int i = 0;i<sizeS;i++)
			{
				if(Mecanico[j].id == listaServicios[i].idMecanicoEncargado)
				{
					bandera = 1;
				}
			}
			if(bandera == 0)
			{
				for(int e = 0;e<sizeE;e++)
				{
					if(Mecanico[j].idEspecialidad == especialidades[e].id)
					{
				    printf("-- Id: %d -- Mecanico: %s -- Especialidad: %s --\n",Mecanico[j].id,Mecanico[j].nombre,especialidades[e].especialidad);
					}
				}
			}
	}
}
void MostrarListaMecanicos(eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[], int sizeE)
{
	for(int i = 0; i<sizeM;i++)
	{
		for(int j = 0; j<sizeE;j++)
		{
			if(Mecanico[i].id > 0 && Mecanico[i].idEspecialidad == especialidades[j].id)
			{
			   printf("-- Id: %d -- Mecanico: %s -- Especialidad: %s --\n",Mecanico[i].id,Mecanico[i].nombre,especialidades[j].especialidad);
			}
		}
	}

}

int ModificarServicio(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
  int respuesta = -1;
  int idServicio;
  int menuOpcion;
  int bandera;
  	respuesta = BuscarEspacioOcupadoMasServicioDiagnosticado(listaServicios,sizeS);
  	if(respuesta != -1)
  	{
  		MostrarListaServiciosDiagnosticados(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
  		idServicio = BuscarServicioPorIdSinDiagnosticar(listaServicios,sizeS);
  		do{
  			menuOpcion = getIntMasIntentos("--Menu De Cambios--\n"
  	    		            "1.Nombre de cliente-\n"
  	    		            "2.Fecha de servicio-\n"
  	    		            "3.Mecanico-\n"
  	    		            "4.Salir-\n"
  	    		            "Elija un aopcion: \n",1,4,3,0);
  			if(menuOpcion > 0 && menuOpcion < 4 )
  			{
  				bandera = 1;
  			}
			switch(menuOpcion)
			{
			case 1:
				getString(listaServicios[idServicio].nombreCliente,"Coloque el nombre del cliente: \n",50);
				TrasnsformarNombres(listaServicios[idServicio].nombreCliente);
				printf("Modificacion realizada\n");
			break;
			case 2:
                listaServicios[idServicio].fecha.anio = getInt("Coloque el anio \n",2022,2023);
                listaServicios[idServicio].fecha.mes = getInt("Coloque el mes: \n",1,12);
                listaServicios[idServicio].fecha.dia = ValidarDiaFecha(listaServicios[idServicio].fecha.mes);
				printf("Modificacion realizada\n");
			break;
			case 3:
				listaServicios[idServicio].idMecanicoEncargado = DefinirMecanico(Mecanico,sizeM,especialidades,sizeE);
				printf("Modificacion realizada\n");
			break;
			case 4:
				printf("Saliendo...\n");
				if(bandera != 1)
				{
					printf("No se modifico nada\n");
				}
			break;
			}
  		}while(menuOpcion != 4);
  	}

  return respuesta;
}
int BuscarServicioPorId(eServicio listaServicios[], int sizeS)
{
  int idServicio;
  int i;
  int index;
  idServicio = getInt("Coloque el id del servicio: \n",1,sizeS);
  for( i = 0;i<sizeS;i++)
  {
	  if(idServicio == listaServicios[i].idServicio  && listaServicios[i].estado != SIN_ASIGNAR)
	  {
		  index = i;
		  break;
	  }
  }


  while(idServicio != listaServicios[i].idServicio)
  {
	  idServicio = getInt("ERROR, Coloque el id del servicio: \n",1,sizeS);
	  for( i = 0;i<sizeS;i++)
	   {
	 	  if(idServicio == listaServicios[i].idServicio  && listaServicios[i].estado != SIN_ASIGNAR)
	 	  {
	 		  index = i;
	 		  break;
	 	  }
	   }
  }
  return index;
}
int BuscarServicioPorIdSinDiagnosticar(eServicio listaServicios[], int sizeS)
{
  int idServicio;
  int i;
  int index;
  idServicio = getInt("Coloque el id del servicio: \n",1,sizeS);
  for( i = 0;i<sizeS;i++)
  {
	  if(idServicio == listaServicios[i].idServicio && listaServicios[i].idDiagnostico > 0  && listaServicios[i].estado == ASIGNADO)
	  {
		  index = i;
		  break;
	  }
  }


  while(idServicio != listaServicios[i].idServicio)
  {
	  idServicio = getInt("ERROR, Coloque el id del servicio: \n",1,sizeS);
	  for( i = 0;i<sizeS;i++)
	   {
	 	  if(idServicio == listaServicios[i].idServicio && listaServicios[i].idDiagnostico > 0  && listaServicios[i].estado == ASIGNADO)
	 	  {
	 		  index = i;
	 		  break;
	 	  }
	   }
  }
  return index;
}
void MostrarListaServicios(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[],int sizeE)
{
	for(int i = 0; i <sizeS; i++)
	{
		if(listaServicios[i].estado == ASIGNADO)
		{
			CompararFKconPK(listaServicios[i],Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
		}
	}
}
void MostrarListaServiciosDiagnosticados(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	for(int i = 0; i <sizeS; i++)
	{
		if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idDiagnostico >0)
		{
			CompararFKconPKDiagnosticado(listaServicios[i],Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
		}
	}
}
void CompararFKconPK(eServicio listaServicios,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	int mecanicoEsIgual;
	int j;
	int e;
	int especialidadIgual;


	for(j = 0; j < sizeM; j++)
	{
			if(listaServicios.idMecanicoEncargado == Mecanico[j].id)
			{
			   mecanicoEsIgual = 1;
			   break;
			}
	}

	for(e = 0;e<sizeE;e++)
	{
		if(especialidades[e].id == Mecanico[j].idEspecialidad)
		{
			especialidadIgual = 1;
			break;

		}

	}

	if(mecanicoEsIgual == 1 && especialidadIgual == 1)
	{
		for(int z = 0; z<sizeD; z++)
		{
		   if(listaServicios.idDiagnostico == Diagnostico[z].id)
		   {
			   MostrarServicio(listaServicios,Mecanico[j],Diagnostico[z],especialidades[e]);
			   break;
		   }
		}
	}
}
void CompararFKconPKDiagnosticado(eServicio listaServicios,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	int mecanicoEsIgual;
		int j;
		int e;
		int especialidadIgual;

	for(j = 0; j< sizeM; j++)
	{

			if(listaServicios.idMecanicoEncargado > 0 && listaServicios.idMecanicoEncargado == Mecanico[j].id)
			{
			   mecanicoEsIgual = 1;
			   break;
		}
	}

	for(e = 0;e<sizeE;e++)
	{
		if(especialidades[e].id == Mecanico[j].idEspecialidad)
		{
			especialidadIgual = 1;
			break;

		}

	}

	if(mecanicoEsIgual == 1 && especialidadIgual == 1)
	{
		for(int z = 0; z<sizeD; z++)
		{
		   if(listaServicios.idDiagnostico > 0 && listaServicios.idDiagnostico == Diagnostico[z].id)
		   {
			   MostrarServicio(listaServicios,Mecanico[j],Diagnostico[z],especialidades[e]);
			   break;
		   }
		}
	}
}
void CompararFKconPKNoDiagnosticados(eServicio listaServicios,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	int mecanicoEsIgual;
		int j;
		int e;
		int especialidadIgual;



			for(j = 0; j < sizeM; j++)
			{
				if(listaServicios.idMecanicoEncargado == Mecanico[j].id)
				{
				   mecanicoEsIgual = 1;
				   break;
				}
			}

			for(e = 0;e<sizeE;e++)
			{
				if(especialidades[e].id == Mecanico[j].idEspecialidad)
				{
					especialidadIgual = 1;
					break;

				}

			}


		if(mecanicoEsIgual == 1 && especialidadIgual == 1)
		{
			for(int z = 0; z<sizeD; z++)
			{
			   if(listaServicios.idDiagnostico == 0 && listaServicios.idDiagnostico == Diagnostico[z].id)
			   {
				   MostrarServicio(listaServicios,Mecanico[j],Diagnostico[z],especialidades[e]);
				   break;
			   }
			}
		}
}
void MostrarServicio(eServicio listaServicios,eMecanico Mecanico,eDiagnosticos Diagnostico, eEspecialidad especialidades)
{
	printf("Id: %d -- Nombre: %s -- fecha: %d/%d/%d -- diagnostico: %s -- Mecanico: %s -- Especialidad: %s -- Cotizacion: $%.2f\n",
	listaServicios.idServicio,listaServicios.nombreCliente,listaServicios.fecha.dia,listaServicios.fecha.mes,
	listaServicios.fecha.anio,Diagnostico.tipo,Mecanico.nombre,especialidades.especialidad,listaServicios.cotizacion);
}

int BajaDeServicio(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	int respuesta = -1;
	int idServicio;
	respuesta = BuscarEspacioOcupado(listaServicios,sizeS);
	if(respuesta != -1)
	{
		MostrarListaServicios(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
		idServicio = BuscarServicioPorId(listaServicios,sizeS);
		listaServicios[idServicio].estado = SIN_ASIGNAR;
		listaServicios[idServicio].idDiagnostico = 0;
		listaServicios[idServicio].idMecanicoEncargado = 0;
		printf("Se dio de baja el servicio\n");
	}
	return respuesta;
}
int Diagnosticar(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	int respuesta = -1;
	int idM;
	int idS;
	respuesta = BuscarEspacioOcupadoSinDiagnosticar(listaServicios,sizeS);
	if(respuesta != -1)
	{
		 idM = DefinirMecanico(Mecanico,sizeM,especialidades,sizeE);
		 idS = BuscarServicioSinDiagnosticarPorId(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);

		 listaServicios[idS].idDiagnostico = CargarDiagnostico(Diagnostico,sizeD);
		 listaServicios[idS].idMecanicoEncargado = idM;
		 listaServicios[idS].cotizacion = getFloat("Coloque el precio del servicio; \n",1500,9000000);
		 printf("Diagnosticado!\n");
	}
	return respuesta;
}
void MostrarServicioNoDiagnosticado(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	for(int i = 0;i<sizeS;i++)
	{
		if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idDiagnostico == 0)
		{
			CompararFKconPKNoDiagnosticados(listaServicios[i],Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
		}
	}
}
int BuscarServicioSinDiagnosticarPorId(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD, eEspecialidad especialidades[], int sizeE)
{
	int idServicio;
	int i;
	int index;
	 MostrarServicioNoDiagnosticado(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
			 idServicio = getInt("Seleccione el servicio a diagnosticar: \n",1,sizeS);
			 for( i = 0;i<sizeS;i++)
				  {
					  if(idServicio == listaServicios[i].idServicio && listaServicios[i].idDiagnostico < 1  && listaServicios[i].estado != SIN_ASIGNAR)
					  {
						  index = i;
						  break;
					  }
				  }

				  while(idServicio != listaServicios[i].idServicio)
				  {
					  idServicio = getInt("ERROR, el servicio a diagnosticar: \n",1,sizeS);
					  for( i = 0;i<sizeS;i++)
					   {
						  if(idServicio == listaServicios[i].idServicio && listaServicios[i].idDiagnostico < 1 &&  listaServicios[i].estado != SIN_ASIGNAR)
						  {
							  index =i;
							  break;
						  }
					   }
				  }
	return index;
}
void MostrarListaDiagnosticos(eDiagnosticos Diagnostico[],int sizeD)
{
	for(int i = 0; i<sizeD;i++)
	{
		if(Diagnostico[i].id > 0)
		{
		printf("-- Id: %d -- Diagnosticos :%s --\n",Diagnostico[i].id,Diagnostico[i].tipo);
		}
	}
}
int CargarDiagnostico(eDiagnosticos Diagnostico[],int sizeD)
{
	int idDiagnostico;
	int i;
	MostrarListaDiagnosticos(Diagnostico,sizeD);
	idDiagnostico = getInt("Seleccione el diagnostico colocando su id: \n",1,sizeD);
	 for( i = 0;i<sizeD;i++)
	  {
		  if(idDiagnostico == Diagnostico[i].id)
		  {
			  break;
		  }
	  }

	  while(idDiagnostico != Diagnostico[i].id)
	  {
		  idDiagnostico = getInt("ERROR, Coloque el id del diagnostico: \n",1,sizeD);
		  for( i = 0;i<sizeD;i++)
		   {
		 	  if(idDiagnostico == Diagnostico[i].id)
		 	  {
		 		  break;
		 	  }
		   }
	  }
	return idDiagnostico;
}
void ColocarFechaCambioAceiteCotizacion(eServicio listaServicios[],int sizeS)
{
	 int anio,mes,dia;
	 int existeFecha = 0;
	 float cotizacionTotal = 0;

	 anio = getInt("Coloque el anio \n",2022,2023);
	 mes = getInt("Coloque el mes: \n",1,12);
	 dia = ValidarDiaFecha(mes);

	 for(int i = 0;i<sizeS;i++)
	 {
		 if(listaServicios[i].estado == ASIGNADO && listaServicios[i].fecha.anio == anio && listaServicios[i].fecha.mes == mes && listaServicios[i].fecha.dia == dia && listaServicios[i].idDiagnostico == ACEITE)
		 {
			 existeFecha = 1;
			 break;
		 }
	 }

	 if(existeFecha != 0)
	 {
		 printf("\n-- COTIZACION TOTAL EN CAMBIOS DE ACEITE --\n");

		 for(int i = 0;i<sizeS;i++)
		 {
			 if(listaServicios[i].estado == ASIGNADO && listaServicios[i].fecha.anio == anio && listaServicios[i].fecha.mes == mes && listaServicios[i].fecha.dia == dia && listaServicios[i].idDiagnostico == ACEITE)
			 {
				 cotizacionTotal =  cotizacionTotal+listaServicios[i].cotizacion;
			 }
		 }
		 printf("Cotizacion total: $%.2f en la Fecha: %d/%d/%d\n",cotizacionTotal,dia,mes,anio);
	 }
	 else
	 {
       printf("No existe servicio donde se cambio el aceite en esta fecha\n");
	 }
}

void CotizacionPromedioDeMecanico(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM)
{
	float promedio;
	float sumador ;
	float contador ;

	printf("\n-- COTIZACION PROMEDIO DE CADA MECANICO --\n");

	for(int j = 0;j<sizeM;j++)
	{
	    sumador = 0;
	    contador = 0;

		for(int i = 0;i<sizeS;i++)
		{
			if(listaServicios[i].estado == ASIGNADO && Mecanico[j].id == listaServicios[i].idMecanicoEncargado)
			{
				sumador = sumador+listaServicios[i].cotizacion;
				contador++;
			}
		}
		if(Mecanico[j].id != 0 && sumador > 0)
		{
		promedio = sumador/contador;
		printf("$%.2f es el promedio de cotizacion de %s -- su total sin promediar es: $%.2f\n",promedio,Mecanico[j].nombre,sumador);
		}
		else
		{
			if(Mecanico[j].id != 0 && sumador == 0)
			{
				printf("$%.2f es el promedio de cotizacion de %s\n",0.00,Mecanico[j].nombre);
			}
		}
	}
}

void MecanicosConMayorDiagnosticos(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM)
{
	int masDiagnosticos;
	int bandera = 1;
	int contador;
	for(int j = 0;j<sizeM;j++)
	{
		contador = 0;
		for(int i = 0;i<sizeS;i++)
		{
			if(listaServicios[i].estado == ASIGNADO && Mecanico[j].id == listaServicios[i].idMecanicoEncargado && Mecanico[j].id != 0)
			{
				contador++;
			}
		}
		if(bandera == 1 || contador > masDiagnosticos)
		{
			masDiagnosticos = contador;
			bandera = 0;
		}
	}

    printf("\n-- MECANICO/S CON MAYOR DIAGNOSTICOS --\n");
	for(int j = 0;j<sizeM;j++)
		{
			contador = 0;
			for(int i = 0;i<sizeS;i++)
			{
				if(listaServicios[i].estado == ASIGNADO && Mecanico[j].id == listaServicios[i].idMecanicoEncargado && Mecanico[j].id != 0)
				{
					contador++;
				}
			}
			if(contador == masDiagnosticos)
			{
				printf("-- Id: %d -- Mecanico: %s -- Diagnosticos totales: %d\n",Mecanico[j].id,Mecanico[j].nombre,masDiagnosticos);
			}
		}
}
void listarOrdenarPorEspecialidad(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	eEspecialidad auxiliar;
	for(int i = 0;i<sizeE-1;i++)
	{
		for(int j = i+1;j<sizeE;j++)
		{
			if(strcmp(especialidades[i].especialidad,especialidades[j].especialidad)>0)
			{
				auxiliar = especialidades[i];
				especialidades[i] = especialidades[j];
				especialidades[j] = auxiliar;
			}

		}
	}
	MostrarServiciosMasEspecilidadesOrdenadas(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
}
void MostrarServiciosMasEspecilidadesOrdenadas(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	printf("\n---SERVICIOS DIAGNOSTICADOS---\n");
	for(int e = 0;e<sizeE;e++)
		{
			for(int d = 0;d<sizeD;d++)
			{
				for(int i = 0;i<sizeS;i++)
				{
					for(int m = 0;m<sizeM;m++)
					{
						if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idMecanicoEncargado == Mecanico[m].id && listaServicios[i].idDiagnostico == Diagnostico[d].id && Mecanico[m].id != 0 && especialidades[e].id == Mecanico[m].idEspecialidad)
						{
						printf("Id: %d -- Nombre: %s -- fecha: %d/%d/%d -- diagnostico: %s -- Mecanico: %s -- Especialidad mecanico: %s -- Cotizacion: $%.2f\n",
						listaServicios[i].idServicio,listaServicios[i].nombreCliente,listaServicios[i].fecha.dia,listaServicios[i].fecha.mes,
						listaServicios[i].fecha.anio,Diagnostico[d].tipo,Mecanico[m].nombre,especialidades[e].especialidad,listaServicios[i].cotizacion);
						}
					}
				}
			}
		}
	    printf("\n---SERVICIOS SIN DIAGNOSTICAR---\n");
		for(int m = 0;m<sizeM;m++)
			{
				for(int d = 0;d<sizeD;d++)
				{
					for(int i = 0;i<sizeS;i++)
					{
						if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idMecanicoEncargado == Mecanico[m].id && listaServicios[i].idDiagnostico == Diagnostico[d].id && Mecanico[m].id == 0)
						{
							printf("Id: %d -- Nombre: %s -- fecha: %d/%d/%d -- diagnostico: %s -- Mecanico: %s --Especialidad mecanico: %s -- Cotizacion: $%.2f\n",
							listaServicios[i].idServicio,listaServicios[i].nombreCliente,listaServicios[i].fecha.dia,listaServicios[i].fecha.mes,
							listaServicios[i].fecha.anio,Diagnostico[d].tipo,Mecanico[m].nombre,"sin existencia",listaServicios[i].cotizacion);
						}
					}
				}
			}
}
void ServicosMarzoMayo2022Especialidades(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
 int idE;
 int bandera = 0;
 idE = DefinirEspecialidad(especialidades,sizeE);

 for(int i = 0;i<sizeS;i++)
	{
		for(int d = 0;d<sizeD;d++)
		{
			for(int m = 0;m<sizeS;m++)
			{
				if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idMecanicoEncargado == Mecanico[m].id && listaServicios[i].idDiagnostico == Diagnostico[d].id && Mecanico[m].idEspecialidad == idE && listaServicios[i].fecha.mes >= 3 && listaServicios[i].fecha.mes <=5 && listaServicios[i].fecha.anio == 2022)
				{
					bandera = 1;
				}
			}
		}
	}



  if(bandera != 0)
  {
	  printf("\n-- SERVICIOS DE MARZO A MAYO 2022 SEGUN ESPECIALIDAD --\n");

		for(int i = 0;i<sizeS;i++)
			{
				for(int d = 0;d<sizeD;d++)
				{
					for(int m = 0;m<sizeS;m++)
					{
						for(int e = 0;e<sizeM;e++)
						{
							if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idMecanicoEncargado == Mecanico[m].id && listaServicios[i].idDiagnostico == Diagnostico[d].id && especialidades[e].id == Mecanico[m].idEspecialidad && Mecanico[m].idEspecialidad == idE && listaServicios[i].fecha.mes >= 3 && listaServicios[i].fecha.mes <=5 && listaServicios[i].fecha.anio == 2022)
							{
							printf("Id: %d -- Nombre: %s -- fecha: %d/%d/%d -- diagnostico: %s -- Mecanico: %s -- Especialidad mecanico: %s -- Cotizacion: $%.2f\n",
							listaServicios[i].idServicio,listaServicios[i].nombreCliente,listaServicios[i].fecha.dia,listaServicios[i].fecha.mes,
							listaServicios[i].fecha.anio,Diagnostico[d].tipo,Mecanico[m].nombre,especialidades[e].especialidad,listaServicios[i].cotizacion);
							}
						}
					}
				}
			}
  }
  else
  {
     printf(""
    		"No hay servicios entre el mes de marzo y mayo,"
    		"\nRealizados por un mecanico con la especialidad seleccionada\n");
  }

}

void PorcentajeDiagnosticosDeCadaMecanico(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[],int sizeE)
{
    float contadorDiagnosticos = 0;
    float contadorMecanicos;
    float porcentajeDiagnosticos;
	for(int i = 0;i<sizeS;i++)
	{
		if(listaServicios[i].estado == ASIGNADO && listaServicios[i].idDiagnostico > 0)
		{
			contadorDiagnosticos++;
		}
	}

	printf("\n-- PORCENTAJE DE DIAGNOSTICOS DE CADA MECANICO --- DIAGNOSTICOS TOTALES: %.f --\n",contadorDiagnosticos);

	for(int m = 0;m<sizeM;m++)
	{
		porcentajeDiagnosticos = 0;
		contadorMecanicos = 0;
		for(int i = 0;i<sizeS;i++)
		{
			if(Mecanico[m].id == listaServicios[i].idMecanicoEncargado && Mecanico[m].id > 0)
			{
				contadorMecanicos++;

			}
		}

		if(Mecanico[m].id > 0)
		{
			porcentajeDiagnosticos = (contadorMecanicos*100)/contadorDiagnosticos;
			for(int e = 0;e<sizeE;e++)
			{
				if(Mecanico[m].idEspecialidad == especialidades[e].id)
				{
					printf("id: %d -- Nombre: %s -- Especialidad: %s -- Procentaje de diagnosticos: %.2f%c  \n",Mecanico[m].id,Mecanico[m].nombre,especialidades[e].especialidad,porcentajeDiagnosticos,37);
				}
			}

		}
	}

}
void EspecialidadesMasEstudidadas(eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[], int sizeE)
{
	int contadorE;
	int bandera = 0;
	int mayorE;

	for(int e = 0;e<sizeE;e++)
	{
		contadorE = 0;
		for(int m= 0; m<sizeM;m++)
		{
			if(Mecanico[m].idEspecialidad == especialidades[e].id &&  Mecanico[m].id > 0)
			{
				contadorE++;
			}
		}
		if(bandera == 0 || contadorE > mayorE )
		{
			mayorE = contadorE;
			bandera = 1;
		}

	}


	printf("\n--TOP 3 ESPECIALIDADES MAS ESTUDIADAS--\n");

	for(int e = 0;e<sizeE;e++)
		{
			contadorE = 0;


			for(int m= 0; m<sizeM;m++)
			{
				if(Mecanico[m].idEspecialidad == especialidades[e].id &&  Mecanico[m].id > 0)
				{
					contadorE++;
				}
			}
			if(contadorE == mayorE)
			{
				printf("-- Id: %d -- Especialidades: %s -- Cantidad de mecanicos que la estudiaron: %d\n",especialidades[e].id,especialidades[e].especialidad,contadorE);
			}

		}

	for(int e = 0;e<sizeE;e++)
			{
				contadorE = 0;


				for(int m= 0; m<sizeM;m++)
				{
					if(Mecanico[m].idEspecialidad == especialidades[e].id &&  Mecanico[m].id > 0)
					{
						contadorE++;
					}
				}
				if(contadorE == mayorE-1)
				{
					printf("-- Id: %d -- Especialidades: %s -- Cantidad de mecanicos que la estudiaron: %d\n",especialidades[e].id,especialidades[e].especialidad,contadorE);
				}

			}
	for(int e = 0;e<sizeE;e++)
			{
				contadorE = 0;


				for(int m= 0; m<sizeM;m++)
				{
					if(Mecanico[m].idEspecialidad == especialidades[e].id &&  Mecanico[m].id > 0)
					{
						contadorE++;
					}
				}
				if(contadorE == mayorE-2)
				{
					printf("-- Id: %d -- Especialidades: %s -- Cantidad de mecanicos que la estudiaron: %d\n",especialidades[e].id,especialidades[e].especialidad,contadorE);
				}

			}
}

int SubMenu(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE)
{
	int respuesta = -1;
	respuesta = BuscarEspacioOcupado(listaServicios,sizeS);
	if(respuesta != -1)
	{
		int menu;
		do{
			menu = getIntMasIntentos("\n--MENU OPCIONES--\n"
								     "1.Todos los mecanicos--\n"
									 "2.Todos los servicios--\n"
									 "3.Mecanicos libres--\n"
									 "4.Lista servicios ordenada por fecha mas antigua--\n"
									 "5.Cotizacion total en cambios de aceite en la fecha a ingresar--\n"
									 "6.Cotizacion promedio de cada mecanico--\n"
									 "7.Mecanico/Mecanicos con mayor cantidad de diagnosticos--\n"
									 "8.Lista de servicios ordenados por especialidad de mecanicos--\n"
									 "9.Lista de servicios de Marzo a Mayo 2022 para especialidad determinada--\n"
									 "10.Porcentaje de servicios diagnosticados de cada mecanico--\n"
									 "11.TOP 3 Mayores especialdiades estudiadas-\n"
									 "12.Salir-\n"
									 "-Elija una opcion: \n",1,12,3,0);
			switch(menu)
			{
			case 1:
				printf("\n-- LISTA MECANICOS TOTALES --\n");
				MostrarListaMecanicos(Mecanico,sizeM,especialidades,sizeE);
			break;
			case 2:
				printf("\n-- LISTA SERVICIOS TOTALES --\n");
				MostrarListaServicios(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
			break;
			case 3:
				printf("\n-- LISTA MECANICOS LIBRES --\n");
				MostrarListaMecanicosSinServicios(listaServicios,sizeS,Mecanico,sizeM,especialidades,sizeE);
			break;
			case 4:
				printf("\n-- LISTA SERVICIOS --\n");
				ordenarPorFecha(listaServicios,sizeS);
				MostrarListaServicios(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
			break;
			case 5:
				ColocarFechaCambioAceiteCotizacion(listaServicios,sizeS);
			break;
			case 6:
				CotizacionPromedioDeMecanico(listaServicios,sizeS,Mecanico,sizeM);
			break;
			case 7:
				MecanicosConMayorDiagnosticos(listaServicios,sizeS,Mecanico,sizeM);
			break;
			case 8:
				listarOrdenarPorEspecialidad(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
			break;
			case 9:
				ServicosMarzoMayo2022Especialidades(listaServicios,sizeS,Mecanico,sizeM,Diagnostico,sizeD,especialidades,sizeE);
			break;
			case 10:
				PorcentajeDiagnosticosDeCadaMecanico(listaServicios,sizeS,Mecanico,sizeM,especialidades,sizeE);
		    break;
			case 11:
				EspecialidadesMasEstudidadas( Mecanico,sizeM,especialidades,sizeE);
			break;
			case 12:
				printf("Volviendo al menu principal...\n");
			break;
			}
		}while(menu != 12);
	}
	return respuesta;
}

