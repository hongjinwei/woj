#include<stdio.h>
#include<stdlib.h>
#define MAX 100

/*
 *输入一个二叉树，输出其镜像。输入可能包含多个测试样例，输入以EOF结束。
 对于每个测试案例，输入的第一行为一个整数n(0<=n<=1000,n代表将要输入的二叉树节点的个数（节点从1开始编号）。接下来一行有n个数字,代表第i个二叉树节点的元素的值。接下来有n行，每行有一个字母Ci。
 Ci=’d’表示第i个节点有两子孩子，紧接着是左孩子编号和右孩子编号。
 Ci=’l’表示第i个节点有一个左孩子，紧接着是左孩子的编号。
 Ci=’r’表示第i个节点有一个右孩子，紧接着是右孩子的编号。
 Ci=’z’表示第i个节点没有子孩子。
 *http://ac.jobdu.com/problem.php?pid=1521
 **************************
 样例输入：
 7
 8 6 10 5 7 9 11
 d 2 3
 d 4 5
 d 6 7
 z
 z
 z
 z
 样例输出：
 8 10 11 9 6 7 5
 */

typedef struct BTNode{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

int num[MAX] = {0};
BTNode *node[MAX] = {NULL};

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

void mirror(BTNode *p)
{
	if(p!=NULL){
		mirror(p->lchild);
		mirror(p->rchild);
		BTNode *tmp = p->lchild;
		p->lchild = p->rchild;
		p->rchild = tmp;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	getchar();
	BTNode *root = buildTree(n);
	mirror(root);
	printTree(root);
	printf("\n");
	return 0;	
}

