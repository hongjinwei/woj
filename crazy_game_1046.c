#define N 3000
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int test_case,len;
    scanf("%d", &test_case);
    int num[N];
    int result , j;
    while(test_case--){
        result = 0;
        scanf("%d",&len);
        for(int i=0;i<len;i++){
            scanf("%d",&num[i]);
        }

        for(int i=0;i<len-1;i++){
            j = i + 1;
            while(j < len){
                if(num[j] < num[i]){
                    result++;
                }
                j++;
            }
        }

        printf("%d\n",result);
    }
    return 0;
}
