/*
Implement a Java program to create a class called as “Number”
with a data member called limit. A class called as “Compute”
inherits this class and has a method called “secLargest” to display
the second largest of an array of numbers. The limit for the array
should be used from the “Number” class.
 */
import java.util.Scanner;

 class Number{
    int limit;
    public Number(int limit){
        this.limit=limit;
    }
}
class Compute extends Number{
    public Compute(int limit){
        super(limit);
    }
    public int compute(int arr[]){
        boolean flag;
        int temp,secondLargest=0;
        for (int i=0; i<limit-1; i++){
            flag=false;
            for(int j=0; j<limit-1-i; j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    flag=true;
                }
            }
            if(flag==false){
                break;
            }
        }
        int largest =arr[limit-1];
        for(int i=limit-1; i>=0; i--){
            if(arr[i]!=largest){
                secondLargest =arr[i];
                break;
            }
        }
        return secondLargest;
    }
    public void secLargest(int arr []){
        System.out.println("Second Largest element in the array is "+compute(arr));
    }

}
public class SecondLargest {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter the limit:");
        int limit= sc.nextInt();
        int  [] arr=new int[limit];
        System.out.println("Enter "+limit+" numbers:");
        for(int i=0; i<limit; i++){
            arr[i]=sc.nextInt();
        }
        Compute c =new Compute(limit);
        c.secLargest(arr);
    }
}
/*
OUTPUT
Enter the limit:
5
Enter 5 numbers:
7
7
5
2
3
Second Largest element in the array is 5
 */