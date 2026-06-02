package Stack;

public class StackArray {
    int size = 100;
    int [] stack = new int[size];
    int top = -1;

    void push(int data){
        if (top == size-1){
            System.out.println("stack is full");
            return;
        }
        stack[++top] = data;
    }

    int pop(){
        if (top == -1){
            System.out.println("Stack is empty");
            return -1;
        }
        return stack[top--];
    }
    int peek(){
        return stack[top];
    }

    boolean isEmpty(){
        if (top == -1){
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        StackArray stackArray = new StackArray();
        stackArray.push(1);
        stackArray.push(2);
        stackArray.push(3);
        System.out.println(stackArray.pop());
        System.out.println(stackArray.pop());
        System.out.println(stackArray.peek());
        System.out.println(stackArray.isEmpty());
        System.out.println( stackArray.pop());
        stackArray.pop();
    }
}
/*
OUTPUT
3
2
1
false
1
Stack is empty
 */