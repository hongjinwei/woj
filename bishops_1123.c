#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long int n;
    while(scanf("%lld",&n)==1){
        if(n==1){
            printf("1\n");
        }else{
            printf("%lld\n",2*n-2);
        }
    }
}
