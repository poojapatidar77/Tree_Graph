//avl tree algo


#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left;
	struct node *right;
    int  height;
};
struct node *root=NULL;
struct node *insert(struct node *temp,int x);
void showall(struct node *temp);
int max(int a,int b);
int getHeight(struct node *n);
int getBalanceFactor(struct node *n);
struct node *rightRotate(struct node *y);
struct node *leftRotate(struct node *x);
void main()
{
	root =insert(root,100);
	root =insert(root,20);
	root =insert(root,130);
	root =insert(root,40);
	root =insert(root,50);
	root =insert(root,25);
	showall(root);
}
struct node *insert(struct node *temp,int x)
{
	if(temp==NULL)
	{
		temp=malloc(sizeof(struct node ));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		return temp;
	}
	if(x<temp->data)
	{
		temp->left=insert(temp->left,x);
	}
	else if(x>temp->data)
	{
		temp->right=insert(temp->right,x);
	}
	else return temp;
	 
	 temp->height=1+max(getHeight(temp->left),getHeight(temp->right));
	
	int bf=getBalanceFactor(temp);
	
	//left left
	if(bf>1&&x<temp->left->data)
    {
		return rightRotate(temp);
	}
	//right right
	if(bf<-1 && x>temp->right->data)
	{
		return leftRotate(temp);
	}
	//left right
	if(bf>1 && x>temp->left->data)
	{
		temp->left=leftRotate(temp->left);
		return rightRotate(temp);
	}
	//right left
	if(bf<-1 && x<temp->right->data)
	{
		temp->right=rightRotate(temp->right);
		return leftRotate(temp);
	}
	return temp;
}
struct node *rightRotate(struct node *y)
{
	struct node *x=y->left;
	struct node *T2=x->right;
	
	x->right=y;
	y->left=T2;
	
	y->height=max(getHeight(y->left),getHeight(y->right))+1;
	x->height=max(getHeight(x->left),getHeight(x->right))+1;
   
   return x;
}
struct node *leftRotate(struct node *x)
{
	struct node *y=x->right;
	struct node *T2=y->left;
	
	y->left=x;
	x->right=T2;
	
	x->height=max(getHeight(x->left),getHeight(x->right))+1;
	y->height=max(getHeight(y->left),getHeight(y->right))+1;
   
   return y;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int getHeight(struct node *n)
{
	if(n==NULL)return 0;
	return n->height;
}
int getBalanceFactor(struct node *n)
{
	if(n==NULL)return 0;
	return (getHeight(n->left)-getHeight(n->right));
}

void showall(struct node *temp)
{
	if(temp==NULL)return ;
	showall(temp->left);
    printf("%d\n",temp->data);
	showall(temp->right);
}
