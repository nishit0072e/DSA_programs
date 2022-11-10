#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
}*head,*newnode,*temp;
int pos;
int n;
int main()
{
	int num,choice;
		while(1){
	printf("\nENTER '1' TO CREATE LINKED LIST: \n");
	printf("\nENTER '2' TO ADD NODE AT BEGINNING:  \n");
	printf("\nENTER '3' TO ADD AT NODE THE END OF THE LIST: \n");
	printf("\nENTER '4' TO ADD NODE AT SPECIFIC POSITION: \n");
	printf("\nENTER '5' TO EXIT: \n");
	scanf("%d",&num);
	switch (num)
	{
	case 1:
	create(n);
	print();
	break;
	case 2:
	addbig();
	print();
	break;
	case 3:
	addend();
	print();
	break;
	case 4:
	addspecific(pos);
	print();
	break;
    case 5:
    	printf("bye bye :) !!");
    	exit(0);
    	break;
    default:
    	printf("WRONG CHOICE...!");
    }//end of switch statement
}//end of while
return 0;
}
void create(int n)
{
	printf("enter the length of the list: ");
	scanf("%d",&n);
	struct node *newnode;
	head=0;
int i;
	for(i=0;i<n;i++)
{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data of node: ");
	scanf("%d",&newnode->data);
	newnode->next=0;
if (head==0)
{
	head=temp=newnode;
}
else {temp->next=newnode;
temp=newnode;
}
}
}
void print()
{
	temp=head;
	printf("\nthe list is:  \n");
	while(temp!=0)
	{
		printf("%d\t  ",temp->data);
			temp=temp->next;
	}

}
void addbig()
{
	struct node *newnode;
	if (head==0)
	{
		printf("invalid position");
	}
	else
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\nenter the data of new beginning node: ");
		scanf("%d",&newnode->data);
		newnode->next=head;
		head=newnode;
	}
}
void addend()
{
	struct node *newnode;
	temp=head;
	if(head==0)
	{
		printf("invalied position");
	}
	else{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nenter the data of new last node: ");
		scanf("%d",&newnode->data);
		newnode->next=0;
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void addspecific(int pos)
{
	int j;
	printf("\nenter position of newnode:  ");
	scanf("%d",&pos);
	struct node *newnode;
	if (pos == 0)
	{
		printf("invalid position");
	}
	else{
		temp=head;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nenter the data of newnode:  ");
		scanf("%d",&newnode->data);
		for(j=0;j<pos-2;j++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}