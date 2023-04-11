#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};


Node *getSuccessor(Node *curr)
{
	curr=curr->right;
	while(curr && curr->left)
	   curr=curr->left;
	return curr;
}
Node *deletion(Node *root,int key)
{
	if(root==NULL)
	   return NULL;
	else if(root->data>key)
	   root->left=deletion(root->left,key);
	else if(root->data<key)
	   root->right=deletion(root->right,key);
	else
	{
		if(root->left==NULL)
		{
			Node *temp=root->right;
			delete(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			Node *temp=root->left;
			delete(root);
			return temp;
		}
		else
		{
			Node *succ=getSuccessor(root);
			root->data=succ->data;
			root->right=deletion(root->right,succ->data);
		}
	}
	return root;
}

void Inorder(Node *root)
{
	if(root==NULL)
	   return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int main()
{
	Node *root=new Node(5);
	root->left=new Node(3);
	root->right=new Node(7);
	root->left->left=new Node(2);
	root->left->right=new Node(4);
	root->right->left=new Node(6);
	root->right->right=new Node(8);
	cout<<"Inorder traversal of BST before deletion\n";
	Inorder(root);
	int key=5;
	root=deletion(root,key);
	cout<<"\n\nInorder traversal of BST after deletion "<<key<<"\n";
	Inorder(root);
	return 0;
}





