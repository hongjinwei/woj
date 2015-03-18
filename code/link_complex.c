#include<stdio.h>
#include<stdlib.h>

/*
 *题目描述：
 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
 输入：
 输入可能包含多个测试样例，输入以EOF结束。
 对于每个测试案例，输入的第一行为一个整数n (1<=n<=1000)：n代表将要输入的链表元素的个数。（节点编号从1开始）。
 接下来有n个数，表示链表节点中的值。
 接下来有n个数Ti，Ti表示第i个节点的另一个指针指向。
 Ti = 0 表示这个指针为NULL。
 输出：
 对应每个测试案例，
 输出n行，每行有二个数，第一个代表当前节点值，第二个代表当前节点的特殊指针的值。
 样例输入：
 5
 1 2 3 4 5
 3 5 0 2 0
 样例输出：
 1 3
 2 5
 3 0
 4 2
 5 0 
 *http://ac.jobdu.com/problem.php?pid=1524
 */

#define MAX 100

typedef struct LNode{
	int data;
	struct LNode *next;
	struct LNode *new;
}LNode;

LNode *node[MAX];
int size;

LNode *createNode(int data)
{
	LNode *p = (LNode *)malloc(sizeof(LNode));
	p->data = data;
	p->next = NULL;
	p->new = NULL;
}

LNode *build_link()
{
	scanf("%d",&size);
	int data;
	for(int i =1;i<=size;i++){
		scanf("%d",&data);
		node[i] = createNode(data);
	}
	
	for(int i =1;i<=size;i++){
		scanf("%d",&data);
		if(i<size){
			node[i]->next = node[i+1];
		}
		if(data){
			node[i]->new = node[data];
		}
	}
	return node[1];
}

void output(LNode *p)
{
	while(p!=NULL){
		printf("%d ",p->data);
		if(p->new != NULL){
			printf("%d\n",p->new->data);
		}else{
			printf("0\n");
		}
		p = p->next;
	}
}

int main(int argc,char **argv)
{
	LNode *p = build_link();
	output(p);
}
