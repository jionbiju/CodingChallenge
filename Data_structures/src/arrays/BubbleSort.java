package arrays;

import java.util.Arrays;
import java.util.Scanner;

public class BubbleSort {

    static void sort(int [] arr,int n){
        boolean flag;
        for (int i=0; i<n-1; i++){
            flag = false;
            for (int j=0; j<n-i-1; j++){
                if (arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    flag = true;
                }
            }
            if (flag == false){
                return;
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        int [] arr = new int[n];
        System.out.println("Enter " + n+" elements:");
        for (int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        sort(arr,n);
        System.out.println("Array elements are: "+ Arrays.toString(arr));
    }
}
/*
OUTPUT
Enter the size of the array:
5
Enter 5 elements:
33 4 64 23 75
Array elements are: [4, 23, 33, 64, 75]
 */