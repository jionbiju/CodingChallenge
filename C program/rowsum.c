//Implement a C program to find row sum, column sum and diagonal sum of a matrix.
#include<stdio.h>
void main()
{
    int rsum,csum,dsum=0,n,i,j;
    printf("Enter the size of the square matrix\n");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter the elemnts of the matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Matrix is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        rsum=0;
        for(j=0; j<n; j++)
        {
            rsum+=arr[i][j];
        }
        printf("sum of row %d is %d\n",i+1,rsum);
    }
    for(i=0; i<n; i++)
    {
        csum=0;
        for(j=0; j<n; j++)
        {
            csum+=arr[j][i];
        }
        printf("sum of column %d is %d\n",i+1,csum);
    }
    for(j=0; j<n; j++)
        {
            dsum+=arr[j][j];
        }
        printf("sum of diagonal  is %d\n",dsum);
    
}

/*
Output
Enter the size of the square matrix
2
Enter the elemnts of the matrix:
1
2
2
23
Matrix is:
1       2
2       23
sum of row 1 is 3
sum of row 2 is 25
sum of column 1 is 3
sum of column 2 is 25
sum of diagonal  is 24
*/