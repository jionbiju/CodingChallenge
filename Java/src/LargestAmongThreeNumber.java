//Find the Largest number among 3 numbers
import java.util.Scanner;

public class LargestAmongThreeNumber {
    public static void main(String args[]){
        int a,b,c;
        System.out.println("Enter 3 numbers:\n");
        Scanner scan = new Scanner(System.in);
        a = scan.nextInt();
        b = scan.nextInt();
        c = scan.nextInt();
        if(a>b && a>c){
            System.out.println("Largest Number is "+a);
        } else if (b>a && b>c) {
            System.out.println("Largest Number is "+b);
        }
        else {
            System.out.println("Largest Number is "+c);
        }
    }
}
//OUTPUT
/*
* Enter 3 numbers:

10
5
9
Largest Number is 10
* */
