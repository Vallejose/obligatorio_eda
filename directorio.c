// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.
#include "definiciones.h"
#include "directorio.h"
#include "listArchivos.h"
#include "archivo.h"
#include "contenido.h"
#include <string.h>
#include <iostream>

struct nodo_directorio{
	// directorios ver seg entrega
	list_archivos archs;
	Cadena nombre;
};

directorio isNull (){
	//retorna un directorio vacio
	return NULL;
}

Cadena Nombre_directorio(directorio d){
	//Retorna el nombre del directorio d
	//Pre: d no es vacio
	return d->nombre;
}

list_archivos listArchs(directorio d){
	//Retorna una lista de archivos 
	//Pre: el directorio no es vacio
	return d->archs;
}
	
bool isEmpty_dir(directorio d){
	//Retorna true si d es vacio, false en caso contrario
	return(d == NULL);
}
/*directorio eliminar_dir(directorio d){
	//Destruye d y libera la memoria asociada
	if (d == NULL){
		return d;
	} else {
		delete d;
		return d;
	}
}*/	
directorio Crear_Directorio(Cadena nombre){
// Retorna un directorio de nombre "nombre".
	directorio d = new(nodo_directorio);
	d->nombre = new char[MAX_NOMBRE];
	strcpy(d->nombre, nombre);
	d->archs = NULL;
	return d;
}
 bool IsEmpty_listArchivos(list_archivos ar){
//Retorna true si ar es vacia y false en caso contrario;
	return(ar==NULL);
 }
 
