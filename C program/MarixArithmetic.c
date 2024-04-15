/*
Menu Driven program to Calculate Matrix Addition, tarsnpose & Multiplication .Use fuctions to read a matrix,to find the sum, 
product,transpose and to diplay.
*/


#include <stdio.h>
void display();
void sum();
void read();
void multi();
void transpose();
void main()
{
    int m1,m2,n2,n1,ch,mat1[10][10],mat2[10][10],result[10][10];
    printf("Enter your choice\n1-Addtion\n2-Multiplication\n3-Transpose\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            printf("Enter the row and column of the first matrix:\n ");
            scanf("%d%d",&m1,&n1);
            printf("Enter the row and column of the Second matrix:\n ");
            scanf("%d%d",&m2,&n2);
            if(m1==m2 && n1==n2)
            {
            printf("Enter the elements of the first matrix\n");
            read(m1,n1,mat1);
            printf("First matrix is:\n");
            display(m1,n1,mat1); 
            printf("Enter the elements of the second matrix\n");
            read(m2,n2,mat2);
            printf("Second matrix is\n"); 
            display(m2,n2,mat2);
            sum(m1,n1,mat1,mat2,result);
            }
            else
            printf("Addition is not possible\n");
            break;
        }
        case 2:
        {
            printf("Enter the row and column of the first matrix:\n ");
            scanf("%d%d",&m1,&n1);
            printf("Enter the row and column of the Second matrix:\n ");
            scanf("%d%d",&m2,&n2);    
            if(m2==n1)
            {
            printf("Enter the elements of the first matrix\n");
            read(m1,n1,mat1);
            printf("First matrix is:\n");
            display(m1,n1,mat1); 
            printf("Enter the elements of the second matrix\n");
            read(m2,n2,mat2);   
            printf("Second matrix is\n"); 
            display(m1,n1,mat1);
            multi(m1,n1,m2,n2,mat1,mat2,result);         
            } 
            else       
            printf("Matrix multiplication is not possible\n");
            break;  
        }
        case 3:
        {
            printf("Enter the row and column of the matrix:\n ");
            scanf("%d%d",&m1,&n1);      
            printf("Enter the elements of the matrix\n");
            read(m1,n1,mat1);  
            printf("Matrix is:\n");
            display(m1,n1,mat1);  
            transpose(m1,n1,mat1,result); 
            break;
        }
        default:
        {
            printf("Enter a valid number\n");
            break;
        }
    }
}

void read(int m,int n,int mat[10][10])
{
    int i,j;
    for ( i = 0; i <m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&mat[i][j]);
        }
        
    }
}
void sum(int m1,int n1,int mat1[10][10],int mat2[10][10],int sum[10][10])
{
    int i,j;
    for ( i = 0; i <m1; i++)
    {
        for ( j = 0; j < n1; j++)
        {
            sum[i][j]=mat1[i][j]+mat2[i][j];
        }
        
    }
    printf("Sum of matrix is:\n");
    display(m1,n1,sum);
}

void display(int m,int n,int matrix[10][10]){
    int i,j;
    for ( i = 0; i <m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");       
    }
}

void multi(int m1,int n1,int m2,int n2,int mat1[10][10],int mat2[10][10],int p[10][10])
{
    int i,j,k;
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n2;j++)
            {
                p[i][j]=0;
                for(k=0;k<m2;k++)
                {
                    p[i][j]=p[i][j]+((mat1[i][k]*mat2[k][j]));
                }
            }
        } 
    printf("Product of the matrix is:\n");
    display(m1,n2,p);
}

void transpose(int m,int n, int matrix[10][10],int t[10][10])
{
    int i,j;
    for(i=0; i<m;i++){
        for(j=0; j<n; j++){
            t[j][i]=matrix[i][j];
        }
    }
    printf("Transpose of the matrix is:\n");
    display(n,m,t);
}

/*
OUTPUT
Enter your choice
1-Addtion
2-Multiplication
3-Transpose
1
Enter the row and column of the first matrix:
 2
2
Enter the row and column of the Second matrix:
 2
2
Enter the elements of the first matrix
2
3
2
3
First matrix is:
2       3
2       3
Enter the elements of the second matrix
3
4
3
4
Second matrix is
3       4
3       4
Sum of matrix is:
5       7
5       7

Enter your choice
1-Addtion
2-Multiplication
3-Transpose
2
Enter the row and column of the first matrix:
 2
2
Enter the row and column of the Second matrix:
 2
2
Enter the elements of the first matrix
1
2
3
4
First matrix is:
1       2
3       4
Enter the elements of the second matrix
1
2
3
4
Second matrix is
1       2
3       4
Product of the matrix is:
7       10
15      22

Enter your choice
1-Addtion
2-Multiplication
3-Transpose
3
Enter the row and column of the matrix:
 3
4
Enter the elements of the matrix
1
2
3
4
5
6
75
33
2
3
45
6
Matrix is:
1       2       3       4
5       6       75      33
2       3       45      6
Transpose of the matrix is:
1       5       2
2       6       3
3       75      45
4       33      6
*/