#include <stdio.h>
#define MAX 30

int main(int argc, char const *argv[])
{
	char test[MAX]="Hola";
	int length=0;
	char *ptrc;
	for (length = 0; test[length]!='\0'; ++length)
		printf("%c\n", test[length]);
	for (ptrc=test; *ptrc!='\0'; ptrc++);
	printf("\nLongitud (segunda version): %ld\n", ptrc-test);
	return 0;
}