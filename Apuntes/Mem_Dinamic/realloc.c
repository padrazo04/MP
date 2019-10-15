#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *p;
	p=(int *)malloc(5*sizeof(int));
	for(int i=0; i<5; i++) {
		printf("Introduzca el valor %d: ",i+1);
		scanf("%d",p+i);
	}
	for(int i=0; i<5; i++) {
		printf("Valor %d: %d\n",i+1,p[i]);
		printf("Posicion %d: %p\n",i+1,&p[i]);
	}
	printf("\n");
	if((p=(int*)realloc(p, 2*5*sizeof(int)))==NULL)
	{
		printf("Error: no pudo asignarse memoria");
		exit(-1);
	}
	for(int i=0; i<10; i++) {
		printf("Valor %d: %d\n",i+1,p[i]);
		printf("Posicion %d: %p\n",i+1,&p[i]);

	}
}
