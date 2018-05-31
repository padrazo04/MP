#include <stdio.h>

void leeVector(double *v, int *tope) {	//double *v es equivalente a double v[]
	printf("\n");
	for(int i=0; i<*tope; i++) {
		printf("Introduce el elemento %d del vector: ", i+1);
		scanf("%lf", (v+i));	//Con scanf debemos usar %lf en lugar de %f
	}							//Lo guarda en la direccion de memoria v+0, v+1, v+2, ...
}

void escribeVector(double *v, int *tope) {
	printf("\n");
	for(int i=0; i<*tope; i++)
		printf("Elemento %d:%.4f\n",i+1, *(v+i));	//Aqui si podremos utilizar %f
} 													//Con *(v+i) accedemos al contenido *(v+0), *(v+1),...

double sumaPositivos(double *v, int *tope) {
	double suma=0;
	for (int i=0; i<*tope; i++){
		if(*(v+i)>0)		//Si el contenido de v[i](ó *(v+i)) es mayor que 0 se sumará
			suma+=*(v+i);
	}
	return suma;
}

int main(int argc, char const *argv[])
{
	int n=5,opc=0;
	double test[n];
	while(opc!=4){
		printf("\nPulse para elegir una opcion:\n");
		printf("1. Introducir datos del vector\n");
		printf("2. Mostrar datos del vector\n");
		printf("3. Sumar los elementos mayores que 0\n");
		printf("4. Salir\nOPCION: ");
		scanf("%d", &opc);
		switch(opc){
			case 1: leeVector(test,&n);
				break;
			case 2: escribeVector(test,&n);
				break;
			case 3: printf("\nLa suma de los positivos es: %.4f\n",sumaPositivos(test, &n));
				break;
			case 4: printf("\nHasta luego Lucas\n");
				break;
			default: printf("\nIntroduzca una opcion correcta\n");
		}
	}
	return 0;
}
