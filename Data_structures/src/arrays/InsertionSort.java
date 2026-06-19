package arrays;

import java.util.Arrays;

public class InsertionSort {
    public static void sort(int [] arr){
        for (int i=1; i<arr.length; i++){
            int temp = arr[i];
            int j;
            for (j=i-1; j>=0 && arr[j] > temp; j--){
                arr[j+1] = arr[j];
            }
            arr[j+1] =temp;
        }
    }
    public static void main(String[] args) {
        int [] arr = {5,8,1,77,45};
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
/*
OUTPUT
[1, 5, 8, 45, 77]
 */