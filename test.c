#include<stdio.h>
#include<stdlib.h>

int main()
{
    char c[50];
    int num[100];
    int p =0 , len;
    scanf("%d",&len);
    getchar();
    gets(c);
    for(int i=0;i<len;i++){
        while(c[p] == ' '){
           p++; 
        }
        num[i] = c[p] - '0';
        p++;
    } 
    for(int i=0; i < len; i++){
        printf("%d ",num[i]);
    }

}
