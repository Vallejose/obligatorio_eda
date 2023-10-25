//Estructura de datos y algoritmos - curso 2023
//Tecnologo en informatica FING - DGETP - UTEC

//Trabajo obligatorio
//archivo.c
//Modulo de implementacion de archivo.

#include <string.h>
#include <iostream>
#include "definiciones.h"
#include "archivo.h"
#include "contenido.h"

using namespace std;

struct _archivo{
	Cadena nombre;
	Cadena exten;
	bool escritura;
	contenido cont; //Terminar de implemetar
};

archivo Null_archivo(){
//Retorna un archivo a vacio.
	return NULL;
}

Cadena Nombre_archivo(archivo a){
//Retorna el nombre del archivo a.
//Pre: a no es vacio.
	return a->nombre;
}

Cadena Extension_archivo(archivo a){
//Retorna la extencion del archivo a.
//Pre: a no es vacio.
	return a->exten;
}

bool Escritura_archivo(archivo a){
//Retorna true si se puede escribir el archivo y false en caso contrario
	return a->escritura;
}

archivo Crear_archivo(Cadena nombreArch){
//Crea un archivo de nombre nombre, extencion exten, escritura true y contenido vacio
	archivo aux = new(_archivo);
	aux->nombre = new char[MAX_NOMBRE];
	strcpy(aux->nombre, nombreArch);
	aux->exten = new char[MAX_EXT];
	strcpy(aux->exten, "txt");
	aux->escritura = true;
	aux->cont = NULL;
	return aux;
}

contenido Contenido_Arch(archivo a){
//Retorna el contenido del arcchivo a
	return a->cont;
}	
bool IsNull_archivo(archivo a){
// retorna true si el archivo a esta vacio y false en caso contrario
	return (a == NULL);
}

archivo Eliminar_archivo(archivo a){
//Elimina el archivo a y libera la memoria
	delete a;
	return a;
}




//contenido Contenido_archivo(archivo a)??