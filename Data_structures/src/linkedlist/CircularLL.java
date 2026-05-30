package linkedlist;

public class CircularLL <T>{
    class CNode {
        T data;
        CNode next;
        CNode(T data){
            this.data = data;
            this.next = null;
        }
    }
    CNode tail;

    CircularLL () {
        this.tail = null;
    }

    void insertAtBegin (T data) {
        CNode newNode = new CNode(data);
        if(tail == null){
            newNode.next = newNode;
            tail = newNode;
            return;
        }
        newNode.next = tail.next;
        tail.next = newNode;
    }

    void display (){
        CNode temp =tail;
        do {
            System.out.print(temp.data+"->");
            temp = temp.next;
        }while (temp != tail);
        System.out.print("null");

    }

    void insertAtLast (T data){
        CNode newNode = new CNode(data);
        if (tail == null){
            newNode.next = newNode;
            tail = newNode;
            return;
        }
        newNode.next = tail.next;
        tail.next = newNode;
        tail = newNode;
    }

    void deleteAtBegin (){
        if(tail == null){
            System.out.println("Empty list.");
        }
        else if (tail.next == tail) {
            tail = null;
        }
        else {
            tail.next = tail.next.next;
        }
    }

    void deleteAtLast () {
        if(tail == null){
            System.out.println("Empty list.");
            return;
        }
        if (tail.next == tail){
            tail = null;
            return;
        }
        CNode temp = tail;
        while (temp.next != tail){
            temp = temp.next;
        }
        temp.next = tail.next;
        tail = temp;
    }



    public static void main(String[] args) {
        CircularLL<String> list = new CircularLL<>();
        list.insertAtBegin("a");
        list.insertAtBegin("b");
        list.insertAtBegin("c");
        list.insertAtLast("g");
        list.display();
        System.out.println("\nDelete at Begin");
        list.deleteAtBegin();
        list.display();
        System.out.println("\nDelete at End");
        list.deleteAtLast();
        list.display();
    }
}
/*
OUTPUT
g->c->b->a->null
Delete at Begin
g->b->a->null
Delete at End
a->b->null
 */