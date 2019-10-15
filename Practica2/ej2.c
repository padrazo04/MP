#include <stdio.h>
#include <stdlib.h>

int num(int *v, int length, int num, int **mayor, int **menor) {	
	int cont1=0, cont2=0;			//Una función no puede devolver dos valores,
	for(int i=0; i<length; i++) { 	//pasamos por referencia
		if(v[i]>num)
			cont1++;				//Calculamos el tamaño del vector mayor y menor
		else cont2++;	
	}
	*mayor=(int *)malloc(cont1*sizeof(int));//Reservamos memoria para mayor y menor
	*menor=(int *)malloc(cont2*sizeof(int));//No olvidamos el casting ya que devuelve un void*
	cont1=cont2=0;
	for(int i=0; i<length; i++) {
		if(v[i]>num) {
			*(mayor)[cont1]=v[i];	
		//Un * porque es por referencia y otro para apuntar al contenido
			cont1++;
		} else {
			*(*(menor)+cont2)=*(v+i);			
			cont2++;
		}
	}
	return cont1;	//Este valor lo usaremos luego para imprimir por pantalla
}
int main(int argc, char const *argv[])
{
	int *test, *mayor, *menor, n, nelem;
	printf("Introduzca el numero de elementos del vector: ");
	scanf("%d",&nelem);

	test=(int *)malloc(nelem*sizeof(int));


	for(int i=0; i<nelem; i++){
		printf("Introduzca el elemento %d del vector: ",i+1);
		scanf("%d", &test[i]);
	}

	printf("Introduzca el valor a comparar: ");
	scanf("%d", &n);

	int cont=num(test, nelem, n, &mayor, &menor);	
	//Los pasamos por referencia ya que los tiene que devolver
	printf("\n");
	for(int i=0; i<cont; i++)
		printf("mayor[%d]: %d\n",i+1, mayor[i]);
	printf("\n");
	for(int i=0; i<nelem-cont; i++)
		printf("menor[%d]: %d\n",i+1, menor[i]);
	//INSERTE AQUÍ LIBERACIÓN DE MEMORIA
	return 0;
}