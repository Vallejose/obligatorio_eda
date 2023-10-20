//Estructura de datos y algoritmos - curso 2023
//Tecnologo en informatica FING - DGETP - UTEC

//Trabajo obligatorio
//contenido.c
//Modulo de implementacion de contenido.

#include <string.h>
#include <iostream>
#include "definiciones.h"
#include "contenido.h"

using namespace std;

struct nodo_contenido{
	Cadena cont;
};

contenido Null_contenido(){
// Retorna uncontenido vacio
	return NULL;
}

Cadena Retorna_contenido(contenido c){
//Retorna el contenido c.
	return c->cont;
}

bool IsNull_contenido(contenido c){
//Retorna true si el contenido es cacion y false en caso contrario
	return (c == NULL);
}

//Crear contenido
//Eliminar archivo

/*
archivo Crear_contenido(){
//Retorna un contenido para un archivo
	contenido cont = new(nodo_contenido);
	cont->contenido = new char[MAX_CONT];
}*/