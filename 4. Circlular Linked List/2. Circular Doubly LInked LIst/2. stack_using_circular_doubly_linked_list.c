#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void push(struct node **head, struct node **tail, int value){
	struct node *temp, *ptr, *last;
	temp = allot;
	temp->data = value;
	
	if(*head==NULL){
		*head = temp;
		temp->prev = *head;
		temp->next = *head;
		*tail = *head;
		return;
	}
	ptr = *head;
	temp->next = *head;
	ptr->prev = temp;
	
	ptr = *tail;
	temp->prev = *tail;
	*head = temp;
	ptr->next = *head;
}

void pop(struct node **head, struct node **tail){
	struct node *ptr;
	ptr = *head;
	
	if(ptr->next==*head){
		*head = NULL;
		return;
	}
	*head = ptr->next;
	ptr = *head;
	ptr->prev = *tail;
	ptr = *tail;
	ptr->next = *head;
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
	struct node *head=NULL, *tail=NULL;
	
	while(true){
		printf("1. push\n2. pop\n3. show\n4. exit\nenter: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter value to push: ");
				scanf("%d", &value);
				push(&head, &tail, value);
				break;
			case 2:
				if(head==NULL){
					printf("\n\t\tEmpty Stack!\n");
					break;
				}
				pop(&head, &tail);
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
