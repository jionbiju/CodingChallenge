//Binary tree operations such as insertion, deletions and traversal.
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};struct node *root=NULL;

void insertion(){
struct node *new,*ptr,*parent=NULL;
int item;
printf("Enter the element to be inserted\n");
scanf("%d",&item);
if(root==NULL){
new=(struct node*)malloc(sizeof(struct node));
root=new;
new->data=item;
new->left=NULL;
new->right=NULL;
}
else{
    ptr=root;
    while(ptr!=NULL){
        if(item<ptr->data){
            parent=ptr;
            ptr=ptr->left;
        }
        else if(item>ptr->data){
            parent=ptr;
            ptr=ptr->right;
        }
        else{
            printf("Element already exist\n");
            return;
        }
    }
    if(ptr==NULL){
        new=(struct node*)malloc(sizeof(struct node));
        new->data=item;
        new->left=NULL;
        new->right=NULL;
        if(item<parent->data){
            parent->left=new;
        }
        else{
            parent->right=new;
        }
    }
}
}

void preorder(struct node *root){
if(root==NULL)
return;
printf("%d\t",root->data);
preorder(root->left);
preorder(root->right);
}

void inorder(struct node *root){
if(root==NULL)
return;
inorder(root->left);
printf("%d\t",root->data);
inorder(root->right);
}

void postorder(struct node *root){
if(root==NULL)
return;
postorder(root->left);
postorder(root->right);
printf("%d\t",root->data);
}

void search(){
    struct node *ptr;
    int key;
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    ptr=root;
    while( ptr!=NULL && ptr->data!=key){
        if(key<ptr->data){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    if(ptr==NULL){
    printf("Element not found\n");
    return;
    }
    else{
    printf("Element founded\n");
    return;
    }
}
struct node *minValueNode(struct node *temp){
    struct node *current=temp;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

void delete(int key){
    struct node *ptr,*parent=NULL,*minNode;
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }
    else{
        ptr=root;
        while(ptr!=NULL && ptr->data!=key){
            if(key<ptr->data){
            parent=ptr;
            ptr=ptr->left;
        }
        else if(key>ptr->data){
            parent=ptr;
            ptr=ptr->right;
        }
        }
        if(ptr==NULL){
            printf("Element not found\n");
            return;
        }
        else if(ptr->right==NULL && ptr->left==NULL){
            if(parent->right==ptr){
                parent->right=NULL;
            }
            else{
                parent->left=NULL;
            }
            free(ptr);
            printf("Element deleted");
        }
        else if(ptr->left!=NULL && ptr->right!=NULL){
            minNode=minValueNode(ptr->right);
            int minValue=minNode->data;
            delete(minValue);
            ptr->data=minValue;
            
        }
        else{
            if(ptr->right!=NULL){
                if(parent->right==ptr){
                    parent->right=ptr->right;
                }
                else{
                    parent->left=ptr->right;
                }
            }
            else{
                if(parent->right==ptr){
                    parent->right=ptr->left;
                }
                else{
                    parent->left=ptr->left;
                }
            }
            printf("Element deleted");
        }
    }
}


void main(){
    int ch,key;
    do{
    printf("\n1-Insertion\n");
    printf("2-Deletion\n");
    printf("3-Search\n");
    printf("4-Traversal\n");
    printf("5-Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:insertion();
               break;
        case 2: printf("Enter the element to be deleted\n");
                scanf("%d",&key);
                delete(key);
                break;
        case 3: search();
                break;
        case 4:printf("1-PreOrder\n");
               printf("2-InOrder\n");
               printf("3-PostOrder\n");
               printf("Enter your choice\n");
               scanf("%d",&ch);
               switch(ch){
                case 1: printf("PreOrder is: ");
                        preorder(root);
                        break;
                case 2: printf("InOrder is: ");
                        inorder(root);
                        break;
                case 3: printf("PostOrder is: ");
                        postorder(root);
                        break;
               }
               break;
    }
    }while(ch!=5);
    
}
/*
OUTPUT
1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
40

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
50

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
45

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
60

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
55

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
70

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
30

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
35

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
25

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
28

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
1
Enter the element to be inserted
15

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
4
1-PreOrder
2-InOrder
3-PostOrder
Enter your choice
1
PreOrder is: 40 30      25      15      28      35      50      45      60      55      70
1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
4
1-PreOrder
2-InOrder
3-PostOrder
Enter your choice
2
InOrder is: 15  25      28      30      35      40      45      50      55      60      70
1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
4
1-PreOrder
2-InOrder
3-PostOrder
Enter your choice
3
PostOrder is: 15        28      25      35      30      45      55      70      60      50      40
1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
2
Enter the element to be deleted
50
Element deleted
1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
4
1-PreOrder
2-InOrder
3-PostOrder
Enter your choice
2
InOrder is: 15  25      28      30      35      40      45      55      60      70
1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
2
Enter the element to be deleted
60
Element deleted
1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
4
1-PreOrder
2-InOrder
3-PostOrder
Enter your choice
2
InOrder is: 15  25      28      30      35      40      45      55      70
1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
2
Enter the element to be deleted
99
Element not found

1-Insertion
2-Deletion
3-Search
4-Traversal
5-Exit
Enter your choice
5
*/