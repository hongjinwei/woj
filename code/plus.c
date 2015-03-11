#include<stdio.h>
#include<stdlib.h>

/*
 * http://ac.jobdu.com/problem.php?pid=1507
 * 不用+，-，*，/求2个整数的和
 */

int plus(int a, int b)
{
	int c = 0;
	int sum = 0;
	while(a || b || c){
		int d1,d2;
		d1 = a%2;
		d2 = b%2;
		sum = (sum << 1) | (d1 ^ d2 ^ c);
		c = (d1 && d2) || (d2 && c) || (d1 && c); //产生进位
		a = a / 2;
		b = b / 2;
	}
	return sum;
}

int main()
{
	int a = 5,b=2;
	printf("%d\n",plus(a,b));
}
