#include<bits/stdc++.h>
using namespace std;
#define allot (struct node *)malloc(sizeof(struct node))

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

void iter_show(struct node *root){
	stack<struct node*> stack;
	while(true){
		while(root!=NULL){
			printf("%d ", root->data);
			stack.push(root);
			root = root->left;
		}
		if(stack.empty())
			break;
			
		root = stack.top(); stack.pop(); 
		root = root->right;
	}
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
	iter_show(n1);
	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	free(n7);
	
	return 0;
}
