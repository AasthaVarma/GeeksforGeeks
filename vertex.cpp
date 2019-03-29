//question - vertex cover problem

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	int c;
	Node *left, *right;
};
set<int> v;
Node *createNode(int item)
{
	Node *temp = new Node;
	temp->data = item;
	temp->c=0;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}
int solve(Node *root)
{
	if(root==NULL)
		return 0;
	if(!root->left && !root->right)
		return 0;
	
	if(root->c!=0)
		return root->c;
	int a = 1+solve(root->left)+solve(root->right);
	int b=0;
	if(root->left)
		b += 1+solve(root->left->left)+solve(root->left->right);
	if(root->right)
		b += 1+solve(root->right->left)+solve(root->right->right);
	
	int c = min(a, b);
	if(c==a)
	{
		v.insert(root->data);
	}
	return c;
}
void print()
{
	cout << endl;
	set<int>::iterator it;
	for(it=v.begin(); it!=v.end(); it++)
		cout << (*it) << " ";
	cout << endl;
}
int main()
{
	Node *root = createNode(10);
	root->left = createNode(20);
	root->right = createNode(30);
	root->left->left = createNode(40);
	root->left->right = createNode(50);
	root->left->right->left = createNode(70);
	root->left->right->right = createNode(80);
	root->right->right = createNode(60);
	
	cout << solve(root);
	print();
	return 0;
}
