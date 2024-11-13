/*
Write a Java program to create two threads: One for
displaying the number of occurrences of each element in an array
and the second thread for displaying the second smallest of an
array.
 */
import java.util.Scanner;
class Frequency extends Thread {
    int n;
    int[] a, b, visited;
    Frequency(int[] a, int n) {
        this.a = a;
        this.n = n;
        this.b = new int[n];
        this.visited = new int[n];
    }

    public void run() {
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                int count = 1;
                for (int j = i + 1; j < n; j++) {
                    if (a[i] == a[j]) {
                        count++;
                        visited[j] = 1;
                    }
                }
                b[i] = count;
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                System.out.println("Element " + a[i] + ", Frequency: " + b[i]);
            }
        }
    }
}

class SecLarge extends Thread {
    int n, secSmallest, smallest;
    int[] a;

    SecLarge(int[] a, int n) {
        this.a = a;
        this.n = n;
    }

    public void run() {
        if(n<2){
            System.out.println("Second smallest element does not exist");
            return;
        }
        int []c=new int[n];
        for (int i=0;i<n;i++){
            c[i]=a[i];
        }
      int temp;
        for (int i=0; i<n-1; i++){
            int flag=0;
            for (int j=0; j<n-1-i;j++){
                if(c[j]>c[j+1]){
                    temp=c[j];
                    c[j]=c[j+1];
                    c[j+1]=temp;
                    flag=1;
                }
            }
            if(flag==0)
                break;
        }
        smallest=c[0];
        for (int i=0; i<n; i++){
            if(c[i]!=smallest){
                secSmallest=c[i];
                break;
            }
        }
        if(secSmallest==0){
            System.out.println("Second smallest element does not exist");
        }
        else {
            System.out.println("Second Smallest element is "+secSmallest);
        }

    }
}

public class Thread1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;

        System.out.println("Enter the size of the array");
        n = sc.nextInt();

        int[] a = new int[n];

        System.out.println("Enter array elements");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        System.out.println("Array elements are:");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        Frequency f = new Frequency(a, n);
        f.start();

        SecLarge secLarge = new SecLarge(a, n);
        secLarge.start();

        try {
            f.join();
            secLarge.join();
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}
/*
OUTPUT
Enter the size of the array
6
Enter array elements
3
4
3
2
5
2
Array elements are:
3 4 3 2 5 2
Second Smallest element is 3
Element 3, Frequency: 2
Element 4, Frequency: 1
Element 2, Frequency: 2
Element 5, Frequency: 1
 */