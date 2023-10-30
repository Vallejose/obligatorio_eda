// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// sistema.c
// Modulo de Implementacion del File System.


#include <string.h>
#include <iostream>
#include "sistema.h"
#include "directorio.h"
#include "listArchivos.h"
#include "archivo.h"
#include "contenido.h"

using namespace std;

struct _sistema{
	directorio raiz;
	directorio actual;
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
	
	list_archivos l_aux = listArchs(Dir_act(s));
	Cadena nomDir = Nombre_directorio(Dir_act(s));
	cout << nomDir << endl;
	if (IsEmpty_listArchivos(l_aux)){
		cout << "Directorio vacio\n";
	} else {
		if(parametro != NULL){
			while(l_aux != NULL){				
				Cadena nomAr = Nombre_archivo(Head_listArchivos(l_aux));
				Cadena extAr = Extension_archivo(Head_listArchivos(l_aux));
				cout << nomDir << "/";
				cout << nomAr << extAr << endl;
				l_aux = Tail_listArchivos(l_aux);
			}
		} else {
			while(l_aux != NULL){
				Cadena nomAr = Nombre_archivo(Head_listArchivos(l_aux));
				Cadena extAr = Extension_archivo(Head_listArchivos(l_aux));
				bool escr = Escritura_archivo(Head_listArchivos(l_aux));
				cout << nomAr << extAr << "   ";
				if (escr)
					cout << "Lecura/Escritura" << endl;
				else 
					cout << "Lectura" << endl;
				l_aux = Tail_listArchivos(l_aux);
			}
		}
	}
	return OK;
}

TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo){
// Crea un nuevo archivo en el directorio actual.
// Para mas detalles ver letra.
	
	directorio auxDir = Dir_act(s);
	list_archivos auxLa = listArchs(auxDir);
	bool extension = false;
	Cadena auxNom = Extraer_Nombre(nombreArchivo, extension);
	int tamNom = strlen(auxNom);
	
	if(tamNom > MAX_NOMBRE){
		cout << "Nombre demasiado largo"<<endl;
		return ERROR;
	} else if (!extension){
		cout<<"Falta extension del archivo"<<endl;
		return ERROR;
	} else {
		Cadena auxExt = Extraer_Ext(nombreArchivo);
		int tamExt = strlen(auxExt);
		if(tamExt > MAX_EXT){
			cout<<"Extension demasiado larga"<<endl;
			return ERROR;
		} else {
			if(IsEmpty_listArchivos(auxLa)){
				archivo auxA = Crear_archivo(auxNom, auxExt);	
				auxLa = Insert_listArchivos(auxA,auxLa);
				Insert_lista(auxLa, auxDir);
				s->actual = auxDir;
				s->raiz = auxDir;
				return OK;
			} else {
				if(existe_arch(auxLa, nombreArchivo)){
					cout << "nombre de archivo ya existente ";
					return ERROR;
				} else {
					archivo auxA = Crear_archivo(auxNom, auxExt);	
					auxLa = Insert_listArchivos(auxA,auxLa);
					Insert_lista(auxLa, auxDir);
					s->actual = auxDir;
					s->raiz = auxDir;	
					return OK;
				}
			}
		}
	}
}
	
bool existe_arch(list_archivos l, Cadena nombreAr){
	//Devuelve true si existe el archivo en la lista de archivos, false en caso contrario
	//Pre: lista no es vacia
	
	Cadena nombreEvaluar = Nombre_archivo(Head_listArchivos(l));
	if(strcmp(nombreEvaluar,nombreAr) == 0)
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
	directorio di_aux = Dir_act(s);
	list_archivos auxLis = listArchs(di_aux);
	int tamanTexto = strlen(texto);
	
	if(existe_arch(auxLis, nombreArchivo)){
		archivo ar_aux = buscar_archivo(auxLis, nombreArchivo);

		if(Escritura_archivo(ar_aux)){
			contenido auxCont = Contenido_Arch(ar_aux);
			Cadena cadCon;

			if(auxCont == NULL){
				cadCon = new char[MAX_CONT];

				if(tamanTexto > MAX_CONT){
					Cadena aux = add_chars(texto,0);
					strcpy(cadCon,aux);

				} else {
					strcpy(cadCon,texto);
				}
				
			}else{
				if(tamanTexto > MAX_CONT){
					Cadena aux = add_chars(texto,0);//Se le pasa cero por que es el espacio que esta utilizado
					cadCon = new char[MAX_CONT];//Se necesita inicializar la variable antes de copiar o concatenar.
					strcpy(cadCon,aux);
					
				}else if(tamanTexto == MAX_CONT){
					cadCon = new char[MAX_CONT];//Se necesita inicializar la variable antes de copiar o concatenar.
					strcpy(cadCon, texto);
					
				}else{
					cadCon = Retorna_cad_cont(auxCont);
					int txtYaIngresado = strlen(cadCon);
					//int espacioOcupado = MAX_CONT - tamanTexto; /*NO NECESITO HACER LA CUENTA LO OCUPADO ME LO DA EL COUNT DEL TEXTO A INGRESAT */
					Cadena auxDos = add_chars(cadCon,tamanTexto);
					strcpy(cadCon,texto);
					strcat(cadCon,auxDos);
					/*NO ES NECESARIO EL IF, YA SE QUE ME VAN A INGREAR TEXTO MENOR AL MAXIMO*/
					/*if(espacioLibre > 0){
						Cadena auxDos = add_chars(cadCon,espacioLibre);
						strcat(texto,auxDos);
						strcpy(cadCon,texto);
					}*/
				}
			}
			auxCont = Insertar_contenido(auxCont, cadCon);
			ar_aux = Insertar_cont_arch(ar_aux,auxCont);
			auxLis = Insert_listArchivos(ar_aux,auxLis);
			Insert_lista(auxLis,di_aux);
			s->actual = di_aux;
			s->raiz = di_aux;
			return OK;
		} else {
			cout <<"El archivo es solo de lectura, TARADO!"<<endl;
			return ERROR;
		}	
	} else {
		cout <<"No existe archivo con ese nombre en el directorio"<<endl;
		return ERROR;
	}
}

TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Agrega un texto al final del archivo NombreArchivo.
// Para mas detalles ver letra.
	directorio di_aux = Dir_act(s);
	list_archivos auxLis = listArchs(di_aux);
	
	if(existe_arch(auxLis, nombreArchivo)){
		archivo ar_aux = buscar_archivo(auxLis, nombreArchivo);
		if(Escritura_archivo(ar_aux)){
			contenido auxCont = Contenido_Arch(ar_aux);
			Cadena cadCon;
			if(auxCont == NULL){
				cadCon = new char[MAX_CONT];
				Cadena aux = add_chars(texto,0);
				strcpy(cadCon,aux);
			}else{
				cadCon = Retorna_cad_cont(auxCont);
				int largo = strlen(cadCon);
				Cadena aux = add_chars(texto,largo);
				strcat(cadCon, aux);
			}
			auxCont = Insertar_contenido(auxCont, cadCon);
			ar_aux = Insertar_cont_arch(ar_aux,auxCont);
			auxLis = Insert_listArchivos(ar_aux,auxLis);
			Insert_lista(auxLis,di_aux);
			s->actual = di_aux;
			s->raiz = di_aux;
			return OK;
		} else {
			cout <<"El archivo es solo de lectura, TARADO!"<<endl;
			return ERROR;
		}	
	} else {
		cout <<"No existe archivo con ese nombre en el directorio"<<endl;
		return ERROR;
	}
}

TipoRet DC (Sistema &s, Cadena nombreArchivo, int k){
// Elimina los a lo sumo K primeros caracteres del archivo parámetro.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet DF (Sistema &s, Cadena nombreArchivo, int k){
// Elimina los a lo sumo K últimos caracteres del archivo parámetro.
// Para mas detalles ver letra.
	directorio di_aux = Dir_act(s);
	list_archivos auxLis = listArchs(di_aux);

	if(existe_arch(auxLis, nombreArchivo)){
		archivo ar_aux = buscar_archivo(auxLis, nombreArchivo);
		if(Escritura_archivo(ar_aux)){
			contenido auxCont = Contenido_Arch(ar_aux);
			Cadena cadCon;
			if(auxCont == NULL){
				cout << "archivo vacio" << endl;
			}else{
				cadCon = Retorna_cad_cont(auxCont);
				int largo = strlen(cadCon);
				Cadena aux = del_chars(cadCon,k);
				strcpy(cadCon, aux);
				auxCont = Insertar_contenido(auxCont, cadCon);
				ar_aux = Insertar_cont_arch(ar_aux,auxCont);
				auxLis = Insert_listArchivos(ar_aux,auxLis);
				Insert_lista(auxLis,di_aux);
				s->actual = di_aux;
				s->raiz = di_aux;
			}
			return OK;
		} else {
			cout <<"El archivo es solo de lectura, TARADO!"<<endl;
			return ERROR;
		}	
	} else {
		cout <<"No existe archivo con ese nombre en el directorio"<<endl;
		return ERROR;
	}
	return NO_IMPLEMENTADA;
}

TipoRet TYPE (Sistema &s, Cadena nombreArchivo){
// Imprime el contenido del archivo parámetro.
// Para mas detalles ver letra.
	
	list_archivos list_aux = listArchs(Dir_act(s));
	if(existe_arch(list_aux, nombreArchivo)){
		archivo auxArch = buscar_archivo(list_aux, nombreArchivo);
		contenido auxCont = Contenido_Arch(auxArch);
		if(auxCont == NULL){
			cout << "No tiene contenido" <<endl;
			return ERROR;
		}else{
			Cadena auxCad = Retorna_cad_cont(auxCont);
			cout << auxCad <<endl;
		}
		return OK;
	} else{
		cout << "No exite un archivo con ese nombre en el directorio actual\n";
		return ERROR;
	}
}

archivo buscar_archivo(list_archivos l, Cadena nombreAr){
	//Devuelve un archivo de nombreAr, de una lista de archivos, NULL si no lo encuentra
	//Pre: lista no es vacia
	Cadena nombreEvaluar = Nombre_archivo(Head_listArchivos(l));
	archivo aux;
	
	if(strcmp(nombreEvaluar,nombreAr) == 0){
		aux = Head_listArchivos(l);
		return aux;
	}else if (Tail_listArchivos(l) == NULL)
		return NULL;	
	 else
		return buscar_archivo(Tail_listArchivos(l), nombreAr);
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