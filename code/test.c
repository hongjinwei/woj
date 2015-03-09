#include<stdio.h>
#include<stdlib.h>

int change(int *c)
{
	(*c)++;
}
int main()
{
	int a=0;
	int *b =  &a;
	change(&a);
	printf("%d\n",a);
}
