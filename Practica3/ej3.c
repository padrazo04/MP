#include <stdio.h>
#include <stdlib.h>

int divEntera(int div1, int div2);

int main(int argc, char const *argv[]) {
  int num1, num2;
  printf("Introduce un dividendo: ");
  scanf("%d",&num1);
  printf("Introduce un divisor: ");
  scanf("%d",&num2);
  if((num1<0) ^ (num2<0))
    printf("%d / %d = %d\n",num1, num2, -divEntera(num1, num2));
  else printf("%d / %d = %d\n",num1, num2, divEntera(num1, num2));
  return 0;
}

int divEntera(int x, int y) {
  x=abs(x);
  y=abs(y);
  if (y==0) {
    printf("Error, el divisor no puede ser 0\n");
    exit(-1);
  }
  if(x<y)
    return 0;
  else return (1+divEntera(x-y,y));
}
