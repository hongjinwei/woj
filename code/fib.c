#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
	if(n ==0 ){
		return 0;
	}
	if(n == 1){
		return 1;
	}

	return fib(n-1) + fib(n-2);
}

int main()
{
	int n = 3;
	printf("%d\n",fib(n));
}
