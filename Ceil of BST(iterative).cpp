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

Node *ceil(Node *root,int key)
{
	Node *res=NULL;
	while(root!=NULL)
	{
		if(root->data==key)
		  return root;
		else if(root->data>key)
		{
			res=root;
			root=root->left;
		}
		else if(root->data<key)
		{
			root=root->right;
		}
	}
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
	root->right->right=new Node(8);
	int key=1;
	cout<<"The Ceil of "<<key<<" in BST is \n";
	if(ceil(root,key)==NULL)
	  cout<<"there is no ceil\n";
	else
	 cout<<ceil(root,key)->data<<"\n";
	return 0;
}





