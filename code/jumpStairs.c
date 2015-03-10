#include<stdio.h>
#include<stdlib.h>
#define MAX 50

/*
 *变态跳台阶 http://ac.jobdu.com/problem.php?pid=1389
 *一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
int p[MAX];
int count;

void init()
{
	count = 0;
	for(int i=0;i<MAX;i++){
		p[i] = i+1;
	}
}

void jump(int steps,int index)
{
	if(steps == 0){
		count++;
	}else{
		for(int k=0;k<=index && p[k]<=steps;k++){
			jump(steps-p[k],index);	
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	init();
	jump(n,n-1);
	printf("%d\n",count);
}

