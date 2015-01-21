#include<stdlib.h>
#include<stdio.h>

long long int l[500];

long long int init(long long int b,long long int l[])
{
    long long int z = -1;
    for(;b!=1;b = b >> 1){
        z++;
        if(b%2 == 1){
            l[z] = 1;
        }else{
            l[z] = 0;
        }
    }
    return z; 
}

int main()
{
    long long int a,b,c;
    long long int y,z;
    while(1){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        if(a==0&&b==0&&c==0){
            break;
        }
        z = init(b,l); 
        y = (a%c)*(a%c)%c;
        for(;z>0;z--){
            if(l[z]){
                y = (y*a%c)*(y*a%c)%c;
            }else{
                y = y*y%c;
            }
        } 
        if(l[0]){
            y = y*a%c;
        }
        printf("%lld\n",y);
    }
    return 0;
}
