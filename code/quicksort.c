#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int num[MAX] = {22,3,34,5,16,33,32,3};
void quicksort(int l, int r)
{
	if(l<r){
		int tmp=num[l];
		int i=l,j=r;
		while(i<j){
			while(num[j] > tmp && i < j){
				j--;
			}
			num[i++] = num[j];
			while(num[i] < tmp && i < j){
				i++;
			}
			num[j--] = num[i];
		}
		num[i] = tmp;
		quicksort(l,i-1);
		quicksort(i+1,r);
	}
}

int main()
{
	quicksort(0,7);
	for(int i=0;i<8;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}
