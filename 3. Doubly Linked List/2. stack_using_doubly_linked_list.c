#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void push(struct node **head, int value){
	struct node *temp, *ptr;
	ptr = *head;					//ptr is similar to old head
	temp = allot;
	
	temp->prev = NULL;
	temp->data = value;
	temp->next = NULL;
	
	if(*head==NULL){
		*head = temp;
		return;
	}
	
	temp->next = ptr;
	ptr->prev = temp;				//linking prev of old head to new head
	*head = temp;					//head now points to temp(newly added node) 
}

void pop(struct node **head){
	struct node *ptr;
	ptr = *head;
	*head = ptr->next;
}

void show(struct node **head){
	struct node *ptr;
	ptr = *head;
	printf("\n\t");
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}printf("\n");
}

int main(){
	int choice, value;
	struct node *head=NULL, *tail=NULL;
	
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
					printf("\n\t\tEmpty Stack!\n");
					break;
				}
				pop(&head);
				break;
			case 3:
				if(head==NULL){
					printf("\n\t\tEmpty Stack!\n");
					break;
				}
				show(&head);
				break;
			case 4:
				exit(0);
			default:
				printf("\n\t\tenter valid choice!\n");
		}
	}
	return 0;
}
