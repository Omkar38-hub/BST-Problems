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

bool search(Node *root,int key)
{
	while(root!=NULL){
	if(root->data==key)
	   return true;
	else if(root->data>key)
	   root=root->left;
	else
	   root=root->right;
    }
    return false;
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
	int key=12;
	cout<<"The Element "<<key<<" present in BST or not?\n";
	if(search(root,key))
	   cout<<"YES";
	else
	    cout<<"NO";
	return 0;
}





