// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// listArchivoso.c
// Modulo de Implementacion de directorio.

#include <string.h>
#include <iostream>
#include "definiciones.h"
#include "listArchivos.h"
#include "archivo.h"
#include "contenido.h"

using namespace std;

struct nodo_listArchivos{
	archivo archs;
	list_archivos siguiente;
};

list_archivos Null_listArchivos(){
//Retorna una lista de archivos vacia.
	return NULL;
}

archivo Head_listArchivos(list_archivos ar){
//Retorna el el primer archivo de la lista de archivos
//Pre: ar no es vacia.
	return ar->archs;
}

list_archivos Tail_listArchivos(list_archivos ar){
//Retorna la lista de archivos ar pero sin el primer elemento.
//Pre: ar no es vacia.
	return ar->siguiente;
}

list_archivos Cons_listArchivos(archivo a, list_archivos ar){
//Inserta un archivo a al principio de ar
	list_archivos aux = new(nodo_listArchivos);
	aux->archs = a;
	aux->siguiente = ar;
	return aux;
}


list_archivos Snoc(archivo a, list_archivos ar){
//Inserta un archivo al final de la lista de archivos.
	list_archivos auxAr = new(nodo_listArchivos);
	auxAr->archs = a;
	auxAr->siguiente = NULL;
	if(ar == NULL)
		return auxAr;
	else{
		list_archivos inicio = ar;
		while(inicio->siguiente != NULL)
			inicio = inicio->siguiente;
		inicio->siguiente = auxAr;
		return inicio;
	}
}


list_archivos Insert_listArchivos(archivo a, list_archivos ar){
//Inserta un archivo de manera ordenada, en una lista ordenada

	list_archivos listaAux = ar, listaRet;
	archivo archAux;
	Cadena nombreArch, nombreInsert;
	bool salir = false;
	cout << "Estoy dentro de la funcion" << endl;

	//Bloque if de testeo
	if(listaAux == NULL){
		cout << "listaAux es nula" << endl;
		listaRet=Cons_listArchivos(a, listaRet);
		//salir = true;
	}else
		cout << "La lista no es nula" << endl;

		if(listaRet == NULL){
		cout << "listaRet es nula" << endl;
	}else
		cout << "La lista no es nula" << endl;
	
	while(listaAux != NULL && !salir){
		cout << "While" << endl;
		archAux = Head_listArchivos(listaAux);
		nombreArch = Nombre_archivo(archAux);

		nombreInsert = Nombre_archivo(a);
		int resulrComp = strcmp(nombreArch,nombreInsert);

		if(resulrComp < 0 ){
			cout << "Resultado de la comparacion: "<< resulrComp << endl;
			if(listaRet == NULL){
				cout << "la lista es vacia" << endl;
				listaRet->archs = a;
				listaRet->siguiente = listaAux;
				salir = true;
			}else{
				cout << "La lista no es vacia" << endl;
				listaRet = Cons_listArchivos(a,listaRet);
				listaRet->siguiente = listaAux;
				salir = true;
			}
		}else{
			cout << "Resultado de la comparacion(No ordenada): "<< resulrComp << endl;
			listaRet = Snoc(archAux,listaRet);
		}
		listaAux = listaAux->siguiente;
	}
	cout << "Voy a retornar"<< endl;
	return listaRet;




	/*




	list_archivos aux = ar,listAux;
	archivo auxA;

	while (ar != NULL){
		auxA = Head_listArchivos(aux);
		Cadena nombArch = Nombre_archivo(auxA);

		Cadena nombInsert = Nombre_archivo(a);

		if(strcmp(nombArch,nombInsert) > 0 ){

			while(ar != NULL){

				if(strcmp(nombArch,nombInsert) > 0){ 
					if(listAux == NULL){
						auxA = Head_listArchivos(ar);
						listAux->archs = auxA;
						listAux->siguiente = ar;
					}else {
					auxA = Head_listArchivos(ar);
					}
				}



				ar = ar->siguiente;
			}

			cout << "esta ordenad "<<endl;
		}else{
			archivo archLista = Head_listArchivos(aux);
			listAux->archs = archLista;
			cout << "esta desordenad "<<endl;
		}

		aux = Tail_listArchivos(aux);
	}
	return ar;*/
}

 bool IsEmpty_listArchivos(list_archivos ar){
//Retorna true si ar es vacia y false en caso contrario;
	return(ar==NULL);
 }
 
 /*list_archivos Destruir_listArchivos(list_archivos ar){
//Destruye ar y libera la memoria asociada.
//De manera recursiva.
		if(ar == NULL)
			return ar;
		else{
			ar->siguiente = Destruir(ar->siguiente);
			delete ar;
		}
		return ar;
 }*/

list_archivos Crear_listArchivos(list_archivos a){ 
//Revisaro bien, nose si le tentgo que pasar parametros a la funcion y por que por referencia
//Inicializa la lista de archivos que contendra cada archivo
 	a = new(nodo_listArchivos);
	//a->archivo = Crear_archivo(nombre, exten);
	a->siguiente = NULL;
	return a;
}