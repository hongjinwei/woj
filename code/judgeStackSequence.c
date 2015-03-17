#include<stdio.h>
#include<stdlib.h>
/*
 *输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
 *http://ac.jobdu.com/problem.php?pid=1366
 */

#define MAX 100
int a[100];
int b[100];
int asize;
int size;

void removeElement(int position)
{
	for(int i=position;i<asize-1;i++){
		a[i] = a[i+1];
	}
	asize--;
}

/*
void print()
{
	for(int i=0;i<asize;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
*/

int judge()
{
	int i=-1;
	for(int j=0;j<size;j++){
		//printf("b[%d] = %d\n",j,b[j]);
		//print();
		if(i<0 && asize ==0 || i>=asize){
			return 0;
		}
		if(i<0 && i<asize-1){
			i++;
		}
		while(a[i] != b[j]  && i<asize){
			i++;	
		}
		if(i<asize){
			removeElement(i);
			i--;
		}else{
			return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d",&size);
	asize = size;
	for(int i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<size;i++){
		scanf("%d",&b[i]);
	}
	
	if(judge()){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
