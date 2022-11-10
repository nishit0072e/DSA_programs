#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *previous;
    struct node *next;
};
struct node *head, *tail = NULL;
void create_node(int data){
   int n;
   printf("Enter length of list: \n");
   scanf("%d",&n);
   for(int i = 0;i<n;i++){
     printf("Enter data of newnode: ");
    scanf("%d",&data);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL){
        head = tail = newnode;
        head->previous = NULL;
        tail->next = NULL;
    }
    else{
        tail->next = newnode;
        newnode->previous = tail;
        tail = newnode;
        tail->next = NULL; 
    }
   }
}
void add_beg(int data){
    printf("Enter data to be stored in beginning node: ");
    scanf("%d",&data);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    head->previous = newnode;
    newnode->next = head;
    newnode->previous = NULL;

    head = newnode;
}
void add_end(int data){
    printf("Enter data to be stored at end node: ");
    scanf("%d",&data);
    
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    tail->next = ptr;
    ptr->previous = tail;
    ptr->next = NULL;

    tail=ptr;
}
void specific(int data){
    int pos;
    printf("position: ");
    scanf("%d",&pos);
    printf("Enter data to be added at newnode at %d: ",pos);
    scanf("%d",&data);
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *temp = head;
    // while(pos != 1){
    //     temp = temp->next;
    //     pos--;
    // }
    for(int i = 0;i<pos;i++){
        temp = temp->next;
        if(temp == NULL){
            printf("impossible");
            return;
        }
        struct node *dummy;
        dummy=temp->previous;

        ptr->previous=dummy;
        dummy->next=ptr;
        printf("\nb4 assignment done");

        temp->previous=ptr;
        ptr->next=temp;
        printf("\nafter assignment done");



        //temp->previous = ptr;
        //ptr->next = temp;
        //temp = head;
        //ptr->previous = temp->previous;
        //temp->next = ptr;
    //     ptr->next = temp;
    //     temp->previous = ptr->previous;
    //     head->next = ptr;
    //     temp->previous = ptr;
    }
}
void print_list(){
    struct node *current = head;
    if(head == NULL){
        printf("list is empty");
    }
    else{
        printf("list elements are: \n");
        while(current != NULL){
            printf("%d\t",current->data);
            current = current->next;
        }
    }
    
}
int main(){
    int choice,data;
    while(1){
        printf("\n1. for create node\n");
        printf("\n2. for add node in beginning\n");
        printf("\n3. for add node in end\n");
        printf("\n4. for add node in specific position\n");
        printf("\n5. for displaying elements\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            create_node(data);
            print_list();
            break;
            case 2:
            add_beg(data);
            print_list();
            break;
            case 3:
            add_end(data);
            print_list();
            break;
            case 4:
            specific(data);
            print_list();
            break;
            case 5:
            print_list();
            break;
            case 6:
            printf("bye bye :) ....!!");
            exit(0);
            break;
            default:
            printf("Invalid command input");
        }
    }
}