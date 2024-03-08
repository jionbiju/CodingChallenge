#include <stdio.h>

void main()
{
    int m,n,i,j;
    printf("Enter the number of rows & column:\n");
    scanf("%d%d",&m,&n);
    int arr[m][n],t[n][m];
    printf("Enter the elements:\n");
    for(i=0; i<m;i++){
        for(j=0; j<n; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Elements are:\n");
    for(i=0; i<m;i++){
        for(j=0; j<n; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<m;i++){
        for(j=0; j<n; j++){
            t[j][i]=arr[i][j];
        }
    }
    printf("Transnpose Matix is:\n");
    for(i=0; i<n;i++){
        for(j=0; j<m; j++){
             printf("%d\t",t[i][j]);
        }
        printf("\n");
    }
}