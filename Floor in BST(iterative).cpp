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
	Node *res=NULL;
	while(root!=NULL)
	{
		if(root->data==key)
		  return root;
		else if(root->data>key)
		  root=root->left;
		else if(root->data<key)
		{
			res=root;
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
	cout<<"The floor of BST is \n";
	if(floor(root,key)==NULL)
	  cout<<"there is no floor\n";
	else
	 cout<<floor(root,key)->data<<"\n";
	return 0;
}





