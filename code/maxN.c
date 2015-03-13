#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 *给定一个数字N，打印从1到最大的N位数。
 *http://ac.jobdu.com/problem.php?pid=1515
 */

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<pow(10,N);i++){
		printf("%d\n",i);
	}
	return 0;
}
