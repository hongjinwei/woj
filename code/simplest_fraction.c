#include<stdio.h>
#include<stdlib.h>

int getMaxCommonDivisor(int a,int b)
{
	if(b%a == 0){
		return a;
	}
	return getMaxCommonDivisor(b%a,a);
}

int main()
{
	int n,count,i;
	int num[600];
	while(scanf("%d",&n) && n!=0){
		count=i=0;
		for(int a=0;a<n;a++){
			scanf("%d",&num[a]);
		}

		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(getMaxCommonDivisor(num[j],num[k])==1){
					count++;
				}			
			}
		}
		printf("%d\n",count);
	}

	return 0;
}
