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


void vertical(Node *root,int ht,map<int,vector<int>>&mp)
{
	if(root==NULL)
	  return;
	mp[ht].push_back(root->data);
	vertical(root->left,ht-1,mp);
	vertical(root->right,ht+1,mp);
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
	cout<<"The vertical traversal of BST\n";
	map<int,vector<int>>mp;
	vertical(root,0,mp);
	for(auto i=mp.begin();i!=mp.end();i++)
	{
		vector<int>v=i->second;
		for(auto x: v)
		  cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
// time complexity=O(n)
// space complexity=O(h)




