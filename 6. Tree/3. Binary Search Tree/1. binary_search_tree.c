#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define COUNT 10

struct bstNode{
	struct bstNode *left;
	int data;
	struct bstNode *right;
};

struct bstNode* allot(int value){
	struct bstNode *newNode;
	newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void print2DUtil(struct bstNode *root, int space){
	int i;
    // Base case
    if (root == NULL){
//    	printf("\n\t\tEmpty Tree!\n");
    	return;
	}
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for(i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct bstNode *root){
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

struct bstNode* insert(struct bstNode *root, int value){
	struct bstNode *newNode;
	newNode = allot(value);
	
	if(root==NULL){
		root = newNode;
		return root;
	}
	else if(value <= root->data){
		root->left = insert(root->left, value);
		return root;
	}
	else{
		root->right = insert(root->right, value);
		return root;
	}
}

int main(){
	int choice, value;
	struct bstNode *root = NULL;
	
	while(true){
		printf("1. insert\n2. delete\n3. show\n4. exit\nenter: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter value to insert: ");
				scanf("%d", &value);
				root = insert(root, value);
				break;
			case 2:
				break;
			case 3:
				print2D(root);
				printf("\n\n");
				break;
			case 4:
				exit(0);
			default:
				printf("\n\t\tenter valid choice!\n");
		}
	}
	return 0;
}
