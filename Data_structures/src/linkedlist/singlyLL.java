package linkedlist;

class Node{
    int data;
    Node next;
    Node (int data){
        this.data = data;
        this.next = null;
    }
}
public class singlyLL {
    Node head = null;
    void insertAtBegining(int data){
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    void insertAtLast(int data){
        if(head == null){
            insertAtBegining(data);
        }
        Node newNode =new Node(data);
        Node temp = head;
        while (temp.next!=null){
            temp = temp.next;
        }
        temp.next = newNode;
    }

    void insertInBetween(int index,int data){
        if(index<0){
            System.out.println("Cannot insert invalid index.");
            return;
        }
        Node temp = head;
        Node newNode = new Node(data);
        for (int i=0; i<index-1; i++){
            temp = temp.next;
        }
        newNode.next = temp.next;
        temp.next = newNode;
    }

    void delete(int data){
        if(head.data == data){
            head = head.next;
            return;
        }
        Node temp = head;
        while (temp.next != null && temp.next.data != data){
            temp = temp.next;
        }
        if (temp.next == null){
            System.out.println("Invalid index,cannot delete.");
            return;
        }
        temp.next = temp.next.next;

    }

    void deleteByIndex (int index){
        if(index<0){
            System.out.println("Cannot delete invalid index.");
            return;
        }
        if (index == 0){
            head = head.next;
            return;
        }
        Node temp = head;
        for (int i=0; i<index-1; i++){
            temp = temp.next;
        }
        temp.next = temp.next.next;
    }


    void display(){
        Node temp =head;
        while(temp != null){
            System.out.print(temp.data+"->");
            temp = temp.next;
        }
        System.out.print("null");
        System.out.println();
    }

    public static void main(String[] args) {
        singlyLL list = new singlyLL();
        list.insertAtBegining(33);
        list.insertAtBegining(24);
        list.insertAtBegining(97);
        list.insertAtLast(100);
        list.insertInBetween(2,67);
        list.display();
        list.delete(67);
        list.display();
        list.deleteByIndex(1);
        list.display();
    }
}
/*
OUTPUT
97->24->67->33->100->null
97->24->33->100->null
97->33->100->null
 */

