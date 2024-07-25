import java.util.Scanner;

public class StringLength {
    public static void main(String args[]){
        int a;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String str = sc.nextLine();
        a = str.length();
        System.out.println("String length= "+a);
    }
}
