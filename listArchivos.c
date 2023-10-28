// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// listArchivoso.c
// Modulo de Implementacion de directorio.

#include <string.h>
#include <iostream>
#include "definiciones.h"
#include "listArchivos.h"
#include "archivo.h"
#include "contenido.h"

using namespace std;

struct nodo_listArchivos{
	archivo archs;
	list_archivos siguiente;
};

list_archivos Null_listArchivos(){
//Retorna una lista de archivos vacia.
	return NULL;
}

archivo Head_listArchivos(list_archivos ar){
//Retorna el el primer archivo de la lista de archivos
//Pre: ar no es vacia.
	return ar->archs;
}

list_archivos Tail_listArchivos(list_archivos ar){
//Retorna la lista de archivos ar pero sin el primer elemento.
//Pre: ar no es vacia.
	return ar->siguiente;
}

list_archivos Cons_listArchivos(archivo a, list_archivos ar){
//Inserta un archivo a al principio de ar
	list_archivos aux = new(nodo_listArchivos);
	aux->archs = a;
	aux->siguiente = ar;
	return aux;
}

list_archivos Snoc_listArchivos(archivo a, list_archivos ar){
//Inserta un archivo al final de la lista de archivos.
	list_archivos auxAr = new(nodo_listArchivos);
	auxAr->archs = a;
	auxAr->siguiente = NULL;
	list_archivos iter = ar;

	while(iter != NULL && iter->siguiente != NULL){
		iter = iter->siguiente;
	}
	if(iter == NULL)
		return auxAr;
	else{
		iter->siguiente  = auxAr;
		return ar;
	}
}

// Revisoar
list_archivos Insert_listArchivos(archivo a, list_archivos ar){
//Inserta un archivo de manera ordenada, en una lista ordenada

	list_archivos listaAux = ar;
	list_archivos listaRet = Null_listArchivos();
	archivo archAux;
	Cadena nombreArch, nombreInsert;
	nombreInsert = Nombre_archivo(a);
	bool agregado = false;
	if(listaAux == NULL)
		listaRet = Cons_listArchivos(a, listaRet);
	else if(Tail_listArchivos(listaAux) == NULL){
		archAux = Head_listArchivos(listaAux);
		nombreArch = Nombre_archivo(archAux);
		int resultComp = strcmp(nombreArch,nombreInsert);
		if(resultComp >0){
			listaRet = Cons_listArchivos(a, listaRet);
			listaRet = Snoc_listArchivos(archAux,listaRet);
		} else if(resultComp == 0)
			listaRet = Snoc_listArchivos(a,listaRet);
		else {
			listaRet = Snoc_listArchivos(archAux, listaRet);
			listaRet = Snoc_listArchivos(a, listaRet);
		}
	} else {
		while(listaAux!=NULL){
			archAux = Head_listArchivos(listaAux);
			nombreArch = Nombre_archivo(archAux);
			int resultComp = strcmp(nombreArch,nombreInsert);
			if(resultComp > 0){
				if(!agregado){
					listaRet = Snoc_listArchivos(a, listaRet);
					agregado = true;
				} 
				listaRet = Snoc_listArchivos(archAux, listaRet);
			}else if(resultComp == 0){
				listaRet = Snoc_listArchivos(a,listaRet);
			}
			 else {
				listaRet = Snoc_listArchivos(archAux, listaRet);
				if(Tail_listArchivos(listaAux) == NULL)
					listaRet = Snoc_listArchivos(a,listaRet);
			}
			listaAux = listaAux->siguiente;
		}
	}
	return listaRet;
}

 bool IsEmpty_listArchivos(list_archivos ar){
//Retorna true si ar es vacia y false en caso contrario;
	return(ar==NULL);
 }