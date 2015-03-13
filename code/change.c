#include<stdio.h>
#include<stdlib.h>

/*
 *输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 *http://ac.jobdu.com/problem.php?pid=1516
 */

void insert(int a,int b,int num[])
{
	int tmp = num[b];
	for(int i=b;i>=a;i--){
		num[i] = num[i-1];	
	}
	num[a] = tmp;
}

int isOdd(int a)
{
	return (a%2==1);
}

int change(int num[],int size)
{
	int j;
	for(int i=0;i<size;i++){
		if(!isOdd(num[i])){
			j = i+1;
			while(j<size && !isOdd(num[j])){
				j++;	
			}
			if(j<size){
				insert(i,j,num);
			}
		}
	}
}

int main()
{
	int size,n;
	int num[50];
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		scanf("%d",&num[i]);
	}
	change(num,size);
	for(int i=0;i<size-1;i++){
		printf("%d ",num[i]);
	}
	printf("%d\n",num[size-1]);

	return 0;
}
