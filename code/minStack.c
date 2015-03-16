#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;


int isEmpty()
{
	return top == -1;
}

void push(int n)
{
	stack[++top] = n;
}

int pop()
{
	return stack[top--];
}

int getMin()
{
	int min = stack[0];
	for(int i=0;i<=top;i++){
		if(min> stack[i]){
			min = stack[i];
		}
	}
	return min;
}

int main()
{
	int n,num;
	char c;
	scanf("%d",&n);	
	while(n--){
		scanf("%c",&c);	
		getchar();
		if(c == 's'){
			scanf("%d",&num);
			push(num);
			printf("%d\n",getMin());
		}
		if(c == 'o'){
			if(isEmpty()){
				printf("NULL\n");
			}else{
				pop();
				if(isEmpty()){
					printf("NULL\n");
				}else{
					printf("%d\n",getMin());
				}
			}
		}
	}
	return 0;
}
