//To find the frequency of a character in a string.
import java.util.Scanner;

public class Frequency {
    public static void main(String []args){
        int count=0;
        System.out.println("Enter a string:");
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        System.out.println("Enter a character:");
        char c = scan.next().charAt(0);
        for (int i=0; i<str.length(); i++){
            if(str.charAt(i) == c){
                count++;
            }
        }
        System.out.println("The character "+ c +" appear "+ count + " times in the string.");

    }
}
/*
* OUTPUT
* Enter a string:
Hello world
Enter a character:
l
The character l appear 3 times in the string.
* */
