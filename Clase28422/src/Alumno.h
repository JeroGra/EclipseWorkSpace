#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
#define T 6
typedef struct
{
	int idCurso;
	char descripcion[200];
	int duracion;
}eCurso;
typedef struct
{
	int legajo;
	char nombre[20];
	float promedio;
	eCurso curso;
	int estado; // determina el estado de una estructura en el vector;
}eAlumno;

eAlumno PedirUnAlumno();


void MostrarUnAlumno(eAlumno miAlumno);//POR VALOR
int CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos);//POR REFERENCIA
void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos);
void OrdenarListaDeAlumnosPorNombre(eAlumno listaAlumnos[], int sizeAlumnos);
void OrdenarListaDeAlumnosPorNota(eAlumno listaAlumnos[], int sizeAlumnos);
void ListaAlumnosAprobados(eAlumno listaAlumnos[], int sizeAlumnos);
void ListaAlumnosHardcode(eAlumno listaAlumnos[]);
int ModificarAlumno(eAlumno listaAlumnos[],int sizeAlumnos);
int BajaAlumno(eAlumno listaAlumnos[],int sizeAlumnos);
