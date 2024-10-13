//Addition of Polynomial using Linked List.
#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff,expo;
    struct node *link;
};
struct node *phead,*qhead,*rhead;

struct node *readPoly(){
    struct node *new,*ptr,*head=NULL;
    int n;
    printf("Enter the number of terms in the polynomial:\n");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        printf("Enter coeff and expo of term %d\n",i);
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d%d",&new->coeff,&new->expo);
        new->link=NULL;
        if(head==NULL){
            head=new;
            ptr=head;
        }
        else{
            ptr->link=new;
            ptr=new;
        }
    }
    return(head);
}

void display(struct node *head){
    struct node *ptr;
    if(head==NULL){
        printf("Polynomial is Empty\n");
    }
    else{
        ptr=head;
        while(ptr->link!=NULL){
            if(ptr->expo>1){
               printf("%dX^%d + ",ptr->coeff,ptr->expo);
               ptr=ptr->link;
            }
            else if(ptr->expo==1){
                printf("%dX + ",ptr->coeff);
                ptr=ptr->link;
            }
            else{
               printf("%d + ",ptr->coeff);
               ptr=ptr->link; 
            }
        }
        if(ptr->expo>1){
            printf("%dX^%d ",ptr->coeff,ptr->expo);
        }
        else if(ptr->expo==1){
            printf("%dX ",ptr->coeff);
            ptr=ptr->link;
        }
        else{
            printf("%d ",ptr->coeff);
        }
    }
}

struct node * addPoly(){
    struct node *p,*q,*r,*head=NULL,*new;
    p=phead;
    q=qhead;
    while(p!=NULL && q!=NULL){
        if(p->expo == q->expo){
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=p->coeff+q->coeff;
            new->expo=p->expo;
            new->link=NULL;
            p=p->link;
            q=q->link;
        }
        else if(p->expo>q->expo){
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=p->coeff;
            new->expo=p->expo;
            new->link=NULL;
            p=p->link;
        }
        else{
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=q->coeff;
            new->expo=q->expo;
            new->link=NULL;
            q=q->link;
        }
        if(head==NULL){
            head=new;
            r=head;
        }
        else{
            r->link=new;
            r=r->link;
        }
    }
    while(p!=NULL){
        new=(struct node*)malloc(sizeof(struct node));
        new->coeff=p->coeff;
        new->expo=p->expo;
        new->link=NULL;  
        if(head==NULL){
            head=new;
            r=head;
        }
        else{
            r->link=new;
            r=r->link;
        }
        p=p->link;
    }
    while(q!=NULL){
        new=(struct node*)malloc(sizeof(struct node));
        new->coeff=q->coeff;
        new->expo=q->expo; 
        new->link=NULL;
        if(head==NULL){
            head=new;
            r=head;
        }
        else{
            r->link=new;
            r=r->link;
        }
        q=q->link;
    }
    return(head);
}

void main(){
    phead=readPoly();
    qhead=readPoly();
    printf("\nFirst Polynomial is ");
    display(phead);
    printf("\nSecond Polynomial is ");
    display(qhead);
    rhead=addPoly();
    printf("\nResultant Polynomial is: ");
    display(rhead);
}
/*
OUTPUT
Enter the number of terms in the polynomial:
4
Enter coeff and expo of term 1
4
3
Enter coeff and expo of term 2
5
2
Enter coeff and expo of term 3
4
1
Enter coeff and expo of term 4
3
0
Enter the number of terms in the polynomial:
2
Enter coeff and expo of term 1
2
2
Enter coeff and expo of term 2
4
1

First Polynomial is 4X^3 + 5X^2 + 4X + 3
Second Polynomial is 2X^2 + 4X
Resultant Polynomial is: 4X^3 + 7X^2 + 8X + 3
*/