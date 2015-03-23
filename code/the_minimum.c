#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 *http://ac.jobdu.com/problem.php?pid=1504
 *题目描述：
 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 输入：
 输入可能包含多个测试样例。
 对于每个测试案例，输入的第一行为一个整数m (1<=m <=100)代表输入的正整数的个数。
 输入的第二行包括m个正整数，其中每个正整数不超过10000000。
 输出：
 对应每个测试案例，
 输出m个数字能排成的最小数字。
 样例输入：
 3
 23 13 6
 2
 23456 56
 样例输出：
 13236
 2345656
 */
#define MAX 100
int num[MAX];
int size;

// return i's number in a num
// num = 99 i=2 return 9
int get_number(int num,int i)
{
	int k = pow(10,i);
	if(k/10 > num){
		return -1;
	}
	while(num>=k){
		num = num / 10;	
	}
	return num%10;
}

int bigger_than(int a,int b)
{
	if(a == b){
		return 0;
	}
	int i=1;	
	int m = get_number(a,i);
	int n = get_number(b,i);
	int current = n;
	while(m!= -1 && n != -1 && m==n){
		i++;
		m = get_number(a,i);
		n = get_number(b,i);
	}

	if(m!= -1 && n != -1){
		return (m>n)?1:0;
	}else if(m == -1 && n == -1){
		return 1;
	}else if(m==-1 && n>current){
		return 1;
	}else if(n==-1 && m<current){
		return 0;
	}else{
		while(m==current || n == current){
			i++;	
			m = get_number(a,i);
			n = get_number(b,i);
			if(m == -1 && n == -1){
				return 0;
			}else if(m==-1 && n<current){
				return 1;
			}else if(n==-1 && m<current){
				return 0;
			}else{
				;	
			}
		}
	}
}

void bubble_sort()
{
	int flag = 0;
	int tmp;
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(bigger_than(num[j],num[j+1])){
				tmp = num[j];		
				num[j] = num[j+1];
				num[j+1] = tmp;
				flag = 1;
			}
		}
		if(!flag){
			return ;
		}
	}
}



int main()
{
	//int a,b;
	//scanf("%d %d",&a,&b);
	//printf("%d\n",bigger_than(a,b));
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		scanf("%d",&num[i]);
	}
	
	bubble_sort();
	for(int i=0;i<size;i++){
		printf("%d",num[i]);
	}
	printf("\n");
	return 0;
}
