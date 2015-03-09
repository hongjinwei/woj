#include<stdio.h>
#include<stdlib.h>

void getDivisor(int a,int b[])
{
	int i = 2, j=1;
	b[0] = 1;
	for(;i<=a/2;i++){
		if(0 == a%i){
			b[j] = i;
			j++;
		}
	}
	b[j] =0;
}

void print(int b[])
{
	int i=0;
	while(b[i+1]!=0){
		printf("%d ",b[i]);
		i++;
	}
	printf("%d",b[i]);
}

int getSum(int b[])
{
	int i=0;
	int sum=0;
	while(b[i]!=0){
		sum += b[i];
		i++;
	}
	return sum;
}

int main()
{
	int b[50],res[50];
	int a = 6,k=0;
	for(int i=1;i<=a;i++){
		getDivisor(i,b);
		if(getSum(b) == i){
			res[k++] = i;	
		}
	}
	res[k] = 0;
	print(res);
	return 0;
}

