#include<stdio.h>
#include<stdlib.h>

int change(int *c)
{
	(*c)++;
}
int main()
{
	char a[5];
	char b[5];
	while(1){
		//gets(a);
		scanf("%s %s",&a,&b);
		printf("%c\n",a[0]);
		printf("%c\n",b[0]);
	}
}
