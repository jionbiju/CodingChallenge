#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *head = NULL; 
void insertAtFront() {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for the node: ");
    scanf("%d", &new->data);
    if(head == NULL){
    head=new;
    head->link =NULL;
    }
    else{
    new->link = head;
    head= new;
    };
}
void insertAtEnd() {
    struct node *temp,*new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for the node: ");
    scanf("%d", &new->data);
    new->link = NULL;
    if (head == NULL) {
        head = new;
    } else {
        temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new;
    }
}
void insertAtPosition() {
    int pos;
    struct node *temp,*new;
    printf("Enter the key (position value) after which to insert: ");
    scanf("%d", &pos);
    temp = head;
    while (temp != NULL && temp->data != pos) {
        temp = temp->link;
    }
    
    if (temp == NULL) {
        printf("Position not found.\n");
        return;
    }
new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for the node: ");
    scanf("%d", &new->data);
    new->link = temp->link;
    temp->link = new;
}
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("Node Values are:\n");
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
void deleteAtFront() {
    struct node *temp ;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->link==NULL){
    temp=head;
    head->link=NULL;
    free(temp);
    }
    else{
    temp=head;
    printf("Deleted element is %d",temp->data);
    head=head->link;
    free(temp);
    }
    
}
void deleteAtEnd() {
    struct node *temp,*prev,*curr;
    if(head==NULL){
    printf("List is empty\n");
    }
    else if(head->link==NULL){
    temp=head;
    printf("Deleted element is %d",temp->data);
    head=NULL;
    free(temp);
    }
    else{
    prev=head;
    curr=head;
    while(curr->link != NULL){
    prev=curr;
    curr=curr->link;
    }
    printf("Deleted element is %d",curr->data);
    prev->link=NULL;
    free(curr);
    }
}

void deleteAtPosition() {
    int pos;
    printf("Enter the element to be deleted: ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *curr = head, *prev = NULL;
    if (head->data == pos) {
        head = head->link;
        printf("Deleted element is %d\n", curr->data);
        free(curr);
        return;
    }
     while (curr != NULL && curr->data != pos) {
        prev = curr;
        curr = curr->link;
    }
    if (curr == NULL) {
        printf("Element %d not found in the list\n", pos);
        return;
    }
    prev->link = curr->link;
    printf("Deleted element is %d\n", curr->data);
    free(curr);
}

int main() {
    int ch;
    do {
        printf("\nEnter your choice:\n");
        printf("1 - Insertion\n");
        printf("2 - Deletion\n");
        printf("3 - Display\n");
        printf("4 - Exit\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("1 - Insert at Beginning\n");
                printf("2 - Insert at End\n");
                printf("3 - Insert at a specified position\n");
                scanf("%d", &ch);
                switch (ch) {
                    case 1: insertAtFront(); break;
                    case 2: insertAtEnd(); break;
                    case 3: insertAtPosition(); break;
                    default: printf("Invalid choice\n");
                }
                break;
                
            case 2:
                printf("1 - Delete at Beginning\n");
                printf("2 - Delete at End\n");
                printf("3 - Delete at a specified position\n");
                scanf("%d", &ch);
                switch (ch) {
                    case 1: deleteAtFront(); break;
                    case 2: deleteAtEnd(); break;
                    case 3: deleteAtPosition(); break;
                    default: printf("Invalid choice\n");
                }
                break;
                
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 4);
    
    return 0;
}