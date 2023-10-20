#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include "definiciones.h"
#include "listArchivos.h"
#include "archivo.h"
#include "contenido.h"

// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.h
// Modulo de Definición de directorio.

typedef struct nodo_directorio * directorio;

directorio isNull ();
//retorna un directorio vacio

Cadena Nombre_directorio(directorio d);
//Retorna el nombre del directorio d
//Pre: d no es vacio

list_archivos listArchs(directorio d);
//Retorna una lista de archivos 
//Pre: el directorio no es vacio
	
bool isEmpty_dir(directorio d);
//Retorna true si d es vacio, false en caso contrario
/*
directorio eliminar_dir(directorio d);
//Destruye d y libera la memoria asociada*/

directorio Crear_Directorio(Cadena nombre);
// Retorna un directorio de nombre "nombre".


 /*bool IsEmpty_listArchivos(list_archivos ar);
//Retorna true si ar es vacia y false en caso contrario;
*/
#endif
