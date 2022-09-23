
#ifndef BBLIOTECAVALIDACION_H_
#define BBLIOTECAVALIDACION_H_
#include <stdio.h>
#include <stdlib.h>

/// @brief Recibe un entero que corresponde a los grados Fahrenheit y lo valida entre el punto de congelacion y ebullicion de dicha escala.
/// @param Mensaje por el cual se toma el entero.
/// @param rengo minimo de la validacion (Congelacion).
/// @param rango maximo de la validacion (Ebullicion).
/// @return devuleve el entero validado.
int ValidacionF(char[],int ,int);

/// @brief  Recibe un entero que corresponde a los grados Celsius y lo valida entre el punto de congelacion y ebullicion de dicha escala
/// @param  Mensaje por el cual se toma el entero.
/// @param  rengo minimo de la validacion (Congelacion).
/// @param  rango maximo de la validacion (Ebullicion).
/// @return devuleve el entero validado.
int ValidacionC(char[],int ,int);
#endif /* BBLIOTECAVALIDACION_H_ */
