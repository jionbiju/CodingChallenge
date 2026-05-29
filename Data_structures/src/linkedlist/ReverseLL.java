package linkedlist;


public class ReverseLL {
    Node head = null;

    void reverse(){
        Node prev = null;
        Node curr = head;
        Node next = null;

        while (curr != null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
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
        ReverseLL list2 = new ReverseLL();
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
        list2.head = list.head;
        System.out.println("Reverse");
        list2.reverse();
        list2.display();
    }
}
/*
OUTPUT
97->24->67->33->100->null
97->24->33->100->null
97->33->100->null
Reverse
100->33->97->null

Process finished with exit code 0

 */
