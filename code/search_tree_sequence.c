#include<stdio.h>
#include<stdlib.h>

/*
 *输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 *http://ac.jobdu.com/problem.php?pid=1367
 */
#define MAX 100
//int num[MAX] = {7,4,6,5};
//int size = 4;
int num[MAX] = {5,7,6,9,11,10,8};
int size = 7;

void insert(int from,int to)
{
	int tmp	= num[from];
	for(int i = from;i>to;i--){
		num[i] = num[i-1];
	}
	num[to] = tmp;
}

int judge(int l,int r)
{
	if(l<r){
		int flag = 1;
		int i = l;
		for(;i<r;i++){
			if(num[i]>num[r]){
				insert(r,i);
				break;
			}
		}
		//printf("l:%d r:%d\n",l,r);
		//for(int j=0;j<size;j++){
		//	printf("%d ",num[j]);
		//}
		//printf("==\n");
		//printf("===i:%d\n",i);
		for(int j=i;j<r;j++){
			if(num[j]<num[i]){
				flag = 0;
				break;
			}
		}

		if(flag){
			return judge(i+1,r) && judge(l,i-1);
		}else{
			return 0;
		}
	}else{
		return 1;
	}
}

int main()
{
	printf("%d\n",judge(0,size-1));
}
