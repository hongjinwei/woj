/*
 * 分解质因数算法
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 10, i = 2;
	while(a!=1){
		if(a%i == 0){
			printf("%d ",i);
			a = a/i;
		}else{
			i++;
		}	
	}
	return 0;
}
