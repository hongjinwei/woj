#include<stdio.h>
#include<stdlib.h>

int change(int *c)
{
	(*c)++;
}

void test1()
{
	char j;
	for(int i=0;i<2;i++){
		scanf("%c",&j);
	}
	printf("%d",j);
}
int main()
{
	test1();
		
}
