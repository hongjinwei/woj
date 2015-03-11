#include<stdio.h>
#include<stdlib.h>

/*
 *重建二叉树。给定先序和中序序列后重新构建二叉树
 *http://ac.jobdu.com/problem.php?pid=1385
 */

//未完成

int parent[50];
typedef struct BTNode{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

int locate(int x,int a[],int size)
{
	for(int i=0;i<size;i++){
		if(a[i] == x){
			return i;
		}
	}	
	return -1;
}

//判断a是不是b的祖先
int isParent(int a,int b)
{
	while(parent[b] != 0){
		if(parent[b] == a){
			return 1;
		}
		b = parent[b];
	}	
	return 0;
}


//给定父节点的先序遍历序列中的下标，返回左子树的下标，若为空返回-1
int locateLeftChild(int p,int fore[],int mid[],int size)
{
	if(p<0 || p>=(size-1)){
		return -1;
	}	
	
	int midp; 
	int root = locate(fore[p],mid,size);
	for(int i=p+1;i<size;i++){
		midp = locate(fore[i],mid,size);
		if( midp< root){
			return midp;
		}	
	}
	return -1;
}

int locateRightChild(int p,int fore[],int mid[],int size)
{
	if(p<0 || p>=(size-1)){
		return -1;
	}	

	int midp; 
	int root = locate(fore[p],mid,size);
	for(int i=p+1;i<size;i++){
		midp = locate(fore[i],mid,size);
		if(midp > root){
			break;
		}	
	}
	for(int i=root+1;i<midp;i++){
		if(isParent(mid[i],mid[midp])||isParent(mid[i],mid[midp])){
			return -1;
		}
	}
	return midp;
}

BTNode *createNode(int n)
{
	BTNode *p = (BTNode *)malloc(sizeof(BTNode));
	p->data = n;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

void build(BTNode *root,int left,int right,int mid[])
{
	BTNode *p;
	if(-1 == left){
		root->lchild = NULL;
	}else{
		p = createNode(mid[left]);
		root->lchild = p;
	}
	
	if(-1 == right){
		root->rchild = NULL;
	}else{
		p = createNode(mid[right]);
		root->rchild = p;
	}
}

void setParent(int root,int l, int r,int mid[])
{
	if(l!=-1){
		parent[mid[l]] = root;
	}
	if(r!=-1){
		parent[mid[r]] = root;
	}
}

void buildTree(BTNode *root,int p,int fore[], int mid[], int size)
{
	if(root != NULL){
		int l = locateLeftChild(p,fore,mid,size);
		int r = locateRightChild(p,fore,mid,size);
		printf("root %d ",p);
		printf("l %d r %d\n",l,r);
		build(root,l,r,mid);
		setParent(root->data,l,r,mid);
		buildTree(root->lchild,l,fore,mid,size);
		buildTree(root->rchild,r,fore,mid,size);
	}
}

int main()
{
	int size;
	int fore[50] = {1,2,4,7,3,5,6,8};
	int mid[50]= {4,7,2,1,5,3,8,6};
	//scanf("%d",&size);
	//for(int i=0;i<size;i++){
	//	scanf("%d",&fore[i]);
	//}
	//for(int i=0;i<size;i++){
	//	scanf("%d",&mid[i]);
	//}
	size = 8;	
	int n;
	//while(scanf("%d",&n) != -1){
	//	printf("left %d\n",locateLeftChild(n,fore,mid,size));
	//	printf("right %d\n",locateRightChild(n,fore,mid,size));
	//}
	BTNode *root = createNode(fore[0]);
	parent[fore[0]] = 0;
	buildTree(root,0,fore,mid,size);
	return 0;
}
