#include<bits/stdc++.h>
using namespace std;
#define allot (struct node *)malloc(sizeof(struct node))
queue<struct node*> q;

struct node{
	struct node *left;
	int data;
	struct node *right;
};

struct node *getnode(int val){
	struct node *newNode = allot;
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void print_level_order(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d ", root->data);
	
	q.push(root->left); q.push(root->right);
	struct node *temp = q.front(); q.pop();
	print_level_order(temp);
}

int main(){
	struct node *n1 = getnode(1);
	struct node *n2 = getnode(2);
	struct node *n3 = getnode(3);
	struct node *n4 = getnode(4);
	struct node *n5 = getnode(5);
	struct node *n6 = getnode(6);
	struct node *n7 = getnode(7);
	
	n1->left = n2; n1->right = n3;
	n2->left = n4; n2->right = n5;
	n3->left = n6; n3->right = n7;
	print_level_order(n1);
	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	free(n7);
	
	return 0;
}
