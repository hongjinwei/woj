#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[1000];
    int b[1000];
    int N,num;
    while(scanf("%d",&N) != -1){
        for(int i=0;i<1000;i++){
            a[i] = 0;
            b[i] = 0;
        }

        for(int i=0;i<N;i++){
            scanf("%d",&num);
            a[num]++;
            //printf("a[%d]= %d\n",num,a[num]);
        }

        int j=0;
        for(int i=0;i<1000;i++){
            if(a[i]>0){
                b[j] = i;
                //printf("b[%d]= %d\n",j,b[j]);
                j++;
            }
        }

        for(int i=0;i<j-1;i++){
            printf("%d ",b[i]);
        }
        printf("%d\n",b[j-1]);
    }
    return 0;
}
