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

	cout<<"Entre a insertar_contenido"<<endl;
	
	cout << " Cree variable contenido cAuz" << endl;
	c->content = text;
	cout << " agregue la cadena al contenido" << endl;
	return c;
}

Cadena add_chars(Cadena txtIngresar, int espacioUsado){
	cout << "entre a add_chars"<<endl;
	int espacioAUsar = strlen(txtIngresar);
	int espacioDisponible= MAX_CONT - espacioUsado;
	
	if(espacioDisponible >= espacioAUsar){
		cout<<"espacioDisponible >= espacioAUsar"<<endl;
		return txtIngresar;
	} else {
		Cadena auxChar = new char[espacioDisponible];
		strcpy(auxChar, txtIngresar);
		cout<<auxChar<<endl;
		
		return auxChar;
	}
}


