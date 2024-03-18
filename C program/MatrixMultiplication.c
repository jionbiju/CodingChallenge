#include<stdio.h>
void main()
{
    int m1,n1,m2,n2,i,j,k;
    printf("Enter the rows & columns of the first matrix:\n");
    scanf("%d%d",&m1,&n1);
    int a[m1][n1];
    printf("Enter the elements of the first matrix:\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("First matrix is\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("Enter the rows & columns of the second matrix:\n");
    scanf("%d%d",&m2,&n2);
    int b[m2][n2],p[m1][n2];
    printf("Enter the elements of the second matrix:\n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("Second matrix is\n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    if(m2==n1)
    {
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n2;j++)
            {
                p[i][j]=0;
                for(k=0;k<m2;k++)
                {
                    p[i][j]=p[i][j]+((a[i][k]*b[k][j]));
                }
            }
        } 
    printf("Products of the matrix is:\n");
          for(i=0;i<m1;i++)
                {
                 for(j=0;j<n2;j++)
                    {
                        printf("%d\t",p[i][j]);
                    }
                      printf("\n");
                }
    }
    else
    {
    printf("Matrix multiplication is not possible\n");
    }
}