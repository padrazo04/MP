#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  float **tabla;
  tabla=(float **)malloc(2*sizeof(float *));
  for(int i=0; i<2; i++)
    tabla[i]=(float *)malloc(3*sizeof(int));
  printf("%p\n",tabla+1);
  printf("%p\n",*(tabla+1));
  return 0;
}
