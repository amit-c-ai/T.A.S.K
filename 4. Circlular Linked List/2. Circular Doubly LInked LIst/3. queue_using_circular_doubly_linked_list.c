#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void push(struct node **tail, struct node **head, int value){
	struct node *temp, *ptr;
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
	*head = temp;
	
	ptr = *tail;
	temp->prev = *tail;
	ptr->next = *head;
}

void pop(struct node **tail, struct node **head){
	struct node *ptr, *new_last;
	ptr = *head;
	
	if(ptr->next==*head){
		*head=NULL;
		return;
	}
	new_last = *tail;
	new_last = new_last->prev;
	new_last->next = *head;
	*tail = new_last;
	ptr->prev = *tail;
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
				push(&tail, &head, value);
				break;
			case 2:
				if(head==NULL){
					printf("\n\t\tEmpty Queue!\n");
					break;
				}
				pop(&tail, &head);
				break;
			case 3:
				if(head==NULL){
					printf("\n\t\tEmpty Queue!\n");
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
