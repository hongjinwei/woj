#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

void swap(long long int *a,long long int *b)
{
    long long int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble(long long int a[],int last)
{
    int j;
    for(int i=last;i>0;i--){
        j = 0;
        while(j<i){
            if(a[j] > a[j+1]){
                swap(&a[j],&a[j+1]);        
            }
            if(a[j] == a[j+1]){
                a[j] = -1;
            }
            j++;
        } 
    
    } 
        
}

int main()
{
    long long int a[MAX]; 
    int i=0;
    while(scanf("%lld",&a[i])){
        if(a[i] == 0){
            break;
        }
        i++;
    }

    bubble(a,i-1);
    for(int k=0;k<i-1;k++){
        if(a[k] != -1){
            printf("%lld ",a[k]);
        }
    }

    printf("%lld\n",a[i-1]);
}
