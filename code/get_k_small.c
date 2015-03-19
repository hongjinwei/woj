#include<stdio.h>
#include<stdlib.h>

//输出最小的K个数字
#define MAX 100
int min[MAX]={0};
int K;

void update(int number)
{
	for(int i=0;i<K;i++){
		if(min[i] == 0){
			min[i] = number;
			return ;
		}

		if(min[i]>number){
			for(int j=K-1;j>i;j--){
				min[j] = min[j-1];
			}
			min[i] = number;	
			return ;
		}
	}
}

int main()
{
	int n,number;
	scanf("%d %d",&n,&K);
	getchar();
	while(n--){
		scanf("%d",&number);
		update(number);
	}

	for(int i=0;i<K-1;i++){
		printf("%d ",min[i]);
	}
	printf("%d\n",min[K-1]);
}
