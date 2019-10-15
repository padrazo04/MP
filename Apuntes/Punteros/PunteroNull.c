/*---------------------
#define NULL 0
esta definido en:
	stddef.h
	stdio.h
	stdlib.h
	string.h
 ---------------------*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int *ptrnull=0; //(ptrnull=0)==(ptrnull=NULL)
	void *ptrvoid;	//Apunta a CUALQUIER tipo de dato
	int a=4;
	ptrvoid=&a;
	printf("%d\n",*(int *)ptrvoid);
	scanf("%d",(int *)ptrvoid);
	return 0;
}
