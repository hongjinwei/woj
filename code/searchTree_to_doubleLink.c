#include<stdio.h>
#include<stdlib.h>

/*
 *题目描述：
 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 输入：
 输入可能包含多个测试样例。
 对于每个测试案例，输入的第一行为一个数n(0<n<1000)，代表测试样例的个数。
 接下来的n行，每行为一个二叉搜索树的先序遍历序列，其中左右子树若为空则用0代替。
 输出：
 对应每个测试案例，
 输出将二叉搜索树转换成排序的双向链表后，从链表头至链表尾的遍历结果。
 样例输入：
 1
 2 1 0 0 3 0 0
 样例输出：
 1 2 3
 *http://ac.jobdu.com/problem.php?pid=1503
 */

#define MAX 100
int num[MAX];
int size;

typedef struct BTNode{
	int data;
	struct BTNode *lchild; //put it as *fore when create a double link list
	struct BTNode *rchild; // put it as *next when create a double link list
}BTNode;

BTNode *create_node(int data)
{
	BTNode *p = (BTNode *)malloc(sizeof(BTNode));
	p->data = data;
	p->lchild = p->rchild = NULL;
	return p;
}

BTNode *create_tree()
{
	BTNode *root = create_node(num[0]);
	BTNode *p,*q;
	for(int i=1;i<size;i++){
		p = root;
		if(num[i] != 0){
			while(1){
				if(num[i] < p->data && p->lchild == NULL){
					q = create_node(num[i]);
					p->lchild = q;
					break;
				}else if(num[i] < p->data){
					p = p->lchild;
				}else if(num[i] >= p->data && p->rchild == NULL){
					q = create_node(num[i]);
					p->rchild = q;
					break;
				}else{
					p = p->rchild;
				}
			}
		}
	}
	return root;
}

void build(BTNode *p,BTNode *pre)
{
	if(p!=NULL){
		build(p->lchild,pre);
		if(p->lchild != NULL){
			p->lchild->rchild = p;	
		}
		p->lchild = pre;
		pre = p;
		build(p->lchild,pre);
		if(p->rchild != NULL){
			p->rchild->lchild = pre;	
			pre = p->rchild;
		}
	}
}

BTNode *build_link(BTNode *root)
{
	BTNode *newroot=root;	
	while(newroot->lchild != NULL){
		newroot = newroot->lchild;	
	}

	build(root,NULL);
	return newroot;
}

void print_link(BTNode *p)
{
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->rchild;
	}
	printf("\n");
}

void print_tree(BTNode *p)
{
	if(p != NULL){
		printf("%d ",p->data);
		print_tree(p->lchild);
		print_tree(p->rchild);
	}
}

int main()
{
	int n,i=0;
	char data[MAX];
	int d;
	scanf("%d",&n);
	getchar();
	while(n--){
		size = 0;
		//gets(data);
		//while(data[i] != '\0'){
		//	if(data[i] >= '0' && data[i] <= '9'){
		//		num[size++] = data[i] - '0';
		//	}
		//	i++;
		//}
		while(scanf("%s" ,&data)){
			num[size++] = atoi(data);
			if(getchar() == '\n'){
				break;
			}
		}
		//for(int j=0;j<size;j++){
		//	printf("%d ",num[j]);
		//}

		BTNode *root = create_tree();	
		//print_tree(root);
		root = build_link(root);
		//printf("\n");
		print_link(root);
		printf("\n");
	}
	return 0;
}

