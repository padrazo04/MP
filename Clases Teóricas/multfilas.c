#include <stdio.h>

struct punto {
	int x;
	int y;
};
typedef struct punto punto;
int main(int argc, char const *argv[]) {
	punto a;
	float matriz[2][3]={1.1,1.2,1.3,2.1,2.2,2.3};
	float V[3];
 	//void multiplicaFilas(float A[][MAX], float V[], int   nFil, int nCol, int a, int b) {
    for(int i=0; i<3; i++) {
        V[i]=matriz[0][i]*matriz[1][i];
    }
    for(int i=0; i<3; i++)
    	printf("%.1f\n",V[i]);
	return 0;
}