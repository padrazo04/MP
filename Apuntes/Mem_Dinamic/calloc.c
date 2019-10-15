#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int* p;
	if((p=(int*)calloc(5,sizeof(int)))==NULL)
	{	//No olvidar el casting, porque la función devuelve un void *
		printf("Error: no pudo asignarse memoria");
		exit(-1);
	}
}