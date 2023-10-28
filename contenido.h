#ifndef CONTENIDO_H
#define CONTENIDO_H

#include "definiciones.h"

//Estructura de datos y algoritmos - curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// contenido.h
// Modulo de Definición de contenido.


typedef struct nodo_contenido * contenido;

contenido Null_contenido();
// Retorna un contenido vacio

Cadena Retorna_cad_cont(contenido c);
//Retorna el contenido del objeto contenido c.
//Pre: el contenido c no puede ser vacio.

bool IsNull_contenido(contenido c);
//retorna true si el contenido es vacio, false en caso contrario
//Cadena Crear_contenido();

contenido Insertar_contenido(contenido c, Cadena text);
//Dada una cadena de texto y un contenido c, inserta le texto en el contenido c


Cadena add_chars(Cadena txtIngresar, int espacioUsado);
//Concatena la cadena existente de texto del contenido, 
//con el texto ingrado por el usuario hasta llegar al maximo permitido


Cadena del_chars(Cadena txtborrar, int espacioLiberar);
//Elimina una n de caracteres de una cadena de texto dada por el usuario
//Pre: La cadena no puede ser vacio

#endif