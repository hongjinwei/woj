#include<stdio.h>
#include<stdlib.h>
/*
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 *http://ac.jobdu.com/problem.php?pid=1519
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

LNode *merge(LNode *head,LNode *L)
{
	if(head == NULL || L == NULL){
		return (head == NULL)?L:head;
	}

	LNode *p = head;
	LNode *q = L->next;
	LNode *r;
	while(p->next != NULL && q != NULL){
		while(p->next != NULL && p->next->data < q->data){
			p = p->next;
		}
		if(p->next != NULL){
			r = p->next;	
			p->next = q;
			q = q->next;
			p->next->next = r;
			p = p->next;
		}	
	}

	if(q!=NULL){
		p->next = q;
	}
	free(L);
	return head;
}

int main()
{
	int n1,n2;
	LNode *h1,*h2;
	while(scanf("%d %d",&n1,&n2) != -1){
		h1 = createLinkList(n1);
		h2 = createLinkList(n2);
		h1 = merge(h1,h2);
		printLink(h1);
	}
	return 0;
}

