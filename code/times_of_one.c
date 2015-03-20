#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 *对应每个测试案例,输出a和b之间1出现的次数。
 *http://ac.jobdu.com/problem.php?pid=1373
 */

int one_number(int num)
{
	int sum = 0;
	while(num){
		if(num%10 == 1){
			sum++;
		}
		num = num / 10;
	}
	return sum;
}

int one_counter_forcely(int a,int b)
{
	int sum=0;
	for(int i=a;i<=b;i++){
		sum += one_number(i);
	}
	return sum;
}

int count(int a,int b)
{

	
	return 0;
}

int main()
{
	while(1){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",one_counter_forcely(a,b));
	}
	return 0;
}
