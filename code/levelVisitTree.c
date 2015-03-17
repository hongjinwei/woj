#include<stdio.h>
#include<stdlib.h>
/*
 *从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 *http://ac.jobdu.com/problem.php?pid=1523
 */

#define MAX 100
typedef struct BTNode{
    int data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

int num[MAX] = {0};
BTNode *node[MAX] = {NULL};

BTNode *queue[MAX];
int front=0;
int rear=0;

void push(BTNode *p)
{
	if(p != NULL){
		rear++;
		queue[rear] = p;
	}
}

BTNode *pop()
{
	return queue[++front];
}

int isEmpty()
{
	return front==rear;
}

BTNode *createNode(int data)
{
    BTNode *p = (BTNode *)malloc(sizeof(BTNode));
    p ->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

BTNode *buildTree(int n)
{
    char sign;
    int l,r;
    BTNode *p;
	
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	getchar();

    for(int i=1;i<=n;i++){
        p = createNode(num[i]);
        node[i] = p;
    }

    for(int i=1;i<=n;i++){
        scanf("%c",&sign);
        if('d' == sign){
            scanf("%d",&l);
            scanf("%d",&r);
            node[i]->lchild = node[l];
            node[i]->rchild = node[r];
        }else if('l' == sign){
            scanf("%d",&l);
            node[i]->lchild = node[l];
        }else if('r' == sign){
            scanf("%d",&r);
            node[i]->rchild = node[r];
        }else{
            ;
        }
        getchar();
    }

    return node[1];
}

void printTree(BTNode *root)
{
    if(root != NULL){
        printf("%d ",root->data);
        printTree(root->lchild);
        printTree(root->rchild);
    }
}

void levelPrintTree(BTNode *root)
{
	push(root);
	BTNode *p;
	while(!isEmpty()){
		p = pop();
		printf("%d ",p->data);
		push(p->lchild);
		push(p->rchild);
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d",&n);
	BTNode *root = buildTree(n);
	//printTree(root);
	//printf("\n");
	levelPrintTree(root);
	return 0;
}
