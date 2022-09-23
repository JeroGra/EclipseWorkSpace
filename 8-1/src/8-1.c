/*
 ============================================================================
 Name        : 8-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char nombre[15];
	int golesMetidos;
	int partidosJugados;
	float promedioGoles;

}sJugador;

void getString(char nombre[], char mensaje[]);
sJugador cargarJugador();
void mostrarMensaje(sJugador jugador);
int pedirEntero(char mensaje[]);
float calcularPromedio(int goles,int partidos);

int main(void) {
	setbuf(stdout, NULL);
    sJugador jugadorUno;
    jugadorUno = cargarJugador();
    mostrarMensaje(jugadorUno);
	return EXIT_SUCCESS;
}


void getString(char nombre[], char mensaje[])
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]s",nombre);
}

int pedirEntero(char mensaje[])
{
	int entero;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%d", &entero);
	return entero;
}

sJugador cargarJugador()
{
	sJugador jugador;
	getString(jugador.nombre,"Coloque el nombre del jugador: \n");
	jugador.golesMetidos = pedirEntero("Coloque los goles metidos: \n");
	jugador.partidosJugados = pedirEntero("coloque los partidos jugados: \n");
	jugador.promedioGoles = calcularPromedio(jugador.golesMetidos,jugador.partidosJugados);
	return jugador;
}

float calcularPromedio(int goles,int partidos)
{
	float promedio;
	float golesF;     //declaracion de variables flotantes para poder hacer la operacion con flotantes y asi tener un resultado de tipo "0.Algo"
	float partidosF;

	golesF = goles;
	partidosF = partidos;

	promedio = golesF/partidosF;
	return promedio;
}

void mostrarMensaje(sJugador jugador)
{
	printf("\nNombre: %s\nGoles metidos: %d\nPartidos Jugados: %d\nPromedio de Goles: %.2f\n", jugador.nombre, jugador.golesMetidos, jugador.partidosJugados, jugador.promedioGoles);
}
