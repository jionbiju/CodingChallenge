//Implement a JAVA program to insert an element in a given position in an array.
import java.util.Scanner;
public class ArrayInseration {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();
        int[] arr = new int[n + 1];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.print("Enter the element to be inserted: ");
        int element = scanner.nextInt();
        System.out.print("Enter the position where the element should be inserted: ");
        int pos = scanner.nextInt();
        int index =pos-1;
        if (pos < 0 || pos > n) {
            System.out.println("Invalid position!");
        } else {
            for (int i = n; i>=index; i--) {
                arr[i] = arr[i - 1];
            }
        }
        arr[index] = element;
        System.out.println("Array after insertion:");
        for (int i = 0; i <= n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
/*
OUTPUT
Enter the size of the array: 4
Enter the elements of the array:
1
3
4
5
Enter the element to be inserted: 2
Enter the position where the element should be inserted: 2
Array after insertion:
1 2 3 4 5
 */