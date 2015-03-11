#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int num;
	struct LNode *next;
}LNode;

LNode *createLinkNode(int n)
{
	LNode *p = (LNode *)malloc(sizeof(LNode));
	p->num = n;
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
	int number;
	LNode *head = createLinkNode(0);
	LNode *p;
	while(scanf("%d",&number) && number != -1){
		p = createLinkNode(number);
		headInsert(head,p);
	}

	p = head->next;
	while(p!=NULL){
		printf("%d\n",p->num);
		p = p->next;
	}
}
