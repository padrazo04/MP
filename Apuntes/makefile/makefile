# Fichero: makefile
# Construye "saludo.exe" a partir de "saludo.c"
# Incluye una regla sin lista de dependencia clean
saludo.exe: saludo.o
	@echo Creando saludo.exe...	# echo y no poner nada es lo mismo
	gcc saludo.c -o saludo.exe	# @echo se usa para informar de mensajes
saludo.o: saludo.c
	@echo Creando saludo.o solamente...
	gcc -c saludo.c
clean:
	@echo Borrando ficheros .o y .exe...
	rm *.o *.exe
