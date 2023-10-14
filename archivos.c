// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.

#include "archivo.h"
#include "definiciones.h"

#include <string.h>

using namespace std;

struct nodo_archivos{
	archivo archivo;
	archivo siguiente;
};

archivos Crear_archivos(archivos &a){ 
//Revisaro bien, nose si le tentgo que pasar parametros a la funcion y por que por referencia
//Inicializa la lista de archivos que contendra cada archivo
	a = new(nodo_archivos);
	//a->archivo = Crear_archivo(nombre, exten);
	a->siguiente = a->archivo;
	return a;
}
	