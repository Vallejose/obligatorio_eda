// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// sistema.c
// Modulo de Implementacion del File System.

#include "contenido.h"
#include <string.h>
#include <iostream>
#include "sistema.h"
#include "directorio.h"
#include "listArchivos.h"
#include "archivo.h"


using namespace std;

struct _sistema{
	directorio raiz;
	directorio actual;
	// aquí deben figurar los campos que usted considere necesarios para manipular el sistema de directorios
	// Se deberan crear nuevos modulos
};



TipoRet CREARSISTEMA(Sistema &s){
// Inicializa el sistema para que contenga únicamente al directorio RAIZ, sin subdirectorios ni archivos.
// Para mas detalles ver letra.
	s = new(_sistema);
	Cadena nombre = new char[MAX_NOMBRE];
	strcpy(nombre, "RAIZ");
	s->raiz = Crear_Directorio(nombre);
	s->actual = s->raiz;
	return OK;
}

TipoRet DESTRUIRSISTEMA(Sistema &s){
// Destruye el sistema, liberando la memoria asignada a las estructuras que datos que constituyen el file system.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet CD (Sistema &s, Cadena nombreDirectorio){
// Cambia directorio. 
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}
	
TipoRet MKDIR (Sistema &s, Cadena nombreDirectorio){
// Crea un nuevo directorio. 
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet RMDIR (Sistema &s, Cadena nombreDirectorio){
// Elimina un directorio.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet MOVE (Sistema &s, Cadena nombre, Cadena directorioDestino){
// mueve un directorio o archivo desde su directorio origen hacia un nuevo directorio destino.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet DIR (Sistema &s, Cadena parametro){
// Muestra el contenido del directorio actual.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo){
// Crea un nuevo archivo en el directorio actual.
// Para mas detalles ver letra.

	/*if((Dir_act(s)) == s->actual){
		cout << nombreArchivo ;
		return OK;
	}else
		return ERROR;
	*/


	if(IsEmpty_listArchivos(listArchs(Dir_act(s)))){
		Cons_listArchivos(Crear_archivo(nombreArchivo), listArchs(Dir_act(s)));
		return OK;
	} else if (existe_arch(listArchs(Dir_act(s)), nombreArchivo)){	
		return ERROR;
	} else {
		Cons_listArchivos(Crear_archivo(nombreArchivo), listArchs(Dir_act(s)));
		return OK;
	}	
}

bool existe_arch(list_archivos l, Cadena nombreAr){
	//Devuelve true si existe el archivo en la lista de archivos, false en caso contrario
	//Pre: lista no es vacia
	
	if(Nombre_archivo(Head_listArchivos(l)) == nombreAr)
		return true;
	else if (Tail_listArchivos(l) == NULL)
		return false;
	else 
		return existe_arch(Tail_listArchivos(l), nombreAr);
}

TipoRet DELETE (Sistema &s, Cadena nombreArchivo){
// Elimina un archivo del directorio actual, siempre y cuando no sea de sólo lectura.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro){
// Agrega un texto al comienzo del archivo NombreArchivo.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet IC (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Agrega un texto al final del archivo NombreArchivo.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Agrega un texto al final del archivo NombreArchivo.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet DC (Sistema &s, Cadena nombreArchivo, int k){
// Elimina los a lo sumo K primeros caracteres del archivo parámetro.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet DF (Sistema &s, Cadena nombreArchivo, int k){
// Elimina los a lo sumo K últimos caracteres del archivo parámetro.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet TYPE (Sistema &s, Cadena nombreArchivo){
// Imprime el contenido del archivo parámetro.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet SEARCH (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Busca dentro del archivo la existencia del texto.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet REPLACE (Sistema &s, Cadena nombreArchivo, Cadena texto1, Cadena texto2){
// Busca y reemplaza dentro del archivo la existencia del texto1 por el texto2. 
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

directorio Dir_act(Sistema s){
//retorna el directorio actual del sistema s-
	return s->actual;
}


