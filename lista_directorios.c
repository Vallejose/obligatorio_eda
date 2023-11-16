// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorios.c
// Modulo de Implementacion de directorio.

#include "definiciones.h"
#include "lista_directorios.h"
#include "listArchivos.h"
#include "archivo.h"
#include "contenido.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_directorio_root{
    directorio root;
};


struct nodo_listDirect{
    directorio dir;
    lista_directorio siguiente;
};

struct nodo_directorio{
    Cadena nombre;
    list_archivos archs;
    lista_directorio internos;
};

//Funciones directorio root


// Funciones lista de directorios.

lista_directorio Null_lista_directorio(){
// Retorna una lista de directorios vacios.
    return NULL;
}

directorio Head_lista_directorios(lista_directorio ld){
//Retorna el directorio actual de la lista de directorios.
    return ld->dir;
}

lista_directorio Tail_lista_directorios(lista_directorio ld){
//Retorna la lista de directorios sin el primer directorio.
    return ld->siguiente;
}

bool IsEmpty_lista_directorio(lista_directorio ld){
//Retorna true si la lista de directorios es vacia y false en caso contrario.
    return (ld == NULL);
}

lista_directorio Crear_lista_directorio(){
//Retorna un directorio nuevo.
    lista_directorio ld = new(nodo_listDirect);
    ld->dir = NULL;
    ld->siguiente = NULL;
    return ld;
}

//Funciones directorio

directorio Null_directorio(){
//Retorna un directorio vacio.
    return NULL;
}

Cadena Nombre_directorio(directorio d){
//Retorna el nombre del directorio actual
    return d->nombre;
}

list_archivos Lista_archivos(directorio d){
//Retorna la lista de archivos de del directorio.
    return d->archs;
}

lista_directorio lista_directorios_internos(directorio d){
//Retorna la lista de directorios internos del directorio actual
    return d->internos;
}

directorio Crear_directorio(Cadena nombre){
//Crea un directorio vacio con el nombre que se le pasa
    directorio d = new(nodo_directorio);
    d->nombre = new char[MAX_NOMBRE];
    strcpy(d->nombre, nombre);
    d->archs = NULL;
    d->internos = NULL;
    return d;
}

directorio Insertar_lista_archivos(directorio d, list_archivos la){
//Inserta una lista de darchivos "la" en un directorio "d"
    d->archs = la;
    return d;
}

//Funciones que combinan las estructuras


bool Existe_directorio(lista_directorio ld, Cadena nombre){
//Retorna true si existe el directorio y false en caso contrario
    while(!IsEmpty_lista_directorio(ld)){
        Cadena nombreDir = Nombre_directorio(Head_lista_directorios(ld));
        if(strcmp(nombre,nombreDir) == 0)
            return true;
        ld = Tail_lista_directorios(ld);
    }
    return false;
}