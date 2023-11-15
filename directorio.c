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

using namespace std;


struct nodo_directorio{
	Cadena nombre;
	list_archivos archs;
	directorio dirInt;
	directorio dirSig;
};


directorio Null_directorio (){
//retorna un directorio vacio
	return NULL;
}

Cadena Nombre_directorio(directorio d){
//Retorna el nombre del directorio d
//Pre: d no es vacio
	return d->nombre;
}

directorio Insert_lista(list_archivos la, directorio dire){
//Inserta una lista de archivos en un directorioi
	dire->archs = la;
	return dire;
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
	
directorio Crear_Directorio(Cadena nombre){
// Retorna un directorio de nombre "nombre".
	printf("Estoy dentro de crear directorio \n");/// De prueba BORRAR antes de entregar
	directorio d = new(nodo_directorio);
	d->nombre = new char[MAX_NOMBRE];
	strcpy(d->nombre, nombre);
	d->archs = NULL;
	d->dirSig = NULL;
	d->dirInt = NULL;
	return d;
}

directorio Directorio_interno(directorio d){
//Devuelve la lista de directorios internos que tiene d.
	return d->dirInt;
}

directorio Directorio_siguiente(directorio d){
//Devuelve la lista de directorios siguientes de d sin el primer elemento.
	return d->dirSig;
}

bool Existe_dir(directorio d, Cadena nombreDir){
// Retorna true si encuentra un directorio con ese nombre y false en caso contrario.
	directorio dirAux = d;
	int compare;

	while(d->dirSig != NULL){
		compare = strcmp(nombreDir, d->nombre);
		if(compare == 0){
			return true;
		}
		d = d->dirSig;
	}
	return false;
}


directorio Insert_dir(directorio dInsrt, directorio d){

	directorio dirAux = d;
	directorio dirRet = Null_directorio();
	Cadena nomInsrt, nomDir;
	nomInsrt = Nombre_directorio(dInsrt);
	
	int resultComp;
	bool agregado = false;
	
	if(isEmpty_dir(d)){
		Snoc_Directorio(dInsrt,dirRet);		
	} else if (isEmpty_dir(Tail_directorio(d))){
		nomDir = Nombre_directorio(d);
		resultComp = strcmp(nomDir, nomInsrt);
		if(resultComp > 0){
			dirRet = Cons_Directorio(dInsrt, dirRet);
			dirRet = Snoc_Directorio(d, dirRet);
		} else if (resultComp < 0){
			dirRet = Cons_Directorio(d, dirRet);
		}
	} else {
		while(!isEmpty_dir(dirAux)){
			nomDir = Nombre_directorio(dirAux);
			resultComp = strcmp(nomDir, nomInsrt);
			if(resultComp > 0){
				if(!agregado){
					dirRet = Snoc_Directorio(dInsrt, dirRet);
					agregado = true;
				}
				dirRet = Snoc_Directorio(dirAux, dirRet);
			}else{
				dirRet = Snoc_Directorio(dirAux,dirRet);
				if(isEmpty_dir(Tail_directorio(d)))
				dirRet = Snoc_Directorio(dInsrt, dirRet);
			}
			dirAux  = dirAux->dirSig;
		}
	}
	return dirRet;
}

directorio Cons_Directorio(directorio dInsert, directorio d){
//Inserta un directorio al principio de una lista de directorios
	directorio dAux = new(nodo_directorio);
	dAux = dInsert;
	dAux->dirSig = d;
	return dAux;
}

directorio Snoc_Directorio(directorio dInsert, directorio d){
// Inserta un directorio al final de una lista de directorios.
	directorio dAux = new(nodo_directorio);
	directorio iter = d;
	dAux = dInsert;
	dAux->dirSig = NULL;
	while(iter != NULL && iter->dirSig != NULL){
		iter = iter->dirSig;

		if(isEmpty_dir(iter)){
			printf("Iter ests vacio \n");
		}else{
			printf("iter no es vacio  \n");
			if(isEmpty_dir(Tail_directorio(iter))){
				printf("el siguiente elemento es NULL  \n");
			}else{
				printf("el siguiente elemento no es NULL \n");
			}
		} 
		
	}

	if(iter == NULL){
		printf("Iter = NULL \n");
		return dAux;
	}else{
		printf("Estoy en el else \n");
		iter->dirSig = dAux;
		return d;
	}
	printf("Llega hasta aca la funcion?? \n");
}

directorio Tail_directorio(directorio d){
//Retorna una lista de directorios sin su primer elemento
//Pre: d no puede ser vacio
	return d->dirSig;
}
