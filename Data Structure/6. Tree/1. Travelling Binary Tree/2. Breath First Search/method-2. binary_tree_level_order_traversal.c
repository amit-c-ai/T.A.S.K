//using queue
#include<stdio.h>
#include<stdlib.h>
#define allot (struct node *)malloc(sizeof(struct node))
#define MAX_Q_SIZE 500

struct node{
	struct node *left;
	int data;
	struct node *right;
};

struct node **createQ(int *, int *);
void enqueue(struct node **, int *, struct node *);
struct node *dequeue(struct node **, int *);

void print_level_order(struct node *root){
	int rear, front;
	struct node **queue = createQ(&rear, &front);
	struct node *temp = root;
	
	while(temp){
		printf("%d ", temp->data);
		
		if(temp->left)
			enqueue(queue, &rear, temp->left);
		
		if(temp->right)
			enqueue(queue, &rear, temp->right);
			
		temp = dequeue(queue, &front);
	}
}

struct node **createQ(int *rear, int *front){
	struct node **queue = (struct node**)malloc(sizeof(struct node)*MAX_Q_SIZE);
	*front = *rear = 0;
	return queue;
}

void enqueue(struct node **queue, int *rear, struct node *new_node){
	queue[*rear] = new_node;
	(*rear)++;
}

struct node *dequeue(struct node **queue, int *front){
	(*front)++;
	return queue[(*front)-1];
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
