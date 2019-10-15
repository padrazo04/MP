# Comentario en Makefile
# Ejercicio 6 de la practica 4
# $@ hace referencia al destino. $^ hace referencia a las dependencias
# $< hace referencia a la primera dependencia
all: crucigrama.x
.PHONY: clean
DEBUG = -ggdb3
crucigrama.x: main.o ficheros.o crucigrama.o libMemoria.a
	@echo Creando el ejecutable crucigrama.x ...
	gcc DEBUG -o $@ $^
main.o: main.c crucigrama.h ficheros.h memoria.h
	@gcc -c main.c -Wall
ficheros.o: ficheros.c ficheros.h
	@gcc -c ficheros.c -Wall
crucigrama.o: crucigrama.c crucigrama.h
	@gcc -c $< -Wall
libMemoria.a: reservaMemoria.o liberaMemoria.o memoria.h
	@echo Creando la libreria libMemoria.a ...
	ar -rs libMemoria.a reservaMemoria.o liberaMemoria.o
reservaMemoria.o: reservaMemoria.c memoria.h
	@gcc -c reservaMemoria.c -Wall
liberaMemoria.o: liberaMemoria.c memoria.h
	@gcc -c liberaMemoria.c -Wall
clean:
	@echo Borrando todos los codigos objeto ...
	@rm *.o
