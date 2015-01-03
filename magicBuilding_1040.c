#include<stdio.h>
#include<stdlib.h>
//#define size 10000
int main()
{
    int N;//N cases
    scanf("%d",&N);
    while(N--){
        int t;//t numbers 
        scanf("%d",&t);
        int a[t];
        int max = 1;
        for(int i=0;i<t;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<t-1;i++){
            int tmp = 1;
            if(a[i] != 0){
                for(int j=i+1;j<t;j++){
                    if(a[j] != 0 && a[i] == a[j]){
                        tmp++; 
                    }
                    if(tmp > max){
                        max = tmp;
                    }
                }
            }
        }
        
        printf("%d\n",max);
    }
    return 0;
}
