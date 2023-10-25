todo: main.o sistema.o directorio.o archivo.o listArchivos.o contenido.o
	g++ -o main main.o sistema.o directorio.o archivo.o listArchivos.o contenido.o
main.o: main.c
	g++ -c main.c
sistema.o: sistema.h sistema.c
	g++ -c sistema.c
directorio.o: directorio.h directorio.c
	g++ -c directorio.c
archivo.o: archivo.h archivo.c
	g++ -c archivo.c
listArchivos.o: listArchivos.h listArchivos.c
	g++ -c listArchivos.c
contenido.o: contenido.h contenido.c
	g++ -c contenido.c
limpiar:
	rm *.o
	rm main

