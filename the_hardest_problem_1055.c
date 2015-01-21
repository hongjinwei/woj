#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10000

int main()
{
    char a[SIZE];
    int i;
    while(1){
        gets(a);
        //getchar();
        if(!strcmp(a,"ENDOFINPUT")){
            return 0;
        }

        if(strcmp(a,"START")&& strcmp(a,"END")){
            i = 0;
            while(a[i] != '\0'){
                if(a[i]>='A' && a[i] <= 'Z'){
                    a[i] = ((a[i] - 'A') - 5 + 26)%26 + 'A';
                }
                i++;
            } 
            printf("%s\n",a);
        } 
    }
}
