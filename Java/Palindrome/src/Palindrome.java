//Check whether the given number is palindrome or not
import java.util.Scanner;
public class Palindrome {
    public static void main(String[] args) {
        int sum=0,temp,digit;
        System.out.println("Enter a number:");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        temp = n;
        while (n!=0){
            digit = n%10;
            sum=sum*10+digit;
            n/=10;
        }
        if(sum == temp){
            System.out.println(temp+" is a palindrome");
        }
        else {
            System.out.println(temp+" is not a palindrome ");
        }
        sc.close();
    }
}
/*
OUTPUT
Enter a number:
454
454 is a palindrome
 */