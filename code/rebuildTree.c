#include<stdio.h>
#include<stdlib.h>
#define MAX 50
/*
 *重建二叉树。给定先序和中序序列后重新构建二叉树
 *http://ac.jobdu.com/problem.php?pid=1385
 */

//version 2.0
typedef struct BTNode{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

int parent[MAX]={0};
int mid[MAX]= {4,7,2,1,5,3,8,6};
int fore[MAX] = {1,2,4,7,3,5,6,8};

int locate(int x,int a[],int size)
{
    for(int i=0;i<size;i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}

void setParent(int root,int data)
{
	parent[data] = root;
}

//if a is b's ancestor return 1
int isParent(int a, int b)
{
	if(parent[a] == -1){
		return 1;
	}

	while(parent[b] != -1){
		if(parent[b] == a){
			return 1;
		}
		b = parent[b];
	}	
	return 0;
}

int getLchild(int a,int size)
{
	int midp = locate(a,mid,size);	
	int forep = locate(a,fore,size);	
	int parentp = locate(parent[a],mid,size);
	int k;	
	if(parentp >= 0){
		for(int i=forep+1;i<size;i++){
			k = locate(fore[i],mid,size);
			if((midp > parentp && k<midp && k>parentp) || (midp < parentp && k<midp)){
				//setParent(a,fore[i]);
				//for(int j=midp+1;j<=k;j++){
				//	if(isParent(mid[j],a))
				//		return -1;
				//}
				return fore[i];
			}
		}
	}else{
		for(int i=forep+1;i<size;i++){
			k = locate(fore[i],mid,size);
			if(k<midp){
				//setParent(a,fore[i]);
				return fore[i];
			}
		}
	}
	return -1;
}

int getRchild(int a,int size)
{
	int midp = locate(a,mid,size);	
	int forep = locate(a,fore,size);	
	int parentp = locate(parent[a],mid,size);
	int k;
	if(parentp >= 0){
		for(int i=forep+1;i<size;i++){
			k = locate(fore[i],mid,size);
			if((midp < parentp && k>midp && k<parentp) || (midp > parentp && k>midp)){
				//setParent(a,fore[i]);
				for(int j=midp+1;j<=k;j++){
					if(parent[mid[j]] != 0 && isParent(mid[j],a)){
						return -1;
					}
				}
				return fore[i];
			}
		}
	}else{
		for(int i=forep+1;i<size;i++){
			k = locate(fore[i],mid,size);
			if(k>midp){
				//setParent(a,fore[i]);
				return fore[i];
			}
		}
	}
	return -1;
}

BTNode *createNode(int n)
{
    BTNode *p = (BTNode *)malloc(sizeof(BTNode));
    p->data = n;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

void build(BTNode *root,int ldata,int rdata)
{
    BTNode *p;
    if(-1 == ldata){
        root->lchild = NULL;
    }else{
        p = createNode(ldata);
        root->lchild = p;
    }

    if(-1 == rdata){
        root->rchild = NULL;
    }else{
        p = createNode(rdata);
        root->rchild = p;
    }
}

void buildTree(BTNode *root, int size)
{
    if(root != NULL){
        int l = getLchild(root->data,size);
        int r = getRchild(root->data,size);
        build(root,l,r);
        buildTree(root->lchild,size);
        buildTree(root->rchild,size);
    }
}

void init(int size)
{
	parent[fore[0]] = -1;
	int a,l,r;
	for(int i=0;i<size;i++){
		a = fore[i];
		l = getLchild(a,size);
		r = getRchild(a,size);
		//printf("===root %d l %d r %d \n",a,l,r);
		if(l!=-1){
			setParent(a,l);
			//printf("parent[%d] = %d\n",l,a);
		}
		if(r!=-1){
			setParent(a,r);
			//printf("parent[%d] = %d\n",r,a);
		}
	}
}

void printParent(int size)
{
	for(int i=1;i<=size;i++){
		printf("%d's parent is %d\n",i,parent[i]);	
	}	
}

void printTreeMid(BTNode *p)
{
	if(p!=NULL){
		printTreeMid(p->lchild);
		printf("%d ",p->data);
		printTreeMid(p->rchild);
	}	
}

void printTreeFore(BTNode *p)
{
	if(p!=NULL){
		printf("%d ",p->data);
		printTreeFore(p->lchild);
		printTreeFore(p->rchild);
	}	
}

int main()
{
    int size;
	//scanf("%d",&size);
    //for(int i=0;i<size;i++){
    //  scanf("%d",&fore[i]);
    //}
    //for(int i=0;i<size;i++){
    //  scanf("%d",&mid[i]);
    //}
    size = 8;
	init(size);
    //int n;
    //while(scanf("%d",&n) != -1){
    //  printf("left %d\n",getLchild(n,size));
    //  printf("right %d\n",getRchild(n,size));
    //}
    BTNode *root = createNode(fore[0]);
    //parent[fore[0]] = 0;
    buildTree(root,size);
	printTreeMid(root);
	printf("\n");
	printTreeFore(root);
	printf("\n");
	printParent(size);
    return 0;
}

