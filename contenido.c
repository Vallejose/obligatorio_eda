//Estructura de datos y algoritmos - curso 2023
//Tecnologo en informatica FING - DGETP - UTEC

//Trabajo obligatorio
//contenido.c
//Modulo de implementacion de contenido.

#include <string.h>
#include <iostream>
#include "definiciones.h"
#include "contenido.h"
#include "archivo.h"

using namespace std;

struct nodo_contenido{
	Cadena content;
};

contenido Null_contenido(){
// Retorna uncontenido vacio
	return NULL;
}

Cadena Retorna_contenido(contenido c){
//Retorna el contenido c.
	return c->content;
}

bool IsNull_contenido(contenido c){
//Retorna true si el contenido es vacio y false en caso contrario
	return (c == NULL);
}

//Crear contenido
//Eliminar archivo

contenido Crear_contenido(){
//Retorna un contenido para un archivo
	contenido contAux = new(nodo_contenido);
	//Cadena aux = new char[MAX_CONT];
	contAux->content = new char[MAX_CONT];
	strcpy(contAux, "hola");
	return contAux;
}