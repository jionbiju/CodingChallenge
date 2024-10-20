//Largeset and smallest element in a linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}*head=NULL,*new,*ptr;

void display(){
    ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

void isLargeOrSmall(){
    int max=head->data;
    int min=head->data;
    ptr=head;
    while(ptr!=NULL){
        if(ptr->data>max){
            max=ptr->data;
        }
        if(ptr->data<min){
            min=ptr->data;
        }
        ptr=ptr->next;
    }
    printf("Largest element is %d\n",max);
    printf("Smallest element is %d\n",min);
}
void main(){
    int ch;
    do{
        printf("Enter the element to be inserted\n");
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL){
            head=new;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new;
        }
        printf("Do you want to insert another element.\nYes-1\nNo-0\n");
        scanf("%d",&ch);
    }
    while(ch!=0);
    
    printf("Elements are:\n");
    display();
    printf("\n");
    isLargeOrSmall();
}
/*
OUTPUT
Enter the element to be inserted
44
Do you want to insert another element.
Yes-1
No-0
1
Enter the element to be inserted
7
Do you want to insert another element.
Yes-1
No-0
1
Enter the element to be inserted
74
Do you want to insert another element.
Yes-1
No-0
1
Enter the element to be inserted
90
Do you want to insert another element.
Yes-1
No-0
1
Enter the element to be inserted
23
Do you want to insert another element.
Yes-1
No-0
1 
Enter the element to be inserted
34
Do you want to insert another element.
Yes-1
No-0
0
Elements are:
44      7       74      90      23      34
Largest element is 90
Smallest element is 7
*/