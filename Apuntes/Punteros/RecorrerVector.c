#include <stdio.h>

int main(int argc, char const *argv[])
{
	int v[5]={0,1,2,3,4};
	int *ptr;
	ptr=v;
	printf("Dirección del primer elemento del vector: %p\n\n",ptr);

	for(int i=0; i<5; i++) {
		printf("elemento %d del vector: %d\n",i+1, v[i]);
		printf("Dirección del elemento %d del vector: %p\n", i+1, (v+i));
	}
	printf("---------------------------------------------------\n\n");
	for(int i=0; i<5; i++) {
		printf("elemento %d del vector: %d\n",i+1, ptr[i]);
		printf("Dirección del elemento %d del vector: %p\n", i+1, ptr+i);
	}
	printf("---------------------------------------------------\n\n");
	for(int i=0; i<5; i++) {
		printf("elemento %d del vector: %d\n",i+1, *(ptr+i));
		printf("Dirección del elemento %d del vector: %p\n", i+1, ptr+i);
	}
	printf("---------------------------------------------------\n\n");
	for(int i=0; i<5; i++) {
		printf("elemento %d del vector: %d\n",i+1, *(v+i));
		printf("Dirección del elemento %d del vector: %p\n", i+1, v+i);
	}
	printf("---------------------------------------------------\n\n");
	int *ptrfin=v+5;
	for(ptr=v; ptr<ptrfin; ptr++) {
		printf("elemento %d del vector: %d\n",*ptr+1, *ptr);
		printf("Dirección del elemento %d del vector: %p\n", *ptr+1, ptr);
	}
	printf("---------------------------------------------------\n\n");
	ptr=v;
	for(int i=0; i<5; i++) {
		printf("elemento %d del vector: %d\n",i+1, *ptr++);
		printf("Dirección del elemento %d del vector: %p\n", i+1, ptr);
	}
	printf("---------------------------------------------------\n\n");

	return 0;
}
