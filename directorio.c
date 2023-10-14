// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.

#include "directorio.h"
#include "definiciones.h"
#include "archivo.h"


#include <string.h>


struct nodo_directorio{
	// directorios ver seg entrega
	archivos arch;
	Cadena nombre;
};

directorio Crear_Directorio(Cadena nombre){
// Retorna un directorio de nombre "nombre".
	directorio d = new(nodo_directorio);
	d->nombre = new char[MAX_NOMBRE];
	strcpy(d->nombre, nombre);
	d->archivos = NULL;
	return d;
}

archivos Crear_Archivos(){
	return NULL;
}

archivo Crear_Archivo(Cadena nombre, directorio direc_act){
	//Rertorna un archivo con el nombre 'nombre'.
	if(direc_act->archivos != NULL){
		if(direc_act->archivos->nombre != nombre && ){
			