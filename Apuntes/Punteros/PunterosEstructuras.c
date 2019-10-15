#include <stdio.h>

struct punto
{
	int x;
	int y;
};

int main(int argc, char const *argv[])
{
	struct punto a;		//OBLIGATORIO PONER STRUCT
	a.x=2;
	a.y=4;
	struct punto *b;
	b=&a;
	printf("Punto A: (%d,%d)\n",a.x,a.y);
	printf("Contenido de B: (%d,%d)\n",(*b).x,(*b).y);
	printf("Contenido de B: (%d,%d)\n",b->x,b->y);		//Distinto formato, mismo significado
	return 0;
}
//*p.x significa *(p.x), esto seria erróneo, puesto que p.x no es un puntero