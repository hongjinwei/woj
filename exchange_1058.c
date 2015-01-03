#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long int k;
    while(1){
        scanf("%lld",&k);
        if(k == 0){
            break;
        }
        long long int size3,size2;
        size3 = k / 3;
        long long int res = 0;
        for(long long int i=0;i<=size3;i++){
            size2 = (k - 3*i)/2;
            res = res + size2 + 1;
        } 
        printf("%lld\n",res);
    }
    return 0;
}
