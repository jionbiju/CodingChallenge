//find number of characters in a string
import java.util.Scanner;

public class StringLength {
    public static void main(String args[]){
        int length;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter a string");
        String str = scan.nextLine();
        scan.close();
        length = str.length();
        System.out.println("Number of character in the string is "+length);

    }
}
/*
OUTPUT
Enter a string
hello
Number of character in the string is 5
 */