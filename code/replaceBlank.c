#include<stdio.h>
#include<stdlib.h>
#define MAX 100
/*
 *请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
 *http://ac.jobdu.com/problem.php?pid=1510
 */

int main()
{
	char str[MAX];
	gets(str);
	char *replaceStr = "\%20";
	for(int i=0;str[i] != '\0';i++){
		if(str[i] == ' '){
			printf("%s",replaceStr);
		}else{
			printf("%c",str[i]);
		}	
	}
	printf("\n");
	return 0;
}
