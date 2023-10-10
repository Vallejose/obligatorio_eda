#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include "definiciones.h"

// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.h
// Modulo de Definición de directorio.

typedef struct nodo_directorio * directorio;

directorio Crear_Directorio(Cadena nombre);
// Retorna un directorio de nombre "nombre".


#endif
