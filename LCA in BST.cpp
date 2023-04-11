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

Node *LCA(Node *root,int n1,int n2)
{
	if(root==NULL)
	  return NULL;
	if(root->data>n1 && root->data>n2)
	    return LCA (root->left,n1,n2);
	if(root->data<n1 && root->data<n2)
	    return LCA (root->right,n1,n2);
	return root;	
}

int main()
{
	Node *root=new Node(50);
	root->left=new Node(20);
	root->right=new Node(100);
	root->left->left=new Node(10);
	root->left->right=new Node(40);
	root->right->left=new Node(70);
	root->right->right=new Node(120);
	root->right->left->left=new Node(60);
	root->right->left->right=new Node(80);
	int n1=60,n2=80;
	cout<<"The LCA of "<<n1<<" and "<<n2<<" is "<<LCA (root,n1,n2)->data;
	return 0;
}
// time complexity=O(n)
// space complexity=O(h)




