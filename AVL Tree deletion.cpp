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
Node *successor(Node *root)
{
	Node *curr=root->right;
	while(curr!=NULL && curr->left!=NULL)
	   curr=curr->left;
	return curr;
}
Node *deleted(Node *root,int key)
{
	if(root==NULL)
	  return root;
	else if(root->data>key)
	   root->left=deleted(root->left,key);
	else if(root->data<key)
	   root->right=deleted(root->right,key);
	else
	{
		if((root->left == NULL) ||(root->right == NULL)) 
        { 
            Node *temp = root->left ? root->left : root->right; 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
            *root = *temp; // Copy the contents of 
                          // the non-empty child 
            free(temp); 
        }
		else
		{
			Node *succ=successor(root);
			root->data=succ->data;
			root->right=deleted(root->right,succ->data);
		} 
	}
	root->height=1+max(height(root->left),height(root->right));
	int balance=getBalance(root);
	// right right case
	if(balance<-1 &&getBalance(root->right)<=0)
	  return leftRotate(root);
	// left left case
	if(balance>1 &&getBalance(root->left)>=0)
	  return rightRotate(root);
	// right left case
	if(balance<-1 && getBalance(root->right)>0)
	{
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	// left right
	if(balance>1 && getBalance(root->left)<0) 
	{
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	return root;
}
int main()
{
	Node *root=NULL;
	root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 
    cout << "Inorder traversal of the constructed AVL tree is \n";
    inOrder(root);
    int key=10;
    root = deleted(root, key);
    cout<<"\n\nInorder traversal after deleting "<<key<<"\n";
    inOrder(root);
    return 0;
}
