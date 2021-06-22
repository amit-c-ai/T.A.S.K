#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))

struct node{
	int data;
	struct node *next;
};

void push(struct node **head, int value){
	struct node *temp, *ptr;
	temp = allot;
	temp->data = value;
	if(*head==NULL){
		*head = temp;
		temp->next = *head;
		return;
	}
	ptr = *head;
	while(ptr->next!=*head){
		ptr = ptr->next;
	}
	temp->next = *head;
	*head = temp;
	ptr->next = *head;
}

void pop(struct node **head){
	struct node *last, *ptr;
	last = *head;
	ptr = *head;	
	if(ptr->next==*head){
		*head = NULL;
		return;
	}
	while(last->next!=*head){
		last = last->next;
	}
	*head = ptr->next;
	last->next = *head;
}

void show(struct node **head){
	struct node *ptr;
	ptr = *head;
	printf("\n\t");
	while(ptr->next!=*head){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}printf("%d\n", ptr->data);
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
