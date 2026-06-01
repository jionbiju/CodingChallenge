package linkedlist;

class SNode{
    int data;
    SNode next;
    SNode(int data){
        this.data = data;
        this.next = null;
    }
}

public class StackLL {
    SNode top = null;

    void push(int data){
        SNode newNode = new SNode(data);
        if (top == null){
            top = newNode;
            return;
        }
        newNode.next = top;
        top = newNode;
    }

    int pop(){
        if (top == null){
            System.out.println("Stack is empty");
            return -1;
        }
        int temp = top.data;
        top = top.next;
        return temp;
    }

    int peeK(){
        return top.data;
    }

    boolean isEmpty(){
        if(top == null){
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        StackLL stack = new StackLL();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.peeK());
        System.out.println(stack.isEmpty());
        System.out.println(stack.pop());
        System.out.println(stack.isEmpty());
    }
}
/*
3
2
1
false
1
true
 */