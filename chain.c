#include<stdio.h>
#include<stdlib.h>

int isOdd(int );
int chainLen(int );

int isOdd(int num)
{
    return (num%2==1);
}

int chainLen(int num)
{
    int len = 1;
    while(num!=1){
        if(isOdd(num)){
            num = num*3 + 1;    
        }else{
            num = num / 2;
        }    
        len++;
    }
    return len;
}

int main()
{
    //printf("%d\n",chainLen(22));
    int i=1,j=1; 
    while(1){
        int max=0,len=0;
        scanf("%d",&i);
        scanf("%d",&j);
        if(i==0 && j==0){
            break;
        }
        while(i<=j){
            len = chainLen(i);
            if(len>max){
                max = len;
            }
            i++;
        }
        printf("%d\n",max);
    }
    return 0;
}
