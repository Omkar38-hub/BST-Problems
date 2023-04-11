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

void inorder(Node *root)
{
	if(!root)
	  return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void swapp(Node *root,Node **first,Node **second)
{
	if(root==NULL)
	  return;
	static Node *prev=NULL;
	swapp(root->left,first,second);
	if(prev!=NULL && root->data<prev->data)
	{
		if(*first==NULL)
		   *first=prev;
		*second=root;
	}
	prev=root;
	swapp(root->right,first,second);
}
int main()
{
	Node *root=new Node(20);
	root->left=new Node(60);
	root->right=new Node(80);
	root->left->left=new Node(4);
	root->left->right=new Node(10);
	root->right->left=new Node(18);
	root->right->right=new Node(100);
	//vector<int>v;
	cout<<"Inorder traversal of BST ";
	inorder(root);
	Node *first=NULL,*second=NULL;
	swapp(root,&first,&second);
	int t=first->data;
	first->data=second->data;
	second->data=t;
	cout<<"\n\nInorder traversal of BST ";
	inorder(root);
	return 0;
}
// time complexity=O(n)
// space complexity=O(h)




