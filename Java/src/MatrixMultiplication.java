//MatrixMultiplication

import java.util.Scanner;

public class MatrixMultiplication {
public static void main(String args[]){
    int i,j,k,m1,n1,m2,n2;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter number of rows and columns of the first matrix:");
    m1 = sc.nextInt();
    n1 = sc.nextInt();
    int [][] a = new int[m1][n1];
    System.out.println("Enter the elements of the first matrix:\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            a[i][j] = sc.nextInt();
        }
    }
    System.out.println("First matrix is:\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            System.out.print( a[i][j] + "   ");
        }
        System.out.println("\n");
    }
    System.out.println("Enter number of rows and columns of the second matrix:");
    m2 = sc.nextInt();
    n2 = sc.nextInt();
    int [][] b = new int[m2][n2];
    int [][] p = new int[m1][n2];
    System.out.println("Enter the elements of the second matrix:\n");
    for(i=0;i<m2;i++)
    {
        for(j=0; j<n2; j++)
        {
            b[i][j] = sc.nextInt();
        }
    }
    System.out.println("Second matrix is:\n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            System.out.print( b[i][j] + "   ");
        }
        System.out.println("\n");
    }
    if(m2==n1){
        for(i=0; i<m1; i++){
            for(j=0; j<n2; j++){
                p[i][j] = 0;
                for (k=0; k<m2; k++){
                    p[i][j] = p[i][j] + ((a[i][k] * b[k][j]));
                }
            }
        }
        System.out.println("Products of the matrix is:");
        for (i=0; i<m1; i++){
            for (j=0; j<n2; j++){
                System.out.print(p[i][j] + "   ");
            }
            System.out.println("\n");
        }
    }
    else {
        System.out.println("Matrix multiplication is not possible.");
    }

}
}
/*
OUTPUT

Enter number of rows and columns of the first matrix:
2
2
Enter the elements of the first matrix:

1
2
3
4
First matrix is:

1   2

3   4

Enter number of rows and columns of the second matrix:
2
2
Enter the elements of the second matrix:

1
2
3
4
Second matrix is:

1   2

3   4

Products of the matrix is:
7   10

15   22
 */