#include<stdio.h>
#include<stdlib.h>

/*
 *http://ac.jobdu.com/problem.php?pid=1132
 *与7无关的数，一个正整数,如果它能被7整除,或者它的十进制表示法中某个位数上的数字为7,
 *则称其为与7相关的数
 */

int isLegal(int a)
{
	if(a % 7 ==0){
		return 0;
	}
	while(a){
		if((a % 10) == 7){
			return 0;
		}
		a = a/10;
	}
	return 1;
}

int main()
{
	int n,sum = 0;
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		if(isLegal(i)){
			sum  += i*i;	
		}
	}
	printf("%d\n",sum);
}
