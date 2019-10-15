#include <stdio.h>

int potencia(int x, int p) {
	if (p==0)
		return 1;
	else
		return (x*potencia(x,p-1));
}

int main(){
	int a,b;
	printf("Introduce un numero: ");
	scanf("%d", &a);
	printf("Introduce un numero: ");
	scanf("%d", &b);
	printf("La potencia del numero es %d\n", potencia(a,b));
}
