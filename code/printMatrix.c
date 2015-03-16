#include<stdio.h>
#include<stdlib.h>

#define R 0
#define D 1
#define L 2
#define U 3
#define MAX 100

int i=1,j=1;
int dir = R;
int num[MAX][MAX] = {0};

int isLast()
{
	return !(num[i-1][j] || num[i+1][j] ||num[i][j-1] || num[i][j+1]);
}

int visitNext()
{
	int flag = 0;
	if(dir == R && num[i][j+1] ){
		flag = 1;
		j++;
	}
	if(dir == D && num[i-1][j] ){
		flag = 1;
		i--;
	}
	if(dir == L && num[i][j-1]){
		j--;
		flag = 1;
	}
	if(dir == U && num[i+1][j]){
		i++;
		flag = 1;
	}

	if(flag){
		if(isLast()){
			printf("%d\n",num[i][j]);
		}else{
			printf("%d ",num[i][j]);
		}
		num[i][j] = 0;
		return 1;
	}else{
		return 0;
	}
}

void changeDir()
{
	dir = (dir + 1)	% 4;
}


void go()
{
	printf("%d ",num[1][1]);
	num[1][1] = 0;
	while(!isLast()){
		while(visitNext());
		changeDir();
	}
}	


int main()
{
	int m,n;	
	scanf("%d %d",&m,&n);
	for(int k=1;k<=m;k++){
		for(int s=1;s<=n;s++){
			scanf("%d",&num[k][s]);
		}
		getchar();
	}
	go();
	return 0;
}
