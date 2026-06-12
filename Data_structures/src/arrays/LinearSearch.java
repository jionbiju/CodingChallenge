package arrays;

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
        int [] arr = {4,5,672,673,87,1,7,9};
        int target = 673;
        System.out.println(LSearch.find(arr,target));
    }
}
