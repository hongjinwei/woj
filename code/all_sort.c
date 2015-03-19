#include<stdio.h>
#include<stdlib.h>

#define MAX 100

char a[MAX] = {0};
int size=0;

void quicksort(int l,int r)
{
	if(l<r){
		int tmp = a[l];
		int i=l,j=r;
		while(i<j){
			while(i<j && a[j] > tmp){
				j--;
			}
			if(i<j){
				a[i++] = a[j];
			}

			while(i<j && a[i] < tmp){
				i++;	
			}
			if(i<j){
				a[j--] = a[i];
			}
		}
		a[i] = tmp;
		quicksort(i+1,r);
		quicksort(l,i-1);
	}
}

void print()
{
	for(int i=0;i<size;i++){
		printf("%c",a[i]);
	}
	printf("\n");
}

void input()
{
	gets(a);
	size = 0;
	for(int i=0;a[i] != '\0';i++){
		size++;
	}
	quicksort(0,size-1);
}

void insert(int l,int r)
{
	int tmp = a[r];
	for(int i=r;i>l;i--){
		a[i] = a[i-1];
	}
	a[l] = tmp;
}

void recurse(int i)
{
	if(i == size-1){
		print();
	}else{
		for(int j=i;j<size;j++){
			insert(i,j);
			recurse(i+1);
			quicksort(i,size-1);
		}
	}

}

int main()
{
	input();
	recurse(0);
}
