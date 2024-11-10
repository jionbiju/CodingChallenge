//Delete even numbers in the list.
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

void deleteEven(){
    struct node *prev=head,*curr=head,*temp;
    while(curr!=NULL){
        if(curr->data%2==0){
            if(curr==head){
                temp=head;
                head=head->next;
                curr=head;
                prev=curr;
                free(temp);
            }
            else{
                temp=curr;
                prev->next=curr->next;
                curr=curr->next;
                free(temp);
            }
        }
        else{
            prev=curr;
            curr=curr->next;
        }
        
    }

}

void main(){
insert();
printf("Elements are:");
display();
deleteEven();
printf("\nList after deleting even elements:");
display();
}

/*
OUTPUT
Enter the elments
1
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
2
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
3
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
4
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
5
Do you want to insert another element
1-Yes
 0-No
1
Enter the elments
6
Do you want to insert another element
1-Yes
 0-No
0
Elements are:1  2       3       4       5       6
List after deleting even elements:1     3       5
*/