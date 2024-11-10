//Queue using array
#include <stdio.h>
int n,arr[20],front=-1,rear=-1;

void enqueue(){
    int item;
    printf("Enter the element to be inserted\n");
    scanf("%d",&item);
    if(front==-1 && rear==-1){
        front=rear=0;
        arr[rear]=item;
    }
    else{
        rear++;
        arr[rear]=item;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear){
        printf("Dequeued elements is %d",arr[front]);
        front=rear=-1;
    }
    else{
        printf("Dequeued elements is %d",arr[front]);
        front++;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Queue elements are:");
        for(int i=front; i<=rear; i++){
            printf("%d\t",arr[i]);
        }
    }
}

void main(){
    int ch;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    do{
        printf("\nEnter your choice\n");
        printf("1-Enqueue\n");
        printf("2-Dequeue\n");
        printf("3-Display\n");
        printf("4-Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:if(rear==n-1)
                   printf("Queue is full\n");
                   else 
                   enqueue();
                   break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            case 4:printf("Exiting..");
                    break;
        }
    }
    while(ch!=4);
}
/*
OUTPUT
Enter the size of the array:
4

Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
1
Enter the element to be inserted
11

Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
1
Enter the element to be inserted
22

Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
1
Enter the element to be inserted
33

Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
1
Enter the element to be inserted
44

Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
3
Queue elements are:11   22      33      44
Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
1
Queue is full

Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
2
Dequeued elements is 11
Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
3
Queue elements are:22   33      44
Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
2
Dequeued elements is 22
Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
3
Queue elements are:33   44
Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
2
Dequeued elements is 33
Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
3
Queue elements are:44
Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
2
Dequeued elements is 44
Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
3
Queue is empty

Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
2
Queue is empty

Enter your choice
1-Enqueue
2-Dequeue
3-Display
4-Exit
4
Exiting..
*/