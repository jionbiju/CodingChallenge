//Matix multiplication and addition using thread
import java.util.Scanner;

class MatrixMultiplication extends Thread{
    int m,n;
    int [][]a,b,p;
    MatrixMultiplication(int m,int n,int [][]a,int [][]b){
        this.m=m;
        this.n=n;
        this.a=a;
        this.b=b;
        this.p=new int[m][n];
    }
    public void run(){
        System.out.println("Starting matrix multiplication");
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                p[i][j]=0;
                for (int k=0; k<n;k++){
                    p[i][j]=p[i][j]+(a[i][k]*b[k][j]);
                }
            }
        }
        System.out.println("Product matrix is");
        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                System.out.print(p[i][j]+" ");
            }
            System.out.println();
        }
    }

}
class Addition extends Thread{
    int m,n;
    int [][]a,b,p;
    Addition(int m,int n,int [][]a,int [][]b ){
        this.m=m;
        this.n=n;
        this.a=a;
        this.b=b;
        this.p=new int[m][n];
    }
    public void run(){
        System.out.println("Starting matrix addition...");
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                p[i][j]=a[i][j]+b[i][j];
            }
        }
        System.out.println("Added matrix is");
        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                System.out.print(p[i][j]+" ");
            }
            System.out.println();
        }
    }
}
public class Matrix {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int m,n;
        System.out.println("Enter the rows and columns of the  matrix");
        m=sc.nextInt();
        n=sc.nextInt();
        int [][]a=new int[m][n];
        int [][]b=new int[m][n];
        System.out.println("Enter elements for the first matrix");
        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                a[i][j]=sc.nextInt();
            }
        }
        System.out.println("First matrix is");
        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("Enter elements for the Second matrix");
        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                b[i][j]=sc.nextInt();
            }
        }
        System.out.println("Second matrix is");
        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                System.out.print(b[i][j]+" ");
            }
            System.out.println();
        }
        MatrixMultiplication multi=new MatrixMultiplication(m,n,a,b);
        multi.start();
        Addition add=new Addition(m,n,a,b);
        add.start();
        try {
            multi.join();
            add.join();
        }
        catch (InterruptedException e){
            System.out.println(e);
        }
    }
}
/*
OUTPUT
Enter the rows and columns of the  matrix
2
2
Enter elements for the first matrix
4
2
5
1
First matrix is
4 2
5 1
Enter elements for the Second matrix
3
3
4
5
Second matrix is
3 3
4 5
Starting matrix multiplication
Product matrix is
20 22
19 20
Starting matrix addition...
Added matrix is
7 5
9 6
 */