#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	int height;
	Node *left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
		height=1;
	}
};
int height(Node *root)
{
	if(root==NULL)
	  return 0;
	else
	   return root->height;
}
int getBalance(Node *root)
{
	if(!root)
	   return 0;
	return height(root->left)-height(root->right);
}
Node *rightRotate(Node *x)
{
	Node *y=x->left;
	Node *t=y->right;
	//rotate
	y->right=x;
	x->left=t;
	x->height=1+max(height(x->left),height(x->right));
	y->height=1+max(height(y->left),height(y->right));
	return y;
}
Node *leftRotate(Node *x)
{
	Node *y=x->right;
	Node *t=y->left;
	//rotate
	y->left=x;
	x->right=t;
	x->height=1+max(height(x->left),height(x->right));
	y->height=1+max(height(y->left),height(y->right));
	return y;
}
Node *insert(Node *root,int key)
{
	if(root==NULL)
	  return new Node(key);
	else if(root->data>key)
	   root->left=insert(root->left,key);
	else if(root->data<key)
	   root->right=insert(root->right,key);
	else
	    return root;
	root->height=1+max(height(root->left),height(root->right));
	int balance=getBalance(root);
	// right right case
	if(balance<-1 &&key>root->right->data)
	  return leftRotate(root);
	// left left case
	if(balance>1 &&key<root->left->data)
	  return rightRotate(root);
	// right left case
	if(balance<-1 && key<root->left->data)
	{
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	// left right
	if(balance>1 && key>root->right->data) 
	{
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	return root;
}
void inOrder(Node *root)
{
	if(!root)
	  return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
int main()
{
	Node *root=NULL;
	root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Inorder traversal of the constructed AVL tree is \n";
    inOrder(root);
    return 0;
}
