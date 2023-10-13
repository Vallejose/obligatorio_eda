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
	Cadena nombre[MAX_NOMBRE];
	Cadena ext[MAX_EXTENCION];
	bool lectura;
	bool escritura;
	//Falta ver el tema del contenidio??
	archivo siguiente;
	archivo actual;
};