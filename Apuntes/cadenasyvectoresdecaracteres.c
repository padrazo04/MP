#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char vectchar1[3];
	char vectchar2[3]={'S','o','l'};	//También es válido char vectchar2[]={'S','o','l'}; 
	char vectchar3[]={'S','o','l'};			//El compilador cuenta los caracteres
	char vectchar4[3]="Sol";
	char vectchar5[]="Sol";
	//char vectchar6[]; (No está definido el tamaño)

	printf("Tama%co de vectchar1 (bytes): %d\n", 164, strlen(vectchar1));
	printf("Tama%co de vectchar2 (bytes): %d\n", 164, strlen(vectchar2));
	printf("Tama%co de vectchar3 (bytes): %d\n", 164, strlen(vectchar3));
	printf("Tama%co de vectchar4 (bytes): %d\n", 164, strlen(vectchar4));
	printf("Tama%co de vectchar5 (bytes): %d\n\n", 164, strlen(vectchar5));

	for(int i=0; i<3; i++) {
		printf("POSICION %d: %c\n", i, vectchar1[i]);
		if(vectchar1[i]=='\0')
			printf("En la posicion %d hay un \\0\n", i);
	}

	for(int i=0; i<5; i++) {
		printf("POSICION %d: %c\n", i, vectchar2[i]);
		if(vectchar2[i]=='\0')
			printf("En la posicion %d hay un \\0\n", i);
	}

	for(int i=0; i<4; i++) {
		printf("POSICION %d: %c\n", i, vectchar3[i]);
		if(vectchar3[i]=='\0')
			printf("En la posicion %d hay un \\0\n", i);
	}


	return 0;
}