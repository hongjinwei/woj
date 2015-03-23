#include<stdio.h>
#include<stdlib.h>

/*
 *题目描述：
 把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 输入：
 输入包括一个整数N(1<=N<=1500)。
 输出：
 可能有多组测试数据，对于每组数据，
 输出第N个丑数。
 样例输入：
 3
 样例输出：
 3
 *http://ac.jobdu.com/problem.php?pid=1214
 */

#define MAX 1500
int ugly[MAX]={1,2,3,4,5};
int max = 5;
int size = 5;

int find_ugly(int n)
{
	int end1=0,end2=0,end3=0;
	int max1=0,max2=0,max3=0;
	while(size < n){
	
		for(int i=end1;i<size;i++){
			if(ugly[i]*2 > max){
				end1 = i;
				max1 = ugly[i]*2;
				break;
			}
		}		
		for(int i=end2;i<size;i++){
			if(ugly[i]*3 > max){
				end2 = i;
				max2 = ugly[i]*3;
				break;
			}
		}		
		for(int i=end3;i<size;i++){
			if(ugly[i]*5 > max){
				end3 = i;
				max3 = ugly[i]*5;
				break;
			}
		}		
		
		ugly[size++]=max= (max1<max2)?((max1<max3)?max1:max3):((max2<max3)?max2:max3);
	}

	return ugly[n-1];
}

int main()
{
	int n;
	while(1){
		scanf("%d",&n);
		printf("%d's ugly number is %d\n",n,find_ugly(n));
	}
}
