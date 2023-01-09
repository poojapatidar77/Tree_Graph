#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define capacity 5

struct node
{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;
struct node *insert(struct node *,int x);
struct node *x[capacity];
void enqueue(struct node*);
struct node* dequeue();
int f=-1;
int r=-1;
void showall(struct node *temp);
bool isempty();
void main()
{
	root=insert(root,10);
	insert(root,25);
	insert(root,15);
	insert(root,1);
	insert(root,4); 
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
void enqueue(struct node *v)
{
	if(r==capacity-1)
	{
		printf("queue is full\n");
		return;
	}
	if(f==-1)++f;
	x[++r]=v;
}
struct node *dequeue()
{
	if(f==-1||f>r)
	{
		printf("queue is empty dequeue\n");
	}
	else return x[f++];
} 
bool isempty()
{
	if(f==-1||f>r)return true;
	else  return false;
}
void showall(struct node *temp)
{
	if(temp==NULL)
	{
		printf("queue is empty showall\n");
	   return ;
	}
	struct node *temp1=temp;
	enqueue(temp1);
	while(!isempty())
	{
		temp1=dequeue();
		printf("%d\n",temp1->data);
		if(temp1->left!=NULL)enqueue(temp1->left);
		if(temp1->right!=NULL)enqueue(temp1->right);
	}
}