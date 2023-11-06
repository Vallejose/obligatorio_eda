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

directorio Null_directorio ();
//retorna un directorio vacio

Cadena Nombre_directorio(directorio d);
//Retorna el nombre del directorio d
//Pre: d no es vacio

directorio Insert_lista(list_archivos la, directorio dire);
//Inserta una lista de archivos en un directorioi

list_archivos listArchs(directorio d);
//Retorna una lista de archivos 
//Pre: el directorio no es vacio
	
bool isEmpty_dir(directorio d);
//Retorna true si d es vacio, false en caso contrario

directorio Crear_Directorio(Cadena nombre);
// Retorna un directorio de nombre "nombre".

directorio Directorio_interno(directorio d);
//Devuelve la lista de directorios internos que tiene d.

directorio Directorio_siguiente(directorio d);
//Devuelve la lista de directorios siguientes de d sin el primer elemento.

bool Existe_dir(directorio d, Cadena nombreDir);
// Retorna true si encuentra un directorio con ese nombre y false en caso contrario.

directorio Cons_Directorio(directorio dInsert, directorio d);
//Inserta un directorio al principio de una lista de directorios

directorio Snoc_Directorio(directorio dInsert, directorio d);
// Inserta un directorio al final de una lista de directorios.





#endif
