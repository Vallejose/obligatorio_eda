#ifndef CONTENIDO_H
#define CONTENIDO_H

#include "definiciones.h"
#include "archivo.h"
//Estructura de datos y algoritmos - curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// contenido.h
// Modulo de Definición de contenido.


typedef struct nodo_contenido * contenido;

contenido Null_contenido();
// Retorna un contenido vacio

Cadena Retorna_contenido(contenido c);
//Retorna el contenido del objeto contenido c.
//Pre: el contenido c no puede ser vacio.

bool IsNull_contenido(contenido c);
//retorna contenido
//Cadena Crear_contenido();

Cadena Crear_contenido();
//Retorna un contenido para un archivo


#endif