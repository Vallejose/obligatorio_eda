//Estructura de datos y algoritmos - curso 2023
//Tecnologo en informatica FING - DGETP - UTEC

//Trabajo obligatorio
//archivo.c
//Modulo de implementacion de archivo.

#include <tring.h>
#include <iostream.h>
#include "definiciones.h"

using namespace std;

struct _archivo{
	Cadena nombre;
	Cadena exten;
	bool escritura;
	//contenido contenido; //Implemetar
};


archivo Crear_archivo(Cadena nombre, Cadena exten){
//Retorna un archivo de nombre archivo y extencion ext
	archivo ar = new(_archivo);
	ar->nombre = new char[MAX_NOMBRE];
	stpcpy(ar->nombre, nombre);
	ar->exten = new char(MAX_EXT];
	strcpy(ar->exten,exten;
	ar->escritura = true
	//ar->contenido = ??
	return ar;
}