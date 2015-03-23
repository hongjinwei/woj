/*
 *输出全排列
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int num[MAX]={1,2,3};
int size=3;

void swap(int i,int j)
{
	if(i!=j){
		num[i] = num[i]+num[j];
		num[j] = num[i]-num[j];
		num[i] = num[i]-num[j];
	}
}

void recurse(int i)
{
	if(i==size-1){
		for(int j=0;j<size;j++){
			printf("%d",num[j]);
		}
		printf("\n");
	}else{
		for(int j=i;j<size;j++){
			swap(i,j);
			recurse(i+1);
			swap(i,j);
		}
	}
}

int main()
{
	recurse(0);
}
