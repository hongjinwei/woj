#include<stdio.h>
#include<stdlib.h>
#define MAX 3

/*
 *http://ac.jobdu.com/problem.php?pid=1512
 *用两个栈来实现一个队列，完成队列的Push和Pop操作。
 */
int stack1[MAX];
int top1 = -1;
int stack2[MAX];
int top2 = -1;

//push a into n's stack;
void stackPush(int a,int n)
{
	if(n==1){
		stack1[++top1] = a;
	}else{
		stack2[++top2] = a;
	}
}

int stackPop(int n)
{
	if(1 == n){
		return stack1[top1--];
	}else{
		return stack2[top2--];
	}
}

void push(int a)
{
	if(top1 == MAX-1&& top2 != -1){
		printf("queue is full\n");
		return ;
	}else if(top1 == MAX-1&& top2 == -1){
		while(top1 != -1){
			stackPush(stackPop(1),2);
		}
		stackPush(a,1);
	}else{
		stackPush(a,1);
	}
}

void pop()
{
	if(top2 == -1 && top1 == -1){
		printf("-1");
		return ;
	}
	if(top2 == -1 && top1 >= 0){
		while(top1 != -1){
			stackPush(stackPop(1),2);
		}
	}
	printf("%d\n",stackPop(2));
}

int main()
{
	push(3);
	push(2);
	push(1);
	push(0);
	push(-1);
	push(-1);
	push(-1);
	pop();
	pop();
	pop();
	pop();
	pop();
	return 0;
}



