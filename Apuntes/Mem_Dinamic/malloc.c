#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int* p;
	if((p=(int*)malloc(5*sizeof(int)))==NULL)
	{
		printf("Error: no pudo asignarse memoria");
		exit(-1);
	}
	return 0;
}