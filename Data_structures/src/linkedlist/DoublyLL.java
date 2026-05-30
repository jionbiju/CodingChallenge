package linkedlist;

class DNode {
    int data;
    DNode next;
    DNode prev;

    DNode(int data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}


public class DoublyLL {
    DNode head = null;

    void insertAtBegin(int data){
        DNode newNode = new DNode(data);
        newNode.next = head;
        if (head != null){
            head.prev = newNode;
        }
        head = newNode;

     }

     void insertAtLast(int data){
        if(head == null){
            insertAtBegin(data);
            return;
        }
        DNode newNode = new DNode(data);
        DNode temp = head;
        while (temp.next != null){
            temp = temp.next;
        }
        newNode.prev = temp;
        temp.next = newNode;

     }

     void insertInBetween(int idx ,int data){
        if (idx < 0){
            System.out.println("Invalid index cannot insert.");
            return;
        }
        DNode newNode = new DNode(data);
        DNode temp = head;
        for (int i=0; i<idx-1; i++){
            temp = temp.next;
        }
        newNode.next = temp.next;
        temp.next.prev = newNode;
        temp.next = newNode;
        newNode.prev = temp;
     }

     void delete (int data){
        DNode temp = head;
        while (temp != null && temp.data != data ){
            temp = temp.next;
        }
        if(temp == null){
            System.out.println("Cannot delete:Data is not found.");
            return;
        }
        if(temp == head){
            head = temp.next;
            if (head != null){
                head.prev = null;
            }
            return;
        }
        if(temp.next == null){
            temp.prev.next = null;
            return;
        }
        temp.next.prev = temp.prev;
        temp.prev.next = temp.next;
     }

     void deleteByIndex (int index){
        DNode temp = head;
        for (int i=0; i<index && temp != null; i++){
            temp = temp.next;
        }
        if (temp == null){
            System.out.println("Invalid index:cannot delete.");
            return;
        }

        if (temp == head){
            head = temp.next;
            if (head != null){
                head.prev = null;
            }
            return;
        }
        if (temp.next == null){
            temp.prev.next = null;
            return;
        }

        temp.prev.next = temp.next;
        temp.next.prev = temp.prev;
     }

     void display(){
        DNode temp = head;
         System.out.println();
        while (temp != null){
            System.out.print(temp.data+"->");
            temp = temp.next;
        }
         System.out.print("null");

     }

    public static void main(String[] args) {
        DoublyLL list = new DoublyLL();
        list.insertAtBegin(3);
        list.insertAtBegin(5);
        list.insertAtBegin(9);
        list.insertAtLast(44);
        list.insertInBetween(2,56);
        list.delete(44);
        list.display();
        list.deleteByIndex(1);
        list.display();
    }
}
/*
OUTPUT
9->5->56->3->null
9->56->3->null
 */