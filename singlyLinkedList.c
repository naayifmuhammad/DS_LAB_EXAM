#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *newnode,*head= NULL,*temp = NULL;

int isEmpty();
void readData();
void insertFront();
void insertPos();
void deleteFront();
void deletePos();
void display();

void main()
{
	int choice;
	printf("Linked list operation\n");
	do{
		printf("\n\n0. Exit 1. Insert at front 2. Insert at specific position 3. Delete at front 4.Delete at position\n");
		printf("Enter your desired operation:");
		scanf("%d",&choice);
	switch(choice)
	{
		case 0:
		printf("\nExiting the operation\n");
		return;
		break;
		case 1:
		readData();
		insertFront();		
		break;
		case 2:
		readData();
		insertPos();			
		break;
		case 3:
		deleteFront();
		break;
		case 4:
		deletePos();
		break;
		case 5:
		display();
		break;
		default:
		printf("\nEnter a valid operation\n");
	}
	temp = head;
	}
	while(choice!=0);	

}

void insertFront()
{
	if(isEmpty()){
		head = newnode;	
	}
	else{
		newnode->next= head;
		head = newnode;
	}
}

void insertPos()
{
	int pos,i=1;
	printf("Enter the position you want to insert the node at: ");
	scanf("%d",&pos);
	temp = head;
	if(pos<=1)
	{
		insertFront();
		return;
	}
	else if(pos == 2)
	{
		temp = head;
	}	
	else{
		
		while(i<pos-1)
		{
			temp=temp->next;
			if(temp == NULL)
			{
				printf("\n\nInsertion not possible at at position: Out of scope");
				return;
			}
		i++;
		}
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

void deleteFront(){
	struct node *ptr;
	if(isEmpty())
	{
		printf("List is empty: Deletion not possible");
		return;
	}
	temp = head;
	head = head->next;
	printf("\nDeleted element is [%d]",temp->data);
	free(temp);	
}

void deletePos()
{
	struct node *ptr;
	int pos,i=1;
	if(isEmpty())
	{
		printf("List is empty: Deletion not possible");
		return;
	}
	printf("Enter the position you want to Delete the node from: ");
	scanf("%d",&pos);
	if(pos<=1)
	{
		deleteFront();
		return;
	}
	else if(pos == 2)
	{
		ptr = head;
		temp = head->next;
	}	
	else{
		
		while(i<pos)
		{
			ptr = temp;
			temp=temp->next;
			if(temp == NULL)
			{
				printf("\n\nDeletion not possible at at position: Out of scope");
				return;
			}
		i++;
		}
	}
	ptr->next = temp->next;
	printf("\nDeleted element is [%d]",temp->data);	
	free(temp);
}

void display(){
	if(isEmpty())
	{
		printf("\n\nLinked list is empty\n");
		return;
	}
	printf("Linked List data is: ");
	while(temp!=NULL)
	{
		printf("  %d  ",temp->data);
		temp = temp->next;
	}
}

int isEmpty()
{
	if(head == NULL)
	{
		return 1;	
	}
	else
		return 0;
}

void readData()
{
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("\nEnter data for new node: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
}


