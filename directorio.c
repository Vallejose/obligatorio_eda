// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.

#include "directorio.h"
#include "definiciones.h"


#include <string.h>

struct nodo_directorio{
	// directorios ver seg entrega
	// archivos archs;
	Cadena nombre;
};

directorio Crear_Directorio(Cadena nombre){
// Retorna un directorio de nombre "nombre".
	directorio d = new(nodo_directorio);
	d->nombre = new char[MAX_NOMBRE];
	strcpy(d->nombre, nombre);
	return d;
}
