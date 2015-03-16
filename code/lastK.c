#include<stdio.h>
#include<stdlib.h>
#define MAX 100
/*
 *链表中倒数第k个结点
 *http://ac.jobdu.com/problem.php?pid=1517
 */

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;

LNode *createNode(int data)
{
	LNode *p;
	p = (LNode *)malloc(sizeof(LNode));
	p->data = data;
	p->next = NULL;
	return p;
}

void headInsert(LNode *head,LNode *p)
{
	LNode *q = head->next;
	head->next = p;
	p->next = q;
}

int main()
{
	int n,k,num;
	LNode *head = createNode(0);
	LNode *p;
	while(scanf("%d %d",&n,&k)!=-1){
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			p = createNode(num);
			headInsert(head,p);
		}

		p = head;
		for(int i=0;i<k;i++){
			p = p->next;	
			if(NULL == p){
				break;
			}
		}

		if(NULL == p || k <= 0){
			printf("NULL\n");
		}else{
			printf("%d\n",p->data);
		}
	}
	return 0;
}
