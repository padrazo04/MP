#define MAX 256
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *f; //referencia al fichero de clientes
	char nombreF[]="test.txt"; //nombre del fichero de clientes
	char nombre[50], apell1[50], apell2[50]; //nombre y apellidos
	int num; //codigo de cliente
	float interes; //tipo de interes
	int total; //deuda total
	//Apertura del fichero
	if((f=fopen(nombreF, "r"))==NULL) {
		fprintf(stderr, "\nError: no pudo abrirse fichero <%s>\n",
		nombreF);
		exit(-1);
	}
	while(fscanf(f, "%s%s%s%d%f%d", nombre, apell1, apell2,&num,
	&interes, &total)==6) {
		//Presentamos los datos obtenidos
		printf("\nCliente Num. %3d: %s %s, %s", num, apell1, apell2,
		nombre);
		printf("\n\tDeuda total= %8d. Interes=%4.2f\n", total,
		interes);
	}
	//Cierre del fichero
	fclose(f);
	return(0);
}
