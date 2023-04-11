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

void kSmallest(Node *root,int k,int &count)
{
	if(root==NULL)
	   return;
	kSmallest(root->left,k,count);
	count++;
	if(count==k)
	{
		cout<<root->data;
		return;
	}
	kSmallest(root->right,k,count);	
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
	int k=7;
	int count=0;
	cout<<"The "<<k<<"th smallest in the gven BST is ";
	kSmallest(root,k,count);
	return 0;
}
// time complexity=O(n)
// space complexity=O(h)




