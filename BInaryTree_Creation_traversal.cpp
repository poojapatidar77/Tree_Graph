#include<iostream>
#include<queue>
class node
{
public :
int data;
node * left;
node * right;
node(int d)
{
data=d;
left=NULL;
right=NULL;
}
};

node * insertion(node *root)
{
std::cout<<"Enter the data\n"	;
int data;
std::cin>>data;
if(data==-1)
return NULL;
root=new node(data);



std::cout<<"Enter left node  value = "<<root->data<<"\n";

root->left=insertion(root->left);


std::cout<<"Enter right node  value  = "<<root->data<<"\n";

root->right=insertion(root->right);

return root;


}
void inorder(node *root)
{
if(root==NULL)return ;

inorder(root->left);
std::cout<<root->data<<"  ";	
inorder(root->right);	
}	


//level order
void levelorder(node * root)
{
std::queue<node*> q;
q.push(root);
q.push(NULL);

while(!q.empty())
{
node *temp=q.front();
q.pop();
if(temp==NULL)
{
std::cout<<"\n";

if(!q.empty())q.push(NULL);	
}
else
{
std::cout<<temp->data<<"  ";
if(temp->left)q.push(temp->left);
if(temp->right)q.push(temp->right);
}
}
	
}

int main()
{
node * root=NULL;
root= insertion(root);	
// inorder(root);

levelorder(root);

return 0;


}