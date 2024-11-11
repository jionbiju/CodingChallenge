//Sorting a linked list.
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;

void insert(){
int ch;
struct node *ptr,*new;
do{
printf("Enter the elments\n");
new =(struct node *)malloc(sizeof(struct node));
scanf("%d",&new->data);
new->next=NULL;
if(head==NULL){
    head=new;
    ptr=head;
}
else{
    ptr->next=new;
    ptr=new;
}
printf("Do you want to insert another element \n1-Yes\n 0-No\n");
scanf("%d",&ch);
}
while(ch!=0);
}
void display(){
    struct node *ptr=head;
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    else{
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}

void sort(){
    struct node *ptr1=head,*ptr2;
    int temp;
    while(ptr1!=NULL){
        ptr2=ptr1->next;
        while(ptr2!=NULL){
            if(ptr1->data>ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
   
}

void main(){
insert();
printf("Elements before sorting:");
display();
sort();
printf("\nList Elements after sorting:");
display();
}
/*
OUTPUT
Enter the elments
5
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
8
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
44
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
6
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
2
Do you want to insert another element
1-Yes
 0-No
0
Elements before sorting:5       8       44      6       2
List Elements after sorting:2   5       6       8       44
*/