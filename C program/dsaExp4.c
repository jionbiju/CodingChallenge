//Find the sum of two arrays using the fuctions read, sum, and display.
#include <stdio.h>
#include <stdlib.h>

void read(int arr[],int n){
    int i;
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
}

void display(int arr[],int n){
    int i;
    printf("Sum of the two arrays is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t",arr[i]);
    }
}

void sumArr(int a[],int b[], int sum[],int n){
    for(int i=0; i<n; i++){
        sum[i]=a[i] + b[i];
    }
}

void main(){
    int n1,n2;
    printf("Enter the size of the first array:\n");
    scanf("%d",&n1);
    printf("Enter the size of the second array:\n");
    scanf("%d",&n2);
    if(n1!=n2){
    printf("Array sum is not possible. The arrays must be of the same size.\n");
    exit(0);
    }
    int a[n1], b[n2],sum[n1];
    printf("Enter the numbers of the first array:\n");
    read(a,n1);
    printf("Enter the numbers of the second array:\n");
    read(b,n2);
    sumArr(a,b,sum,n1);
    display(sum,n1);
}

//OUTPUT
/*
Enter the size of the first array:
3
Enter the size of the second array:
3
Enter the numbers of the first array:
1
2
3
Enter the numbers of the second array:
4
5
6
Sum of the two arrays is:
5       7       9
*/