// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.

#include <string.h>
#include "definiciones.h"
#include "archivo.h"
#include "archivos.h"

using namespace std;

struct nodo_listArchivos{
	archivo archivo;
	archivo siguiente;
};

list_archivos Null_archivos(){
//Retorna una lista de archivos vacia.
	return NULL;
}

archivo Head_archivos(list_archivos ar){
//Retorna el el primer archivo de la lista de archivos
//Pre: ar no es vacia.
	return ar->archivo;
}

list_archivos Tail_archivos(list_archivos ar){
//Retorna la lista de archivos ar pero sin el primer elemento.
//Pre: ar no es vacia.
	return ar->siguiente;
}

list_archivos Cons(archivo a, list_archivos ar){
//Inserta un archivo a al principio de ar
	list_archivos aux = new(nodo_listArchivos);
	aux->archivo = a;
	aux->siguiente = ar;
	return aux;
}


 bool IsEmpty_archivos(list_archivos ar){
//Retorna true si ar es vacia y false en caso contrario;
	return(ar==NULL);
 }
 
 list_archivos Destruir(list_archivos ar){
//Destruye ar y libera la memoria asociada.
//De manera recursiva.
		if(ar == NULL)
			return ar;
		else{
			ar->siguiente = Destruir(ar->siguiente);
			delete ar;
		}
		return ar;
 }

list_archivos Crear_archivos(list_archivos a){ 
//Revisaro bien, nose si le tentgo que pasar parametros a la funcion y por que por referencia
//Inicializa la lista de archivos que contendra cada archivo
	a = new(nodo_listArchivos);
	//a->archivo = Crear_archivo(nombre, exten);
	a->siguiente = a->archivo;
	return a;
}