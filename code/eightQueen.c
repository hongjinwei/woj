#include<stdio.h>
#include<stdlib.h>
#define N 8 // chessboard size
/*
 *八皇后问题
 *http://ac.jobdu.com/problem.php?pid=1140
 */


int abs(int a);//math abstract number;
int x[N];//the position of the queen;
int place(int i,int j);//return if you can put the queen here;
void traceback(int index);//put the queen to the index's column;

int sum=0;
int abs(int a)
{
	if(a<0){
		return 0-a;
	}else{
		return a;
	}
}

int place(int i,int j) //wether x[i] = j is legal ,means put queen on point(i,j);
{                      //if legal ,k<i x[k] != j,abs(x[k] - k) != (j - i);
	for(int k=0;k<i;k++){
		if(x[k] == j || abs(i - k) == abs(j - x[k]) ){
			return 0;
		}
	}	
	return 1;
}

void printChessboard()
{
	printf("\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(x[j] == i){
				printf("Q ");
			}else{
				printf("# ");
			}
		}
		printf("\n");
	}
}
void put(int t, int n) //put the t's row
{
	if(t==N){
		sum++;
		if(sum == n){
			for(int k=0;k<N;k++){
				printf("%d",x[k]+1);	
			}	
			printChessboard();
		}
	}else{
		for(int k=0;k<N;k++){
			x[t] = k;
			if(place(t,k)){
				put(t+1,n);
			}
		}
	}
}

int main()
{
	int n = 1;
	put(0,n);
}
