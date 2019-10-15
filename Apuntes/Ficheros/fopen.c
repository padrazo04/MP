#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *f;
	if((f=fopen("test.txt", "r"))==NULL){
		printf("El fichero %s no existe\n","test.txt");
		exit(-1);	//return 0;
	}
	else fclose(f);	
	return 0;
}