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


bool pairSum(Node *root,int sum,unordered_set<int>&s)
{
	if(root==NULL)
	  return false;
	if(pairSum(root->left,sum,s)==true)
	  return true;
	if(s.find(sum-root->data)!=s.end())
	   return true;
	else
	   s.insert(root->data);
	return pairSum(root->right,sum,s);
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
	int sum=30;
	unordered_set<int>s;
	if(pairSum(root,sum,s))
	  cout<<"yes given "<<sum<<" present in BST\n";
	else
	   cout<<"sum Not present in BST";
	return 0;
}
// time complexity=O(n)
// space complexity=O(n)




