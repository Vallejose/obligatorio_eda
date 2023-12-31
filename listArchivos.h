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

list_archivos Snoc(archivo a, list_archivos ar);
//Inserta un archivo al final de la lista de archivos.

bool IsEmpty_listArchivos(list_archivos ar);

list_archivos Insert_listArchivos(archivo a, list_archivos ar);
//Inserta un archivo de manera ordenada, en una lista ordenada

//Retorna true si ar es vacia y false en caso contrario;

 
/*list_archivos Destruir_listArchivos(list_archivos ar);
//Destruye ar y libera la memoria asociada.
//De manera recursiva.*/


list_archivos Crear_listArchivos(list_archivos a);
//Revisaro bien, nose si le tentgo que pasar parametros a la funcion y por que por referencia
//Inicializa la lista de archivos que contendra cada archivo


list_archivos Crear_listArchivos(list_archivos a);
//Revisaro bien, nose si le tentgo que pasar parametros a la funcion y por que por referencia
//Inicializa la lista de archivos que contendra cada archivo

list_archivos Insert_listArchivos(archivo a, list_archivos ar);
//Inserta un archivo de manera ordenada

#endif