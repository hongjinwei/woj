#include<stdio.h>
#include<stdlib.h>

/*
 * http://ac.jobdu.com/problem.php?pid=1113
 * 给定一个m节点，已知完全二叉树有n个节点，求m所在子树共有多少节点
 */

int ans;
int count(int p,int n)
{
	if(p<=n){
		ans++;
		count(p*2,n);
		count(p*2+1,n);
	}
}

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n) && m!=0 && n!=0){
		ans = 0;
		count(m,n);
		printf("%d\n",ans);
	}
	return 0;
}
