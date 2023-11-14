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

archivo Crear_archivo(Cadena nombreArch, Cadena ext){
//Crea un archivo de nombre nombre, extencion exten, escritura true y contenido vacio
	
	archivo aux = new(_archivo);
	aux->nombre = new char[MAX_NOMBRE];
	strcpy(aux->nombre, nombreArch);
	aux->exten = new char[MAX_EXT];
	strcpy(aux->exten, ext);
	aux->escritura = true;
	aux->cont = NULL;
	return aux;
}

Cadena Extraer_Nombre(Cadena nomArchivo, bool &ext){
//Dada un nombre y la extension, retorna el nombre del archivo 
	int tamNombre = strlen(nomArchivo);
	Cadena nomAux = new char [MAX_NOMBRE];
	int iter = 0;
	
	do{
		nomAux[iter] = nomArchivo[iter];
		iter++;
	}while(nomArchivo[iter] != '.' && iter <= tamNombre);
	
	if(iter > tamNombre){
		ext = false;
	} else {
		ext = true;
	}
	
	return nomAux;
}

Cadena Extraer_Ext(Cadena nomArchivo){
//Dada un nombre y la extension, retorna la ext del archivo
//Pre: extension no puede ser vacia
	int tamNombre = strlen(nomArchivo);
	Cadena extAux = new char [MAX_EXT];
	int iter = 0, iterDos = 0;	
	bool guardar = false;
	
	while(iter <= tamNombre){
		if(nomArchivo[iter] == '.'){
			guardar = true;
		}
		if(guardar){
			extAux[iterDos] = nomArchivo[iter];
			iterDos++;
		}
		iter++;
	}
	return extAux;
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

archivo Insertar_cont_arch(archivo a, contenido c){
//Inserta un nodo contenido en un archivo
//Pre:el archivo y el contenido no pueden ser nulos
	archivo aux = a;
	aux -> cont = c;
	return aux;
}

Cadena nombre_y_extension_ar(archivo a){
	//Dado un archivo, retorna el nombre y la extension como una cadena 
	
	Cadena nomAux = a->nombre;
	Cadena extAux = a->exten;
	Cadena ret = strcat(nomAux, extAux);
	
	cout << "cadena ret: "<<ret<<endl;
	
	/*Cadena aux = new char[MAX_NOMBRE+MAX_EXT+1]; //El +1 es por el .
	for (int i=0; m < (MAX_NOMBRE+MAX_EXT+1); i++) {
		aux[i] = txtIngresar[m];
	}
	return ax;*/
	
	return ret;
}