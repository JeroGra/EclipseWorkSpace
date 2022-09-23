
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int direccion;
	char calle[50];
	char localidad[50];
	int codigoPostal;
}eDireccion;
typedef struct{

	int idProveedor;
	char razonSocial[50];
	eDireccion direcion;

}eProveedor;
typedef struct{

	int idProdcto;
	char descripcion[200];
	float precio;
	int idProveedor;


}eProducto;
// el producto tiene como FK la PK del proveedor , proveedor seria 1.* y el producto 1*1


typedef struct{

	char tipodeRaza[50];
	char carcacteristicas[200];

}eRaza;
typedef struct{
	int idDueño;
	char nombre[50];
	int edad;
	char sexo[10];

}eDueño;
typedef struct{

	int idMascota;
	char nombre[50];
	eRaza raza;
    char sexo[10];
    int idDueño;

}eMascota;
// La mascota tendria como FK el PK del dueño


typedef struct{

  int idLocalidad;
  char descripcion[200];
  int codigoPostal;

}eLocalidad;
typedef struct{
	int idAlumno;
	char nombre[50];
	int idLocalidad;

}eAlumno;
//El alumno tendria como FK el PK de la localidad

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
