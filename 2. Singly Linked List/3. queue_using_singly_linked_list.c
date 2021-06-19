#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))
int length=0;

struct node{
	int data;
	struct node *link;
};

void push(struct node **head, int value){
	struct node *temp;
	temp = allot;
	
	temp->data = value;
	temp->link = *head;
	
	*head = temp;
	length++;
}

void pop(struct node **head){
	struct node *ptr;
	ptr = *head;
	if(ptr->link==NULL){
		*head=NULL;
		return;
	}
	while(ptr->link->link!=NULL){
		ptr = ptr->link;
	}
	ptr->link = NULL;
}

void show(struct node **head){
	struct node *ptr;
	ptr = *head;
	printf("\n\t");
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}printf("\n");
}

int main(){
	int choice, value;
	struct node *head=NULL;
	
	while(true){
		printf("1. push\n2. pop\n3. show\n4. exit\nenter: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter value to push: ");
				scanf("%d", &value);
				push(&head, value);
				break;
			case 2:
				if(head==NULL){
					printf("\n\tEmpty Queue!\n");
					break;
				}
				pop(&head);
				break;
			case 3:
				if(head==NULL){
					printf("\n\tEmpty Queue!\n");
					break;
				}
				show(&head);
				break;
			case 4:
				exit(0);
			default:
				printf("\nenter valid choice\n");
		}
	}
}
