#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))

struct node{
	struct node *left;
	int data;
	struct node *right;
};

struct node *getnode(int value){
	struct node *newNode;
	newNode = allot;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void recur_show(struct node *root){
	if(root==NULL){
		return;
	}
	recur_show(root->left);
	
	printf("%d ", root->data);
	
	recur_show(root->right);
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
	recur_show(n1);
	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	free(n7);
	
	return 0;
}
