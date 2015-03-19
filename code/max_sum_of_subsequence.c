#include<stdio.h>
#include<stdlib.h>

/*
 *HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天JOBDU测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？
 输入：
 输入有多组数据,每组测试数据包括两行。
 第一行为一个整数n(0<=n<=100000),当n=0时,输入结束。接下去的一行包含n个整数(我们保证所有整数属于[-1000,1000])。
 输出：
 对应每个测试案例,需要输出3个整数单独一行,分别表示连续子向量的最大和、该子向量的第一个元素的下标和最后一个元素的下标。若是存在多个子向量,则输出起始元素下标最小的那个。
 样例输入：
 3
 -1 -3 -2
 5
 -8 3 2 0 5
 8
 6 -3 -2 7 -15 1 2 2
 0
 样例输出：
 -1 0 0
 10 1 4
 8 0 3
 *http://ac.jobdu.com/problem.php?pid=1372
 */

#define MAX 100
int n;
int beginFrom[MAX];
int max_sum[MAX];
int num[MAX];

void solve()
{
	int from,to,sum,max;
	for(int i=0;i<n;i++){
		max = num[i];
		from = to = i;
		sum = 0;
		for(int j=i;j<n;j++){
			sum	+= num[j];
			if(sum>max){
				max = sum;
				to = j;	
			}
		}
		
		beginFrom[from] = to;
		max_sum[from] = max;
	}
	
	from = 0;
	max = max_sum[0];
	for(int i=1;i<n;i++){
		if(max_sum[i]>max){
			from = i;
			max = max_sum[i];
		}	
	}

	printf("%d %d %d\n",max,from,beginFrom[from]);
}

int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}

	solve();
}
