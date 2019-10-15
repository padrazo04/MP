#include <stdio.h>

struct punto {
	int x;
	int y;
};

void cambiaMal(int a, int b){
	int aux=a;
	a=b;
	b=aux;
}

void cambiaBien(int *a, int *b){		//De igual forma se pueden pasar estructuras
	int aux=*a;							//En C TODOS los parámetros se pasan por valor.
	*a=*b;
	*b=aux;
}

void funcion1(struct punto a);
void funcion2(struct punto *a);


int main(int argc, char const *argv[]) {
	struct punto c;
	c.x=0;
	c.y=0;
	int a=2, b=4;
	printf("Valor de a: %d\nValor de b: %d\n",a,b);
	cambiaMal(a,b);
	printf("CambiaMal --> a: %d\tb: %d\n",a,b);
	cambiaBien(&a,&b);					//El paso por referencia se simula mediante punteros
	printf("CambiaBien --> a: %d\tb: %d\n",a,b);
	funcion1(c);
	printf("Paso por valor de estructuras:\nX: %d\nY: %d\n", c.x, c.y);
	funcion2(&c);
	printf("Paso por referencia de estructuras:\nX: %d\nY: %d\n", c.x, c.y);
	return 0;
}

void funcion1(struct punto a){
	a.x=5;
	a.y=3;
}
void funcion2(struct punto *a){
	(*a).x=4;
	a->y=4;

}