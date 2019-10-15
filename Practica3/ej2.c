#include <stdio.h>

int mcd(int x, int y);

int main() {
  int x,y = 0;
  printf("Numero 1: ");
  scanf("%d",&x);
  printf("Numero 2: ");
  scanf("%d",&y);

  printf("El mcd de %d y %d es %d\n",x,y,mcd(x,y));
}

int mcd(int x, int y) {
  if(y==0)
    return x;
  else return mcd(y, x%y);
}
