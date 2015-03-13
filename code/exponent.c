#include<stdio.h>
#include<stdlib.h>

/*
 *给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 *http://ac.jobdu.com/problem.php?pid=1514
 */
double calc(double base,int n)
{
	double res=base;
	if(0 == n){
		return 1.0;
	}

	int N = abs(n) - 1;
	while(N--){
		res = res * base;	
	}

	if(n>0){
		return res;
	}else{
		return 1.0/res;
	}
}

int main()
{
	int T,n;
	double base,ans;

	int ex;
	scanf("%d",&T);
	while(T--){
		scanf("%lf",&base);
		scanf("%d",&n);
		ex = 0;
		if(base == 0.0 && n < 0){
			printf("INF\n");
		}else{
			ans = calc(base,n);
			//printf("ans %lf\n",ans);
			while(ans<1.0){
				ans = ans*10;	
				ex--;
			}	
			while(ex>10.0){
				ans = ans/10;	
				ex++;
			}
			printf("%.2lfe",ans);
			if(ex>=0){
				printf("+%02df\n",ex);
			}else{
				printf("-%02df\n",abs(ex));
			}
		}
	}
}
