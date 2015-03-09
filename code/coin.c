#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define TOTAL 100

/*
 * 递归方式计算用1分，2分，5分组成1元总共有几种方式
 */
int p[3]= {5,2,1};

void change(int index,int value,int *count)
{
	if(index==2){
		(*count)++;
		return ;
	}

	for(int i=0;i<=value/p[index];i++){
		change(index+1,value-i*p[index],count);
	}
}

int main()
{
	int num=0;
	change(0,TOTAL,&num);
	printf("%d\n",num);
}
