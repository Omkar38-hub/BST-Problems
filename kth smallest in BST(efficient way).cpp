#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data,lcount;
	struct Node *left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
		lcount=0;
	}
};

void kSmallest(Node *root,int k)
{
	if(root==NULL)
	   return;
	if((root->lcount)+1==k)
	{
		cout<<root->data<<" ";
		return;
	}
	else if((root->lcount)+1>k)
	    kSmallest(root->left,k);
	else
	    kSmallest(root->right,k-((root->lcount)+1));
}
Node *insert(Node *root,int key)
{
	if(root==NULL)
	   return new Node(key);
	else if(root->data>key)
	{
		root->left=insert(root->left,key);
		root->lcount+=1;
	}
	else if(root->data<key)
	    root->right=insert(root->right,key);
	return root;
}
void inorder(Node *root)
{
	if(root==NULL)
	  return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
	Node *root=NULL;
	root=insert(root,50);
	root=insert(root,20);
	root=insert(root,100);
	root=insert(root,10);
	root=insert(root,30);
	root=insert(root,70);
	root=insert(root,120);
	root=insert(root,4);
	root=insert(root,80);
	cout<<"Inorder traversal of given BST is ";
	inorder(root);
	int k=5;
	cout<<"\n\nThe "<<k<<"th smallest in the given BST is ";
	kSmallest(root,k);
	return 0;
}
// time complexity=O(h)
// space complexity=O(h)




