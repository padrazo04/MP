#include <stdio.h>
#include <math.h>	//Al compilar debemos teclear gcc -ej7.c -Wall -lm

int *leeVector(int *v, int n){
	for (int i = 0; i < n; ++i)
	{
		printf("Introduce el elemento %d del vector: ", i+1);
		scanf("%d", &v[i]); //(v+i)
	}
	return v;
}

void muestraVector(int *v, int n) {
	for (int i = 0; i < n; ++i)
		printf("v[%d]:\t%d\n", i+1, *(v+i));
}

void estadisticos(int *v, int n) {
	int sumamed=0, sumavar=0;
	float media=0, varianza=0, desv=0;
	for (int i = 0; i < n; i++) {
		sumamed+=*(v+i);
		sumavar+=pow(v[i],2);
	}
	media=sumamed/n;
	varianza=(sumavar/n)-pow(media,2);
	desv=sqrt(varianza);
	printf("Media: %.2f\nVarianza: %.2f\nDesviacion tipica: %.4f\n", media, varianza, desv);
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Introduce el numero de elementos del vector: ");
	scanf("%d", &n);
	int v[n];
	leeVector(v,n);
	muestraVector(v,n);
	estadisticos(v,n);
	return 0;
}
