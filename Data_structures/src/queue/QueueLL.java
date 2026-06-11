package queue;

class QNode{
    int data;
    QNode next;
    QNode(int data){
        this.data = data;
        this.next = null;
    }
}
public class QueueLL {
    QNode front,rear;
    QueueLL(){
        front = null;
        rear = null;
    }

    void enqueue(int data){
        QNode newNode = new QNode(data);
        if(front == null){
            front=newNode;
            rear = newNode;
            return;
        }
        rear.next = newNode;
        rear = newNode;
    }

    int dequeue(){
       if(front == null){
           System.out.println("Queue is empty.");
           return -1;
       }
       int data = front.data;
       front = front.next;
       return data;
    }

    public static void main(String[] args) {
        QueueLL ll = new QueueLL();
        ll.enqueue(2);
        ll.enqueue(434);
        ll.enqueue(5);
        System.out.println(ll.dequeue());
        System.out.println(ll.dequeue());
        System.out.println(ll.dequeue());
        System.out.println(ll.dequeue());
    }
}
/*
OUTPUT
2
434
5
Queue is empty.
-1
 */
