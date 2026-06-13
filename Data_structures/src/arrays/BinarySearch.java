package arrays;

public class BinarySearch {
    public static int search(int [] arr,int target){
        int l=0;
        int r=arr.length-1;
        int mid;
        boolean asc = true;
        if (arr[l] > arr[r]){
            asc = false;
        }
        if (asc){
            while (l<=r){
                mid = (l+r)/2;
                if (arr[mid] == target){
                    return mid;
                }
                else if(target < arr[mid]){
                    r = mid-1;
                }
                else {
                    l = mid +1;
                }

            }
        }
        else {
            while (l <= r) {
                mid = (l + r) / 2;
                if (arr[mid] == target) {
                    return mid;
                } else if (target < arr[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }

    public static int recursiveSearch(int [] arr, int target,int l,int r){
        int mid = (l+r)/2;
        if (l>r){
            return -1;
        }
        if (arr[mid] == target){
            return mid;
        }
        if (target<arr[mid]){
            return recursiveSearch(arr,target,l,mid-1);
        }
        else {
            return recursiveSearch(arr,target,mid+1,r);
        }
    }

    public static void main(String[] args) {
        int [] arr = {1,4,5,6,7,12,34,55};
        int [] arr1 ={99,55,35,21,20,14,13,5,2};
        System.out.println("Ascending Order array:" + search(arr,55));
        System.out.println("Descending Order array:" + search(arr1,55));
        System.out.println("Ascending Order array using recursion: " + recursiveSearch(arr,4,0,arr.length-1));
    }
}
/*
OUTPUT
Ascending Order array:7
Descending Order array:1
Ascending Order array using recursion: 1
 */