#include<stdio.h>
#include<stdlib.h>

/*
 *http://ac.jobdu.com/problem.php?pid=1153
 *括号匹配问题
 */

typedef struct stackType{
	char n;
	int position;
}stackType;

stackType stack[100];
int top = -1;

void push(char c,int p )
{
	++top;
	stack[top].n = c;
	stack[top].position = p;
}

stackType pop()
{
	//char a = stack[top--];
	return stack[top--];
}

int popable()
{
	return (top >= 1 && stack[top].n==')' && stack[top-1].n =='(');
}
int main()
{
	char str[100];
	stackType a;
	gets(str);
	for(int i=0;str[i]!='\0';i++){
		if('(' == str[i] || ')' == str[i]){
			push(str[i],i);
		}else{
			str[i] = ' ';
		}

		if(popable()){
			a = pop();
			str[a.position] = ' ';
			a = pop();
			str[a.position] = ' ';
		}
	}
	for(int j=0;j<=top;j++){
		if(stack[j].n == '(')
			str[stack[j].position] = '$';
		if(stack[j].n == ')')
			str[stack[j].position] = '?';
	}

	printf("%s\n",str);
}
