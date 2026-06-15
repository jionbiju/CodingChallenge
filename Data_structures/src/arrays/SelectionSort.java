package arrays;

import java.util.Arrays;
import java.util.Scanner;

public class SelectionSort {
    void sort(int [] arr,int n){
        for (int i=0; i<n; i++){
            int idx_min = i;
            for (int j=i+1; j<n; j++){
                if (arr[j] < arr[idx_min]){
                    idx_min = j;
                }
            }
            int temp = arr[idx_min];
            arr[idx_min] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String[] args) {
        SelectionSort ss = new SelectionSort();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int n = sc.nextInt();
        int [] arr = new int[n];
        System.out.println("Enter " + n+" elements:");
        for (int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        ss.sort(arr,n);
        System.out.println("Array elements are: "+ Arrays.toString(arr));
    }
}
/*
OUTPUT
Enter the size of the array
6
Enter 6 elements:
-4 55 134 -56 2 89
Array elements are: [-56, -4, 2, 55, 89, 134]

Process finished with exit code 0

 */