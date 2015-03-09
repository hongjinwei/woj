/*
 *简易计算器
 */

#include<stdio.h>
#include<stdlib.h>

double queue[200];
int rear = -1;

void push(double c)
{
	rear++;
	queue[rear] = c;
}


int pown(int a, int b)
{
	int k = 0;
	for(;k<b-1;k++){
		a = a*a;
	}
	return a;
}

void scan(char input[])
{
	int i = 0;
	while(input[i] != '\0'){
		while(input[i] == ' '){
			i++;
		}	
		double num = 0;
		int flag = -1;
		int numflag = 0, opflag = 0;
		while((input[i]<='9' && input[i] >= '0') || input[i] == '.'){
			numflag = 1;
			if(input[i] == '.'){
				flag = 0;
			}

			if(flag == -1){
				num = num*10 + input[i] - '0';	
			}
			if(flag > 0){
				num = num + (double )(input[i] - '0')/ pown(10,flag);
			}
			i++;
			if(flag>=0){
				flag++;
			}
		}
		if(numflag){
			push(num);
			while(input[i] == ' '){
				i++;
			}	
		}
		if(input[i] == '+' || input[i] == '-' || input[i] == '*' ||input[i] =='/'){
			push(input[i]);
			i++;	
		}
	}
}

void printQueue()
{
	int j=0;
	for(;j<=rear;j++){
		if((j+1)%2 == 0){
			printf("%c",(int )queue[j]);
		}else{
			printf("%f",queue[j]);
		}
	}
	printf("\n");
}

//pass a pointer which points to the op
void op(int op)
{
	double a = queue[op-1];	
	double b = queue[op+1];	
	double res;

	if(queue[op] == '+'){
		res = a + b;	
	}
	if(queue[op] == '-'){
		res = a - b;	
	}
	if(queue[op] == '*'){
		res = a * b;	
	}
	if(queue[op] == '/'){
		res = a / b;	
	}
	
	queue[op-1] = res;
	int j = op;
	for(;j<=rear-2;j++){
		queue[j] = queue[j+2];
	}
	rear = rear - 2;
}


double calc()
{
	int k = 1;
	for(;k<=rear;k=k+2){
		if((int )queue[k] == '*' || (int )queue[k] == '/'){
			op(k);
			k = k - 2;
		}
	}
	//printQueue();

	k=1;
	while(rear >= 1){
		op(k);
	}
	return queue[0];
}

int main()
{
	char input[200]; 
	gets(input);
	scan(input);
	//printQueue();	
	printf("%.2f\n",calc());
}

