#include <stdio.h>

int minimo(int num1, int num2){		//Introducimos los datos por valor
	if(num1<num2)
		return num1;
	else return num2;
}

void minimo_referencia(int num1, int num2, int *resultado){		//Pasamos el resultado por referencia con *
	if(num1<num2)
		*resultado=num1;	//Al asignarle el valor de num1, se lo estamos asignando a la variable declarada en el main
	else *resultado=num2;

}
int main(int argc, char const *argv[])
{
	int a,b,res;
	printf("Introduce un numero:");
	scanf("%d",&a);
	printf("Introduce otro numero:");
	scanf("%d",&b);
	printf("El valor minimo entre %d y %d por valor es: %d\n",a,b,minimo(a,b));
	minimo_referencia(a,b,&res);	//Al llamar a la función le pasamos la dirección de res
	printf("El valor minimo entre %d y %d por referencia es: %d\n",a,b,res);
	return 0;
}