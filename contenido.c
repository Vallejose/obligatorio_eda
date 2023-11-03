//Estructura de datos y algoritmos - curso 2023
//Tecnologo en informatica FING - DGETP - UTEC

//Trabajo obligatorio
//contenido.c
//Modulo de implementacion de contenido.

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"
#include "contenido.h"


using namespace std;

struct nodo_contenido{
	Cadena content;
};

contenido Null_contenido(){
// Retorna uncontenido vacio
	return NULL;
}

Cadena Retorna_cad_cont(contenido c){
//Retorna el contenido c.
	return c->content;
}

bool IsNull_contenido(contenido c){
//Retorna true si el contenido es vacio y false en caso contrario
	return (c == NULL);
}

contenido Insertar_contenido(contenido c, Cadena text){
//Dada una cadena de texto y un contenido c, inserta le texto en el contenido c
	contenido aux = new(nodo_contenido);
	aux->content = text;
	return aux;
}
	
Cadena add_chars(Cadena txtIngresar, int espacioUsado){
//Concatena la cadena existente de texto del contenido, 
//con el texto ingrado por el usuario hasta llegar al maximo permitido
	int espacioAUsar = strlen(txtIngresar);
	int espacioDisponible= MAX_CONT - espacioUsado;

	if(espacioAUsar <= espacioDisponible)
		return txtIngresar;
	else{
		Cadena ax = new char[MAX_CONT];
		for (int m=0; m<espacioDisponible; m++) {
			ax[m] = txtIngresar[m];
		}
		return ax;
	}
}
	
Cadena del_chars_end(Cadena txtborrar, int espacioLiberar){
//Elimina los n ultimos caracteres de una cadena de texto dada por el usuario
//Pre: La cadena no puede ser vacio
	int espacioUsado = strlen(txtborrar);
	int espacioDisponible= espacioUsado - espacioLiberar;
	
	if(espacioLiberar >= espacioUsado){
		Cadena ax = new char[MAX_CONT];
		return ax;
	}else{
		Cadena ax = new char[MAX_CONT];
		for (int m=0; m<espacioDisponible; m++) {
			ax[m] = txtborrar[m];
		}
	return ax;
	}
}


Cadena del_chars_init(Cadena txtborrar, int espacioLiberar){
//Elimina los n primeros de caracteres de una cadena de texto dada por el usuario
//Pre: La cadena no puede ser vacio
	int espacioUsado = strlen(txtborrar);
	int espacioDisponible= espacioUsado - espacioLiberar;
	
	if(espacioLiberar >= espacioUsado){
		Cadena ax = new char[MAX_CONT];
		return ax;
	}else{
		Cadena ax = new char[MAX_CONT];
		int i = 0;
		while(i<=espacioDisponible && i+espacioLiberar<= espacioUsado){
			ax[i] = txtborrar[i+espacioLiberar];
			i++;
		}
		/*
		for (int m=0; m<espacioDisponible; m++) {
			if()
			ax[m] = txtborrar[m+espacioLiberar];//Falta condicion de corte: sino se pasa del arreglo
		}*/
	return ax;
	}
}