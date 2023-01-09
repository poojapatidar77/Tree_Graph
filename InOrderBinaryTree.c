 #include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left;
    struct node *right;	
};
struct node *root=NULL;
struct node *insert(struct node *,int);
void showall(struct node *);
void main()
{
	root=insert(root,10);
   insert(root,5);
   insert(root,15);
   insert(root,2);
   insert(root,1);
  showall(root);
}
struct node *insert(struct node *temp,int x)
{
	if(temp==NULL)
	{
		temp=malloc(sizeof(struct node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
	}
	else if(x<temp->data)
	{
		temp->left=insert(temp->left,x);
	}
	else if(x>temp->data)
	{
		temp->right=insert(temp->right,x);
	}
	return temp;
}
void showall(struct node *temp)
{
	if(temp==NULL)return;
 	showall(temp->left);
	printf("%d\n",temp->data);
   showall(temp->right);
 
}