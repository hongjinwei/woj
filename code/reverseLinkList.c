#include<stdio.h>
#include<stdlib.h>

/*
 *输入一个链表，反转链表后，输出链表的所有元素。
 *http://ac.jobdu.com/problem.php?pid=1518
 */

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;

LNode *createNode(int data)
{
	LNode *p = (LNode *)malloc(sizeof(LNode));
	p->data = data;
	p->next = NULL;
	return p;
}

LNode *createLinkList(int n)
{
	LNode *head = createNode(0);
	LNode *p,*q = head;
	int num;
	while(n--){
		scanf("%d",&num);
		p = createNode(num);
		q->next = p;
		q = p;
	}
	return head;
}

void reverse(LNode *head)
{
	LNode *p = head->next;
	if(p == NULL){
		return ;
	}
	LNode *r = NULL;
	LNode *q = p->next;

	while(p != NULL&& q!=NULL){
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	if(head ->next != NULL){
		head->next->next= NULL;
	}

	head->next = p;
}

void printLink(LNode *p)
{
	if(p == NULL || p->next == NULL){
		printf("NULL\n");
		return ;
	}
	p = p->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}	
	printf("\n");
}

int main()
{
	int n;
	LNode *head;
	while(scanf("%d",&n)!= -1){
		head = createLinkList(n);
		reverse(head);
		printLink(head);
	}
	return 0;
}
