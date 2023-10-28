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
	contenido aux = new(nodo_contenido);
	aux->content = text;
	cout << " agregue la cadena al contenido" << endl;
	return aux;
}
	
Cadena add_chars(Cadena txtIngresar, int espacioUsado){
	cout << "entre a add_chars"<<endl;
	int espacioAUsar = strlen(txtIngresar);
	int espacioDisponible= MAX_CONT - espacioUsado;
	cout << "espacio disponiblee: " << espacioDisponible<<endl;
	
	if(espacioAUsar <= espacioDisponible){
		cout << txtIngresar << endl;
		return txtIngresar;
	}else{
		Cadena ax = new char[MAX_CONT];

	for (int m=0; m<=espacioDisponible; m++) {
		ax[m] = txtIngresar[m];
		}
		cout << ax << endl;
	return ax;
	}
	
	
	//cout << ax << endl;
	//cout << xxxua << endl;


		
	
}