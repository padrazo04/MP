#include <stdio.h>
#include <ctype.h>
#define MAX 30

int numDigit(char *cad){
	int nDigit=0;
	for(int i=0; cad[i]!='\0'; i++)
		if((isdigit(cad[i]))!=0)
			nDigit++;
	return nDigit;
}

int numMayusc(char cad[]){
	int nMay=0;
	for(int i=0; cad[i]!='\0'; i++)
		if((isupper(cad[i]))!=0)
			nMay++;
	return nMay;

}

int numMinusc(char cad[]){
	int nMin=0;
	for(int i=0; cad[i]!='\0'; i++)
		if((islower(cad[i]))!=0)
			nMin++;
	return nMin;

}

int numEspacios(char cad[]){
	int nEsp=0;
	for(int i=0; cad[i]!='\0'; i++)
		if((isspace(cad[i]))!=0)
			nEsp++;
	return nEsp-1;

}

int main(int argc, char const *argv[])
{
	char cad[MAX];
	printf("Introduzca la cadena: " );
	//scanf("%s", &cad);	//No puede leer espacios
	//gets(cad); //PELIGROSA, se pasa el bufer
	fgets(cad, MAX, stdin);	//Lee MAX-1 caracteres
	printf("Cadena introducida: ");
	printf("%s", cad);
	/*for(int i=0; cad[i]!='\0'; i++)
		printf("%c",cad[i]);*/		//printf("%s\n", cad);
	printf("\nNumero de digitos: %d", numDigit(cad));
	printf("\nNumero de mayusculas: %d", numMayusc(cad));
	printf("\nNumero de minusculas: %d", numMinusc(cad));
	printf("\nNumero de espacios: %d\n", numEspacios(cad));
	return 0;
}
