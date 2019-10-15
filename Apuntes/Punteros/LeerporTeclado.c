#include <stdio.h>

struct electrica
{
char corriente[30];
int voltios;
};

int main() {
  int z1, *z2, z3[5];
  float q1, *q2, q3[5];
  char a1, *a2, a3[10];
  struct electrica a,b;
  struct electrica *p=&a, *q=&b;

/*  z2=&z1;
  scanf("%d",&z1); //Equivale a scanf("%d",z2);
  scanf("%d", &z3[0]);

  q2=&q1;
  scanf("%f",&q1); //Equivale a scanf("%f",q2);
  scanf("%f",&q3[0]);*/

  a2=&a1;
  scanf("%c\n",&a1); //Equivale a scanf("%c",a2);
  scanf("%c\n",&a3[0]);
  scanf("%c\n",&a3[1]);
  printf("%c\n",a3[0]);
  printf("%s\n",a3);
  scanf("%s", a3);
  printf("%c\n",a3[0]);
  printf("%s\n",a3);

  scanf("%d",&p->voltios); //Equivale a &(*p).voltios
  scanf("%s", p->corriente);
  printf("%d\n", p->voltios);
  printf("%d\n", (*p).voltios);
  printf("%s\n", p->corriente);

  return 0;
}
