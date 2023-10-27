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

contenido Insertar_contenido(contenido c, cadena text){
//
	Cadena cadAux = Retorna_contenido(c);
	if(cadAux == NULL){
		strcpy(cadAux, text);
	} else {
		
	}
	
	/*contenido contAux = new(nodo_contenido);
	//Cadena aux = new char[MAX_CONT];
	contAux->content = new char[MAX_CONT];
	*/
	strcpy(contAux, conten);
	return contAux;
}