/*
 *计算素数
 */
#include<stdio.h>
#include<stdlib.h>

int primes[2000]={2};
int p=0;

void setPrimes(int a)
{
	p++;
	primes[p] = a;
}

int isPrime(int a)
{
	if(a < 2){
		return 0;
	} 

	if(2 == a){
		return 1;
	}
	
	for(int i=0;primes[i]*primes[i] <= a;i++){
		if(a%primes[i] == 0){
			return 0;
		}
	}
	setPrimes(a);
	return 1;
}

int main()
{
	int n = 10000;
	for(int i=2;i<=n;i++){
		if(isPrime(i)){
			printf("%d ",i);
		}
	}
}
