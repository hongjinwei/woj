#include<stdio.h>
#include<stdlib.h>

/*
 *输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 *http://ac.jobdu.com/problem.php?pid=1513
 */

int main()
{
	int n,T,count;
	scanf("%d",&T);
	while(T--){
		count = 0;
		scanf("%d",&n);
		printf("%d\n",n);
		while(n){
			if(n > 0){
				if(n & 1){
					count++;
				}
				n = n>>1;
			}else{
				if(n & 0x80000000){
					count++;
				}
				n = n<<1;
			}
		}
		printf("%d\n",count);
	}
}
