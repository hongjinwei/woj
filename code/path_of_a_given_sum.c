#include<stdio.h>
#include<stdlib.h>

/*
 *输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 *http://ac.jobdu.com/problem.php?pid=1368
 */

#define MAX 100
typedef struct BTNode{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

BTNode *node[MAX] = {NULL};
int size;

BTNode *stack[MAX];
int top = -1;

int locate(int x)
{
	for(int i=1;i<=size;i++){
		if(node[i]->data ==x){
			return i;
		}
	}
}
void push(BTNode *p)
{
	stack[++top] = p;	
}

void pop()
{
	top--;
}

int isLeaf(BTNode *p)
{
	return p->lchild==NULL && p->rchild==NULL;
}

BTNode *createNode(int data)
{
	BTNode *p = (BTNode *)malloc(sizeof(BTNode));
	p->data = data;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

BTNode *buildTree()
{
	for(int i=1;i<=size;i++){
		node[i] = createNode(0);
	}

	int data,l,r;
	for(int i=1;i<=size;i++){
		scanf("%d %d %d",&data,&l,&r);
		node[i]->data = data;
		if(l != -1){
			node[i]->lchild = node[l];
		}

		if(r != -1){
			node[i]->rchild = node[r];
		}
	}

	return node[1];
}

int calc_sum()
{
	int sum=0;
	for(int i=0;i<=top;i++){
		sum += stack[i]->data;
	}
	return sum;
}

void print_path()
{
	printf("A path is found: ");
	for(int i=0;i<top;i++){
		printf("%d ",locate(stack[i]->data));
	}
	if(top >=0){
		printf("%d\n",locate(stack[top]->data));
	}
}

void print_stack()
{
	printf("stack ");
	if(top < 0){
		printf("is empty");
	}else{
		for(int i=0;i<=top;i++){
			printf("%d ",stack[i]->data);
		}
	}
	printf("\n");
}

void path(BTNode *p,int sum)
{
	if(p!=NULL){
		push(p);
		print_stack();
		if(!isLeaf(p)){
			path(p->lchild,sum);
			path(p->rchild,sum);
			pop();
		}else{
			if(calc_sum() == sum){
				print_path();
			}
			pop();
		}
	}
}

int main()
{
	int sum;
	scanf("%d %d",&size,&sum);
	BTNode *root = buildTree();
	printf("result:\n");
	path(root,sum);
	return 0;
}
