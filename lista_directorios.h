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

typedef struct nodo_directorio_root * root;

typedef struct nodo_listDirect * lista_directorio;

typedef struct nodo_directorio * directorio;


// Funciones lista de directorios.

lista_directorio Null_lista_directorio();
// Retorna una lista de directorios vacios.

directorio Head_lista_directorios(lista_directorio ld);
//Retorna el directorio actual de la lista de directorios.

lista_directorio Tail_lista_directorios(lista_directorio ld);
//Retorna la lista de directorios sin el primer directorio.

bool IsEmpty_lista_directorio(lista_directorio ld);
//Retorna true si la lista de directorios es vacia y false en caso contrario.

lista_directorio Crear_lista_directorio();
//Retorna un directorio nuevo.

//Funciones directorio

directorio Null_directorio();
//Retorna un directorio vacio.

Cadena Nombre_directorio(directorio d);
//Retorna el nombre del directorio actual

list_archivos Lista_archivos(directorio d);
//Retorna la lista de archivos de del directorio.

lista_directorio lista_directorios_internos(directorio d);
//Retorna la lista de directorios internos del directorio actual

directorio Crear_directorio(Cadena nombre);
//Crea un directorio vacio con el nombre que se le pasa

directorio Insertar_lista_archivos(directorio d, list_archivos la);
//Inserta una lista de darchivos "la" en un directorio "d"

//Funciones que combinan las estructuras

bool Existe_directorio(lista_directorio ld, Cadena nombre);
//Retorna true si existe el directorio y false en caso contrario

#endif