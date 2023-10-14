#ifndef ARCHOIVO_H
#define ARCCHIVO_H

#include "definiciones.h"
//Estructura de datos y algoritmos - curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// archivo.h
// Modulo de Definición de archivo.


typedef struct _archivo * archivo;

archivo Crear_archivo(Cadena nombre, Cadena exten);
//Retorna un archivo de nombre archivo y extencion ext


#endif