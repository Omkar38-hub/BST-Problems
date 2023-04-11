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
	if(root==NULL)
	  return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
 
bool checkBST(Node *root,int &prev)
{
	if(root==NULL)
	  return true;
	if(checkBST(root->left,prev)==false)
	   return false;
	if(root->data<=prev)
	   return false;
	prev=root->data;
	return checkBST(root->right,prev);
}

int main()
{
	Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(30);
	root->right->left=new Node(18);
	root->right->right=new Node(35);
	cout<<"Inorder traversal of given BST is ";
	inorder(root);
	int prev=INT_MIN;
	if(checkBST(root,prev))
	  cout<<"\n\nGiven tree is BST";
	else
	  cout<<"\n\nGiven tree is not a BST";
	return 0;
}
// time complexity=O(n)
// space complexity=O(h)




