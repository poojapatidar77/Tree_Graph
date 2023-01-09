//BFS using Linked List


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
struct node
{
	int data;
	struct node *data1;
	struct node *left,*right;
   struct node *next;
};
struct node *root=NULL;
struct node *insert(struct node *,int x);
void enqueue(struct node*);
struct node* dequeue();
struct node *front=NULL;
struct node *rare=NULL;

void showall(struct node *temp);
bool isempty();
void main()
{
	root=insert(root,10);
	insert(root,25);
	insert(root,15);
	insert(root,1);
	insert(root,4); 
	insert(root,14); 
	insert(root,40); 
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
struct node *temp=malloc(sizeof(struct node ));
	temp->data1=v;
     temp->next=NULL;
	if(front==NULL)
	{
		rare=front=temp;
		return ;
	}
	rare->next=temp;
	rare=temp;
}
struct node *dequeue()
{
	if(front==NULL)
	{
		printf("queue is empty dequeue\n");
	}
	else
	{
		struct node *temp=front;
		struct node * temp1=temp->data1;
		front=temp->next;
		free(temp);
		return temp1;
	}
} 
bool isempty()
{
	if(front==NULL)return true;
	else false;
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