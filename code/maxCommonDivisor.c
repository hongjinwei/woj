#include<stdio.h>
#include<stdlib.h>

/*
 *求2个数的最大公约数
 *欧几里德算法
 */
int getMaxCommonDivisor(int a,int b)
{
	if(a==0 || b==0){
		return 0;
	}

	printf("%d %d \n", a, b);
	if(b%a == 0){
		return a;
	}else{
		return getMaxCommonDivisor(b%a,a);
	}
}

int main()
{

	printf("%d\n", getMaxCommonDivisor(9,6));
	return 0;
}
