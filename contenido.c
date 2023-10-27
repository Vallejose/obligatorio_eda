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

//Crear contenido
//Eliminar archivo

contenido Insertar_contenido(contenido c, Cadena text){
//
	cout<<"Entre a insertar_contenido"<<endl;
	Cadena cadAux;
	
	if(c == NULL){
		cout<<"entre al if cadAux == NULL"<<endl;
		cadAux = new char[MAX_CONT];
		strcpy(cadAux, text);
		cout << "el texto ingresado fue: " << cadAux << endl;
		
		int l = strlen(cadAux);
		cout << "cant letras: "<< l << endl;
	} else {
		cadAux = Retorna_cad_cont(c);
		cout<<"cadAux = cadena de c"<<endl;
	}
	contenido cAux = new(nodo_contenido);
	//cAux = c;
	cout << " Cree variable contenido cAuz" << endl;
	cAux->content = cadAux;
	cout << " agregue la cadena al contenido" << endl;
	return cAux;
}

/*int cuenta_letras(Cadena cad){
//Cuenta la cantidad de letras del contenido
	int pos = 0;
	Cadena leer;
	
	strcpy(leer, cad);
	
	do{
		leer = getchar();
		pos++;
		
	}while(leer!='\0');
	
	cout << "pos = "<< pos <<endl;
	
	return pos;
}*/