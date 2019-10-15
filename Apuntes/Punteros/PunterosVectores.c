#include <stdio.h>

int main(int argc, char const *argv[])
{
	int v[5]={1,2,3,4,5};
	int *ptr;
	ptr=v //Equivale a ptr= &v[0];
	*v=0;	//Equivale a v[0]=0 y a *(&v[0])=0;

	float m[2][2]={1.1,1.2,2.1,2.2}
	//Para matrices estaticas usaremos la notacion m[][]

	return 0;
}
