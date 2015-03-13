#include<stdio.h>
#include<stdlib.h>

int p[2] = {1,2};
int count = 0;

void jump(int steps)
{
	if(steps == 0 ){
		count++;
	}
	for(int i=0;p[i]<=steps && i < 2;i++){
		jump(steps-p[i]);
	}
}

int main()
{
	jump(4);
	printf("%d\n",count);
}

