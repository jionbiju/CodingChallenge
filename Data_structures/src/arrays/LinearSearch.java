package arrays;

import java.util.Scanner;

class LSearch{
    public static int find(int [] arr,int target){
        for(int i=0;i<arr.length ; i++){
            if (arr[i] == target){
                return i;
            }
        }
        return -1;
    }
}
public class LinearSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter the array size:");
        n = sc.nextInt();
        int [] arr = new int[n];
        System.out.println("Enter " + n+" array elements:");
        for (int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }
        int target;
        System.out.println("Enter the element to be searched:");
        target = sc.nextInt();
        System.out.println("Index:"+LSearch.find(arr,target));
    }
}
/*
OUTPUT
Enter the array size:
6
Enter 6 array elements:
78 45 984 4 22 369
Enter the element to be searched:
4
Index:3

Process finished with exit code 0

 */
