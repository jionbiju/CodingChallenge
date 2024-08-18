//Frequnecy of each element in an array
import java.util.Scanner;
public class Frequency {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int n = sc.nextInt();
        int [] a =new int[n];
        int [] b =new int[n];
        int [] visited = new int[n];
        System.out.println("Enter array elements");
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++){
            visited[i] = 0;
        }
        int count;
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                count=1;
                for(int j=i+1; j<n; j++){
                    if(a[i] == a[j]){
                        count++;
                        visited[j] = 1;
                    }
                }
                b[i] = count;
            }
        }
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                System.out.println("Element "+a[i]+ ", Frequency: "+ b[i]);
            }
        }
    }
}
/*
OUTPUT
Enter the size of the array
6
Enter array elements
7
9
5
7
7
9
Element 7, Frequency: 3
Element 9, Frequency: 2
Element 5, Frequency: 1
 */
