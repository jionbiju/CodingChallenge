//Write a Java program to find all prime numbers in a given limit.
import java.util.Scanner;

public class PrimeNumber {
public static void main(String args[]){
    System.out.println("Enter a limit:");
    Scanner sc = new Scanner(System.in);
    int limit = sc.nextInt();
    sc.close();
    System.out.println("Prime Number Up to "+ limit + ":");
    for(int i=2; i<=limit; i++){
    if(isPrime(i)){
        System.out.print(i + " ");
    }
    }
}
public static boolean isPrime(int n){
    if (n <= 1) {
        return false;
    }
    for (int i=2; i<=Math.sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
}

/*
OUTPUT
Enter a limit:
25
Prime Number Up to 25:
2 3 5 7 11 13 17 19 23
 */