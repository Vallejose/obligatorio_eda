#ifndef ARCHIVOS_H
#define ARCHIVOS_H

// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// archivos.h
// Modulo de Definición de Archivos.
#include "definiciones.h"
#include "archivo.h"
#include "contenido.h"
typedef struct nodo_listArchivos * list_archivos;

list_archivos Null_listArchivos();
//Retorna una lista de archivos vacia.


archivo Head_listArchivos(list_archivos ar);
//Retorna el el primer archivo de la lista de archivos
//Pre: ar no es vacia.


list_archivos Tail_listArchivos(list_archivos ar);
//Retorna la lista de archivos ar pero sin el primer elemento.
//Pre: ar no es vacia.


list_archivos Cons_listArchivos(archivo a, list_archivos ar);
//Inserta un archivo a al principio de ar


list_archivos Snoc_listArchivos(archivo a, list_archivos ar);
//Inserta un archivo al final de la lista de archivos.


list_archivos Insert_listArchivos(archivo a, list_archivos ar);
//Inserta un archivo de manera ordenada


 bool IsEmpty_listArchivos(list_archivos ar);
//Retorna true si ar es vacia y false en caso contrario;

bool existe_arch(list_archivos l, Cadena nombreAr);
	//Devuelve true si existe el archivo en la lista de archivos, false en caso contrario


#endif