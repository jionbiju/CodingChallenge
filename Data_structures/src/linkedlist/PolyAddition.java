package linkedlist;

class PNode{
    int coef;
    int expo;
    PNode next;
    PNode (int coef, int expo){
        this.coef = coef;
        this.expo = expo;
        this.next = null;
    }
}
 class LinkedList {
    PNode head = null;
     void insertAtBeginning(int coef, int expo){
        PNode newNode = new PNode(coef,expo);
        newNode.next = head;
        head = newNode;
    }

    void insertAtLast(int coef, int expo){
        if(head == null){
            insertAtBeginning(coef,expo);
            return;
        }
        PNode newNode =new PNode(coef,expo);
        PNode temp = head;
        while (temp.next!=null){
            temp = temp.next;
        }
        temp.next = newNode;
    }

    void display(){
        PNode temp =head;
        while(temp != null){
            System.out.print(temp.coef+"X^" +temp.expo);
            if (temp.next != null) {
                System.out.print(" + ");
            }
            temp = temp.next;
        }
        System.out.println();
    }
}
public class PolyAddition {
    static LinkedList p;

    static void  polyAdd(PNode p1, PNode p2){
        p = new LinkedList();
        while (p1 != null && p2 != null){
            if (p1.expo == p2.expo){
                p.insertAtLast(p1.coef + p2.coef, p1.expo);
                p1 = p1.next;
                p2 = p2.next;
            }
            else if (p1.expo > p2.expo){
                p.insertAtLast(p1.coef, p1.expo);
                p1 = p1.next;
            }
            else if (p2.expo > p1.expo){
                p.insertAtLast(p2.coef, p2.expo);
                p2 = p2.next;
            }
        }
        while (p1 != null){
            p.insertAtLast(p1.coef, p1.expo);
            p1 = p1.next;
        }
        while (p2 != null){
            p.insertAtLast(p2.coef, p2.expo);
            p2 = p2.next;
        }
    }

    public static void main(String[] args) {
        LinkedList p1 = new LinkedList();
        p1.insertAtLast(3,2);
        p1.insertAtLast(4,1);
        p1.insertAtLast(2,0);
        System.out.print("Polynomial P1:");
        p1.display();

        LinkedList p2 = new LinkedList();
        p2.insertAtLast(4,2);

        System.out.print("Polynomial P2:");
        p2.display();

        polyAdd(p1.head,p2.head);
        System.out.print("Resultant Polynomial:");
        p.display();

    }
}
/*
OUTPUT
Polynomial P1:3X^2 + 4X^1 + 2X^0
Polynomial P2:4X^2
Resultant Polynomial:7X^2 + 4X^1 + 2X^0
 */