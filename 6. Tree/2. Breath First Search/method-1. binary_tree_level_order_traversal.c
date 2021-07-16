#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))

struct node{
	struct node *left;
	int data;
	struct node *right;
};

void print_curr_level(struct node* root, int level);
int height(struct node *root);
struct node *getnode(int value);


void print_level_order(struct node *root){
	int i, h;
	h = height(root);
	for(i=1; i<=h; i++){
		print_curr_level(root, i);
	}
}

void print_curr_level(struct node *root, int level){
	if(level==0){
		return;
	}
	else if(level==1){
		printf("%d ", root->data);
	}
	else if(level>1){
		print_curr_level(root->left, level-1);
		print_curr_level(root->right, level-1);
	}
}

int height(struct node *node){
	if(node==NULL){
		return 0;
	}
	else{
		int lheight = height(node->left);
		int rheight = height(node->right);
		
		if(lheight>rheight)
			return lheight+1;
		return rheight+1;
	}
}

struct node *getnode(int value){
	struct node *newNode;
	newNode = allot;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
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
