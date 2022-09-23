#include <stdlib.h>
#include "Alumno.h"
#define C 3

int main(void) {
	setbuf(stdout, NULL);

	eAlumno listaAlumnos[T];//={{10,"Alberto",7.5},{99, "Jero", 9},{14,"Luis",5},{30,"Ana",9},{101,"Azul",3}};
	eCurso cursosDisponibles[C]={{1,"Cocina",6},{2,"Programacion",12},{3,"Mantenimiento de Pc",6}};
	int opcion;
	int retorno;

	for(int i = 0; i<T;i++)
	{
		listaAlumnos[i].estado = LIBRE;
	}

	ListaAlumnosHardcode(listaAlumnos);
	do
	{
		printf("1.Cargar\n2.Mostrar\n3.Ordenarn\n4.Ordenar por Nota\n5.Lista Aprobados\n6.Modificar Alumno\n7.Dar Baja\n10.Salir\nElija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				retorno = CargarListaDeAlumnos(listaAlumnos, T);
				switch(retorno)
				{
				 case -1:
				  printf("No hay espacio \n");
				 break;
				 default:
				   printf("Se cargo Alumno\n");
				  break;

				}
			break;
			case 2:
				MostrarListaDeAlumnos(listaAlumnos, T);
			break;
			case 3:
				OrdenarListaDeAlumnosPorNombre(listaAlumnos, T);
			break;
			case 4:
				OrdenarListaDeAlumnosPorNota(listaAlumnos, T);
		    break;
			case 5:
				ListaAlumnosAprobados(listaAlumnos, T);
			break;
			case 6:
				retorno = ModificarAlumno(listaAlumnos,T);
				switch(retorno)
				{
				 case -1:
				  printf("No Encontro el legajo\n");
				 break;
				 default:
				  printf("Se cargo nuevo promedio\n");
				 break;
				}

			break;
			case 7:
				retorno = BajaAlumno(listaAlumnos,T);
				switch(retorno)
				{
				 case -1:
				  printf("No Encontro el legajo\n");
				 break;
				 default:
				  printf("Se ELIMINO\n");
				 break;
				}
			break;
		}
	}while(opcion!=10);

	return EXIT_SUCCESS;
}

