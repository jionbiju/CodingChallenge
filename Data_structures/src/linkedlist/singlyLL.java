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



    void display(){
        Node temp =head;
        while(temp != null){
            System.out.print(temp.data+"->");
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        singlyLL list = new singlyLL();
        list.insertAtBegining(33);
        list.insertAtBegining(24);
        list.insertAtBegining(97);
        list.insertAtLast(100);
        list.display();
    }
}

