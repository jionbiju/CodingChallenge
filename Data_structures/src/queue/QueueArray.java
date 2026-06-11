package queue;

public class QueueArray {
    int size = 2;
    int front = -1;
    int rear = -1;
    int [] arr = new int[size];


    void enqueue(int data){
        if (rear == size-1){
            throw new IndexOutOfBoundsException("Queue is full.");
        }
        if (front == -1 && rear == -1){
            front++;
            arr[++rear] = data;
            return;
        }
        arr[++rear] = data;

    }

    int dequeue(){
        if (front == -1 ||  rear == -1 || front>rear){
            throw new IndexOutOfBoundsException("Queue is empty.");
        }
        int num;
        num = arr[front++];
        return num;
    }
    public static void main(String[] args) {
        QueueArray queueArray = new QueueArray();
        queueArray.enqueue(1);
        queueArray.enqueue(2);
        queueArray.enqueue(3);
        System.out.println(queueArray.dequeue());
        System.out.println(queueArray.dequeue());


    }
}
