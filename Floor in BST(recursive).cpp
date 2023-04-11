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

Node *floor(Node *root,int key)
{
	static Node *res=NULL;
	if(root==NULL)
	   return res;
	else if(root->data>key)
	   floor(root->left,key);
	else if(root->data<key)
	{
		res=root;
		floor(root->right,key);
	}
	else
	  return root;
	return res;
}
int main()
{
	Node *root=new Node(5);
	root->left=new Node(3);
	root->right=new Node(7);
	root->left->left=new Node(2);
	root->left->right=new Node(4);
	root->right->left=new Node(6);
	root->right->right=new Node(9);
	int key=8;
	cout<<"The floor of BST is \n";
	if(floor(root,key)==NULL)
	  cout<<"there is no floor\n";
	else
	 cout<<floor(root,key)->data<<"\n";
	return 0;
}





