#include<stdio.h>
#include<stdlib.h>

typedef struct newtype{
	int num;
	int exist;
}newtype;

int ifInt(long long int a,long long  int b)
{
	return !(a%b);
}

long long int cantalan(long long int n)
{
	if(n == 1){
		return 1;
	}
	long long int N = 2*n,j = 1;	
	long long int res = N;
	newtype number[n];
	for(int i=0;i<n+1;i++){
		number[i].num = i+1;
		number[i].exist = 1;
	}
	while(j<n){
		res = res * (N-j);
		for(int i=0;i<n+1;i++){
			if(ifInt(res,number[i].num) && number[i].exist){
				res = res / number[i].num;
				number[i].exist = 0;
			}
		}
		j++;
	}
	return res;
}


int main()
{
	int i,k;
	scanf("%d",&i);
	while(i--){
		scanf("%d",&k);
		printf("%lld\n",cantalan(k));
	}
	return 0;
}
