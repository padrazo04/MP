#include <stdio.h>
#include <math.h>

struct monomio {
	int coef;
	int grado;
};

void leerMonomio(struct monomio *m) {
	printf("Introduce el coeficiente del monomio: ");
	scanf("%d", &(*m).coef);
	printf("Introduce el grado del monomio: ");
	scanf("%d", &m->grado);
}

void imprimirMonomio(struct monomio *m) {
	printf("%dx^%d", m->coef, (*m).grado);
}

struct monomio monmayor(struct monomio *m, int n) {
	struct monomio mayor;
	mayor.coef=0;
	mayor.grado=-999;
	for(int i=0; i<n; i++){
		if(((m+i)->grado)>mayor.grado) {
			mayor=m[i];
		} else if((m+i)->grado==mayor.grado)
			mayor.coef+=(m+i)->coef;
	}
	return mayor;
}

struct monomio monmenor(struct monomio *m, int n) {
	struct monomio menor;
	menor.coef=0;
	menor.grado=999;
	for(int i=0; i<n; i++){
		if(((m+i)->grado)<menor.grado) {
			menor=m[i];
		} else if((m+i)->grado==menor.grado)
			menor.coef+=(m+i)->coef;
	}
	return menor;
}

float evaluaPol(struct monomio *m, int n, float p) {
	float res=0;
	for (int i=0; i<n; i++)
		res+=((m+i)->coef)*pow(p,(m+i)->grado);	//gcc ej9.c -lm
	return res;
}

int main(int argc, char const *argv[])
{
	int n=5;
	float p, res;
	struct monomio m[n];
	struct monomio mayor, menor;
	/*---------------------------------------------------
	printf("Introduzca el numero de monomios: ");
	scanf("%d", &n);
	m=(struct monomio*)malloc(n*sizeof(struct monomio));
	-------------------mem_dinamica--------------------*/

	for(int i=0; i<n; i++)
		leerMonomio(m+i);

	printf("\n");
	for(int i=0; i<n; i++) {
		imprimirMonomio(m+i);
		if(i<(n-1))
			printf("+");
		else printf("\n\n"); }

	mayor=monmayor(m,n);
	menor=monmenor(m,n);

	printf("El monomio de mayor grado es: %dx^%d\n",mayor.coef, mayor.grado);
	printf("El monomio de menor grado es: %dx^%d\n",menor.coef, menor.grado);
	printf("Introduce un valor p para evaluar el polinomio: ");
	scanf("%f",&p);
	res=evaluaPol(m, n, p);
	printf("VALOR DE P: %.5f\tF(P)= %.5f\n",p,res);
	return 0;
}
