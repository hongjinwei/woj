#include<stdio.h>
#include<stdlib.h>

int size=0;
int change(int *c)
{
	(*c)++;
}

void test1()
{
	char j;
	for(int i=0;i<2;i++){
		scanf("%c",&j);
	}
	printf("%d",j);
}

void test2()
{
	size = 1;
}

void insert(int l ,int r,int num[])
{
	int tmp = num[r];
	for(int i=r;i>l;i--){
		num[i] = num[i-1];
	}
	num[l] = tmp;
}

void print(int num[],int size)
{
	for(int i=0;i<size;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}

void quicksort(int l, int r,int num[])
{
	if(l>=r){
		return ;
	}
	int tmp = num[l];
	int i=l,j=r;
	while(i<j){
		while(i<j && num[j] > tmp ){
			j--;
		}	
		if(i<j){
			num[i++] = num[j];
		}

		while(i<j && num[i] <= tmp ){
			i++;
		}	
		if(i<j){
			num[j--] = num[i];
		}
	}
	num[i] = tmp;
	quicksort(i+1,r,num);
	quicksort(l,i-1,num);
}


void swap(int l , int r,int num[])
{
	if(l!=r){
		num[l] = num[l] + num[r];	
		num[r] = num[l] - num[r];
		num[l] = num[l] - num[r];
	}
}

void permutation(int i,int size,int num[])
{
	//int k;
	if(i==size-1){
		printf("--->");
		print(num,size);		
		return ;
	}else{
		for(int j=i;j<size;j++){
			//printf("i %d j %d\n",i,j);
			insert(i,j,num);
			//print(num,size);		
			//scanf("%d",&k);
			permutation(i+1,size,num);
			quicksort(i,size-1,num);
			//printf("before swap i %d j %d\n",i,j);
			//swap(i,j,num);
		}
	}	
}

void test3()
{
	int num[10] = {1,2,3,4};
	int size = 4;
	//quicksort(0,3,num);
	//print(num,size);		
	permutation(0,size,num);
}

void test4()
{
	int a[20];
	char b[20][20];
	/*
	scanf("%d",&a[0]);
	printf("%d\n",a[0]);
	scanf("%s",a);
	printf("%s\n",a);
	scanf("%s",b[0]);
	printf("%s\n",b[0]);
	scanf("%s",&b[0]);
	printf("%s\n",b[0]);
	*/
	//scanf("%s",&a[0]);
	

	scanf("%s",&a[0]);
	printf("%s\n",a);
	scanf("%s",&a);
	printf("%s\n",a);
	scanf("%s",a);
	printf("%s\n",a);
}

int main()
{
	test4();

}
