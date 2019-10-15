#include <stdio.h>
#include "operaciones.h"

int main() {
	int num1=2;
	int num2=4;
	printf("La suma de %d y %d es %d\n", num1, num2, suma(num1, num2));
	printf("La resta de %d y %d es %d\n", num1, num2, resta(num1, num2));
	printf("El producto de %d y %d es %d\n", num1, num2, producto(num1, num2));
	printf("La división de %d y %d es %d\n", num2, num1, divisionEntera(num2, num1));
	printf("El factorial de %d es %d\n", num2, factorial(num2));
}
