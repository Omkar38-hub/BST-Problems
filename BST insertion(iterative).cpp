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

Node *insert(Node *root,int key)
{
	Node *temp=new Node(key);
	Node *parent=NULL;
	Node *curr=root;
	while(curr!=NULL)
	{
		parent=curr;
		if(curr->data>key)
			curr=curr->left;
		else if(curr->data<key)
			curr=curr->right;
		else
		  return root;
	}
	if(parent==NULL)
	   return temp;
	else if(parent->data>key)
	   parent->left=temp;
	else 
	   parent->right=temp;
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
	cout<<"Inorder traversal of BST before insertion\n";
	Inorder(root);
	int key=1;
	root=insert(root,key);
	cout<<"\n\nInorder traversal of BST after inserting "<<key<<"\n";
	Inorder(root);
	return 0;
}





