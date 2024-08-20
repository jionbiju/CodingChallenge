//Example for Exception
import java.util.InputMismatchException;
import java.util.Scanner;
public class Exception{
    public static void main(String args [])throws
            ArithmeticException, ArrayIndexOutOfBoundsException, InputMismatchException,
            NegativeArraySizeException
    {
        Scanner sc = new Scanner(System.in);
        try{
            System.out.println("Enter the size of first array ");
            int n =sc.nextInt();
            int [] a = new int[n];
            System.out.println("Enter the size of second array ");
            int m =sc.nextInt();
            int [] b = new int[m];
            int [] result1 = new int[n];
            int [] result2 = new int[m];
            if(n !=m){
                throw new ArrayIndexOutOfBoundsException("Size of the Array should be same ");
            }
            System.out.println("Enter the elements of the first array ");
            for(int i=0; i<n; i++){
                a[i] = sc.nextInt();
            }
            System.out.println("Enter the elements of the second array ");
            for(int i=0; i<m; i++){
                b[i] = sc.nextInt();
            }
            for(int i=0; i<m; i++){
                result1[i] = a[i]/b[i];
                result2[i] = b[i]/a[i];
            }

            for(int i=0; i<n; i++){
                System.out.println("Result of "+a[i]+ "/"+ b[i] + "="+ result1[i]);

            }
            for(int i=0; i<m; i++){
                System.out.println("Result of " +b[i] +"/"+a[i]+ "=" +result2[i]);
            }

        }
        catch(ArithmeticException e){
            System.out.println("Division by zero is not possible \n"+e);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Size of the arrays are different\n" + e);
        }
        catch(InputMismatchException e){
            System.out.println("Only integer value should be entered\n" + e);
        }
        catch(NegativeArraySizeException e){
            System.out.println("Array size should not be negative\n" + e);
        }
        finally{
            System.out.println("Operation Completed");
        }
    }
}
/*
OUTPUT-1
Enter the elements of the first array
2
Enter the elements of the second array
0
Division by zero is not possible
java.lang.ArithmeticException: / by zero
Operation Complete

OUTPUT-2
Enter the size of first array
-8
Array size should not be negative
java.lang.NegativeArraySizeException: -8
Operation Completed

OUTPUT-3
Enter the size of first array
1
Enter the size of second array
2
Size of the arrays are different
java.lang.ArrayIndexOutOfBoundsException: Size of the Array should be same
Operation Completed

OUTPUT-4
Enter the size of first array
aa
Only integer value should be entered
java.util.InputMismatchException
Operation Completed

OUTPUT-5
Enter the size of first array
2
Enter the size of second array
2
Enter the elements of the first array
8
6
Enter the elements of the second array
4
2
Result of 8/4=2
Result of 6/2=3
Result of 4/8=0
Result of 2/6=0
Operation Completed
 */