#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char *p;
	p=(char *)malloc(3*sizeof(char));
	for(int i=0; i<3; i++) {
		printf("Introduzca el valor %d: ",i+1);
		fgets(p+i, 3, stdin);
	}
	for(int i=0; i<3; i++) {
		printf("Valor %d: %c\n",i+1,p[i]);
		printf("Posicion %d: %p\n",i+1,&p[i]);
	}
	printf("\n");
	if((p=(char*)realloc(p, 2*3*sizeof(char)))==NULL)
	{
		printf("Error: no pudo asignarse memoria");
		exit(-1);
	}
	for(int i=0; i<6; i++) {
		printf("Valor %d: %c\n",i+1,p[i]);
		printf("Posicion %d: %p\n",i+1,&p[i]);

	}
}
