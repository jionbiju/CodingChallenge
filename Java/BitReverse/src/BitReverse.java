import java.util.Scanner;

public class BitReverse {
    public static void main(String args []) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        int n = sc.nextInt();
        String binary = Integer.toBinaryString(n);
        System.out.println("Corresponding binary of the integer number");
        System.out.println(binary);
        int l = binary.length();
        char result;
        System.out.println("Reversed bits are");
        for (int i = 0; i < l; i++){
            result = binary.charAt(l-1-i);
            System.out.print(result);
        }
        sc.close();
    }
}
