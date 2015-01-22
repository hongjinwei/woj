#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top = -1;

int pop()
{
    top--;
}

int push(int a)
{
    stack[++top]=a;
}

void init()
{
    top = -1;
}
int isSame()
{

    if(top > 0){
        return stack[top] == stack[top-1];    
    }else{
        return 1;
    }
}

int main()
{
    int N;
    int num;
    while(scanf("%d",&N)!=-1){
        init();
        while(N--){
            scanf("%d",&num);
            push(num);
            if(!isSame()){
                pop();
                pop();
            }
        }
        printf("%d\n",stack[0]);
    }
}
