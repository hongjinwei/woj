#include<stdio.h>
#include<stdlib.h>

int stack[100];
int number[100];
int top = -1;

int isEmpty()
{
    return top == -1;
}

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
    while(scanf("%d",&N)!=-1){
        init();
        int i = 0;
        while(N--){
            scanf("%d",&number[i]);
            push(number[i]);
            i++;
            if(!isSame()){
                pop();
                pop();
            }
        }

        if(!isEmpty()){
            printf("%d\n",stack[0]);
        }else{
            int count0=0;
            int count1=0;
            for(int j=0;j<N;j++){
                if(number[j]==stack[0])
                    count0++;
                if(number[j]==stack[1])
                    count1++;
            }
            if(count0>count1){
                printf("%d\n",stack[0]);
            }else{
                printf("%d\n",stack[1]);
            }
        }
    }

}
