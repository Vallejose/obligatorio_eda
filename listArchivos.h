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

typedef struct nodo_listArchivos * list_archivos;


list_archivos Null_archivos();
//Retorna una lista de archivos vacia.


archivo Head_archivos(list_archivos ar);
//Retorna el el primer archivo de la lista de archivos
//Pre: ar no es vacia.


list_archivos Tail_archivos(list_archivos ar);
//Retorna la lista de archivos ar pero sin el primer elemento.
//Pre: ar no es vacia.



list_archivos Cons(archivo a, list_archivos ar);
//Inserta un archivo a al principio de ar


bool IsEmpty_archivos(list_archivos ar);
//Retorna true si ar es vacia y false en caso contrario;

 
list_archivos Destruir(list_archivos ar);
//Destruye ar y libera la memoria asociada.
//De manera recursiva.


list_archivos Crear_archivos(list_archivos a);
//Revisaro bien, nose si le tentgo que pasar parametros a la funcion y por que por referencia
//Inicializa la lista de archivos que contendra cada archivo


list_archivos Crear_archivos(list_archivos a);
//Revisaro bien, nose si le tentgo que pasar parametros a la funcion y por que por referencia
//Inicializa la lista de archivos que contendra cada archivo

#endif