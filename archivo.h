#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "definiciones.h"
#include "contenido.h"

//Estructura de datos y algoritmos - curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// archivo.h
// Modulo de Definición de archivo.


typedef struct _archivo * archivo;

archivo Null_archivo();
//Retorna un archivo a vacio.


Cadena Nombre_archivo(archivo a);
//Retorna el nombre del archivo a.
//Pre: a no es vacio.


contenido Contenido_Arch(archivo a);
//Retorna el contenido del arcchivo a


Cadena Extension_archivo(archivo a);
//Retorna la extencion del archivo a.
//Pre: a no es vacio.


bool Escritura_archivo(archivo a);
//Retorna true si se puede escribir el archivo y false en caso contrario


archivo Crear_archivo(Cadena nombreArch);
//Crea un archivo de nombre nombre, extencion exten, escritura true y contenido vacio


bool IsNull_archivo(archivo a);
// retorna true si el archivo a esta vacio y false en caso contrario


archivo Eliminar_archivo(archivo a);
//Elimina el archivo a y libera la memoria

#endif