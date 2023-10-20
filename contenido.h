#ifndef CONTENIDO_H
#define CONTENIDO_H

#include "definiciones.h"
//Estructura de datos y algoritmos - curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// contenido.h
// Modulo de Definición de contenido.


typedef struct nodo_contenidio * contenido;

contenido Null_contenido();
// Retorna uncontenido vacio

contenido Return_contenido(contenido c);
//Retorna el contenido del objeto contenido c.


bool IsNull_contenido(contenido c);

/*
archivo Crear_contenido();
//Retorna un contenido para un archivo
*/

#endif