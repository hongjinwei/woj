#include<stdio.h>
#include<stdlib.h>

char lower(char c)
{
    if(c >= 'A' && c <= 'Z'){
        c = c - 'A' + 'a';
    }
    return c;
}

char upper(char c)
{
    if(c >= 'a' && c <= 'z'){
        c = c - 'a' + 'A';
    }
    return c;
}

void change(char name[],char new[])
{
    int i=0,j=0;
    while(name[i]!='\0' && name[i] != ' '){
        i++;
    }
    i++;
    while(name[i]!='\0'){
        if(j==0){
            new[j] = upper(name[i]);
        }else{
            new[j] = lower(name[i]);
        }
        i++;
        j++;
    }
    new[j++] = ' ';
    i = 0;
    while(name[i]!=' '){
        if(i==0){
            new[j] = upper(name[i]);
        }else{
            new[j] = lower(name[i]);
        }
        i++;
        j++;
    }
    new[j] = '\0';
}

int main()
{
    int t;//t cases;
    char name[200];
    char new[200];
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(name);
        change(name,new);
        printf("%s\n",new);
    }
    return 0;
}
