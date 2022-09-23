#include <string.h>
#include "Alumno.h"


eAlumno PedirUnAlumno()
{
	eAlumno miAlumno;

	printf("Ingrese el legajo: ");
	scanf("%d", &miAlumno.legajo);
	printf("Ingrese el nombre: ");
	fflush(stdin);
	gets(miAlumno.nombre);//scanf("%[^\n]", miAlumno.nombre); ... fgets
	printf("Ingrese el promedio: ");
	scanf("%f", &miAlumno.promedio);
	printf("Ingrese el Id del Curso: ");
    scanf("%d", &miAlumno.curso.idCurso);

	miAlumno.estado = OCUPADO;
	return miAlumno;
}
void ListaAlumnosHardcode(eAlumno listaAlumnos[])
{
	eAlumno auxiliar[5]={{10,"Alberto",7.5,{1},OCUPADO},{99, "Jero", 9,{1},OCUPADO},{14,"Luis",5,{2},OCUPADO},{30,"Ana",9,{3},OCUPADO},{101,"Azul",3,{3},OCUPADO}};
	for(int i = 0; i<5; i++)
	{
		listaAlumnos[i]=auxiliar[i];
	}
}
int BuscarEspacioLibre(eAlumno listaAlumnos[], int sizeAlumnos);
int BuscarEspacioLibre(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int index = -1;
	for(int i = 0; i < sizeAlumnos;i++)
	{
		if(listaAlumnos[i].estado == LIBRE)
		{
			index = i;
			break;
		}
	}
	return index;
}



int CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int index;
	index = BuscarEspacioLibre(listaAlumnos,sizeAlumnos);
	if(index != -1)
	{
		listaAlumnos[index] = PedirUnAlumno();
	}
	return index;
}
void MostrarUnAlumno(eAlumno miAlumno)
{
	if(miAlumno.estado == OCUPADO)
	{
	   printf("%4d %10s %4.2f %d\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio, miAlumno.curso);
	}
}

void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		MostrarUnAlumno(listaAlumnos[i]);
	}

}

void OrdenarListaDeAlumnosPorNombre(eAlumno listaAlumnos[], int sizeAlumnos)
{
	eAlumno auxiliarAlumno;
	for(int i = 0; i < sizeAlumnos-1; i++)
	{
		for(int j = i+1; j<sizeAlumnos; j++)
		{
			if(strcmp(listaAlumnos[i].nombre,listaAlumnos[j].nombre)<0)
			{
				auxiliarAlumno = listaAlumnos[i];
				listaAlumnos[i] = listaAlumnos[j];
				listaAlumnos[j] = auxiliarAlumno;
			}
		}
	}
}
void OrdenarListaDeAlumnosPorNota(eAlumno listaAlumnos[], int sizeAlumnos)
{
	eAlumno auxiliarAlumno;
	for(int i = 0; i < sizeAlumnos-1; i++)
	{
		for(int j = i+1; j<sizeAlumnos; j++)
		{
			if(listaAlumnos[i].promedio < listaAlumnos[j].promedio)
			{
				auxiliarAlumno = listaAlumnos[i];
				listaAlumnos[i] = listaAlumnos[j];
				listaAlumnos[j] = auxiliarAlumno;
			}
			else
			{
				if(listaAlumnos[i].promedio == listaAlumnos[j].promedio)
				{
				   if(strcmp(listaAlumnos[i].nombre,listaAlumnos[j].nombre)>0)
					{
						auxiliarAlumno = listaAlumnos[i];
						listaAlumnos[i] = listaAlumnos[j];
						listaAlumnos[j] = auxiliarAlumno;
					}
				}
			}
		}
	}
}

void ListaAlumnosAprobados(eAlumno listaAlumnos[], int sizeAlumnos)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].promedio > 5)
		{
			if(strcmp(listaAlumnos[i].nombre,"Jero")== 0) //listaAlumnos[i].nombre[0] == 'A'
			{
				 MostrarUnAlumno(listaAlumnos[i]);
			}
		}
	}
}

int ModificarAlumno(eAlumno listaAlumnos[],int sizeAlumnos)
{
	int confirmacion;
	int legajo;
	confirmacion = -1;
	printf("ingrese el Lejago a moficar: \n");
	scanf("%d", &legajo);
	for(int i = 0; i < sizeAlumnos;i++)
	{
		if(listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].legajo == legajo)
		{
			printf("Coloque el nuevo promedio: ");
			scanf("%f", &listaAlumnos[i].promedio);
			confirmacion = 1;
			break;
		}
	}
	return confirmacion;
}
int BajaAlumno(eAlumno listaAlumnos[],int sizeAlumnos)
{
	int elimino;
	int legajo;
	elimino = -1;
	printf("ingrese el Lejago a moficar: \n");
	scanf("%d", &legajo);
	for(int i = 0; i < sizeAlumnos;i++)
	{
		if(listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].legajo == legajo)
		{
			listaAlumnos[i].estado = LIBRE;
			elimino = 1;
			break;
		}
	}
	return elimino;

}


