//Estructura de datos y algoritmos - curso 2023
//Tecnologo en informatica FING - DGETP - UTEC

//Trabajo obligatorio
//contenido.c
//Modulo de implementacion de contenido.

#include <sring.h>
#include <iostream.h>
#include "definiciones.h"
#include "contenido.h"

using namespace std;

struct nodo_contenido{
	Cadena contenido;
};

contenido Null_contenido(){
// Retorna uncontenido vacio
	return NULL;
}

contenido Return_contenido(contenido c){
//Retorna el contenido del objeto contenido c.
	return c->contenido;
}

bool IsNull_contenido(contenido c){
//Retorna true si el contenido es cacion y false en caso contrario
	return (c == NULL);
}

//Crear contenido
//Eliminar archivo


archivo Crear_contenido(){
//Retorna un contenido para un archivo
	contenido cont = new(nodo_contenido);
	cont->contenido = new char[MAX_CONT];
}