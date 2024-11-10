//Two variable polynomial addition using linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
    int coeff;
    int expoX,expoY;
    struct node *link;
};
struct node *phead,*qhead,*rhead;

struct node * readPoly(){
    struct node *new,*ptr,*head=NULL;
    int n;
    printf("Enter the number of terms in the Polynomial:\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the coeff ,expoX and expoY of term %d\n",i+1);
        scanf("%d%d%d",&new->coeff,&new->expoX,&new->expoY);
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
    return head;
}

void display(struct node *head){
    if(head==NULL){
        printf("Empty");
        return;
    }
    else{
     struct node *ptr;
     ptr=head;
        while(ptr->link!=NULL){
               printf("%dX^%dY^%d + ",ptr->coeff,ptr->expoX,ptr->expoY);
               ptr=ptr->link;
        }
         printf("%dX^%dY^%d ",ptr->coeff,ptr->expoX,ptr->expoY);
    }
}

struct node * addPoly(){
    struct node *p,*q,*r,*head=NULL,*new;
    p=phead;
    q=qhead;
    while(p!=NULL && q!=NULL){
        if(p->expoX == q->expoX && p->expoY==q->expoY){
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=p->coeff+q->coeff;
            new->expoX=p->expoX;
            new->expoY=p->expoY;
            new->link=NULL;
            p=p->link;
            q=q->link;
        }
        else if(p->expoX>q->expoX || (p->expoX==q->expoX && p->expoY >q->expoY)){
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=p->coeff;
            new->expoX=p->expoX;
            new->expoY=p->expoY;
            new->link=NULL;
            p=p->link;
        }
        else{
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=q->coeff;
            new->expoX=q->expoX;
            new->expoY=q->expoY;
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
        new->expoX=p->expoX;
        new->expoY=p->expoY;
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
        new->expoX=q->expoX; 
        new->expoY=q->expoY; 
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