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

struct nodo_archivo{
	Cadena nombreArchivo;
	Cadena ext;
	bool lectura;
	bool escritura;
	//Falta ver el tema del contenidio??
	archivo siguiente;
};

archivo Crear_Archivo(Cadena nombre){
	//Rertorna un archivo con el nombre 'nombre'.	
	
	archivo a = new(nodo_archivo);
	a->nombreArchivo = new char[MAX_NOMBRE];
	stpcpy(a->nombre, nombre);
	a->lectura = true;
	a->escritura = true;
	a->ext = '.txt';
	return a;
}
