//Palindrome using linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;

void isPalindrome(char str[20]){
    int flag=1;
    struct node*ptr,*new,*temp;
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
    temp=head;
    for(int i=0; i<l/2; i++){
        if(temp->data!=ptr->data){
            flag=0;
            break;
        }
        temp=temp->next;
        ptr=ptr->prev;
    }
    if(flag==0){
        printf("%s is not a palindrome.",str);
    }
    else{
        printf("%s is palindrome.",str);
    }
}

void main(){
    char c[20];
    printf("Enter a string\n");
    scanf("%[^\n]s",&c);
    isPalindrome(c);
}
/*
OUTPUT
Enter a string
malayalam
malayalam is palindrome.
Enter a string
123
123 is not a palindrome
*/