/*Write a Java program named 'ArithmeticOperations' that includes static methods
for performing addition, subtraction, multiplication, and division on numeric values*/

import java.util.Scanner;

public class ArithmeticOperations {

    public static int addition(int a, int b){
        return a+b;
    }

    public static int subtraction(int a, int b){
        return a-b;
    }

    public static int multiplication(int a, int b){
        return a*b;
    }

    public static float division(int a, int b){
        if(b == 0){
            System.out.println("Division by zero is not possible.");
        }
        return a/b;
    }

    public static void main(String args[]){
        int a,b;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter 2 number:");
        a = scan.nextInt();
        b = scan.nextInt();
        int sum = ArithmeticOperations.addition(a,b);
        int difference = ArithmeticOperations.subtraction(a,b);
        int product = ArithmeticOperations.multiplication(a,b);
        float quotient = ArithmeticOperations.division(a,b);
        System.out.println("Addition: " + a + " + " + b + " = " + sum);
        System.out.println("Subtraction: " + a + " - " + b + " = " + difference);
        System.out.println("Multiplication: " + a + " * " + b + " = " + product);
        System.out.println("Division: " + a + " / " + b + " = " + quotient);
    }
}
/*
OUTPUT
Enter 2 number:
50
5
Addition: 50 + 5 = 55
Subtraction: 50 - 5 = 45
Multiplication: 50 * 5 = 250
Division: 50 / 5 = 10
 */