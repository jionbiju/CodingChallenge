//Reverse a string using linked list.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void reverse(char str[20]){
    struct node*ptr,*new;
    int l=strlen(str);
    for(int i=0; i<l; i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->data=str[i];
        new->next=NULL;
        new->prev=NULL;
        if(head==NULL){
            head=new;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new;
            new->prev=ptr;
        }
    }
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    while(ptr!=NULL){
        printf("%c",ptr->data);
        ptr=ptr->prev;
    }
}


void main(){
char str[20];
printf("Enter a string\n");
scanf("%[^\n]s",&str);
printf("Reverse of the string is:\n");
reverse(str);
}
/*
OUTPUT
Enter a string
hello world
Reverse of the string is:
dlrow olleh
*/