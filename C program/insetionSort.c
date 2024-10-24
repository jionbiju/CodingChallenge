//Insertion sort
#include <stdio.h>
void sort(int arr[],int n){
    int temp,j;
    for(int i=1; i<n; i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void display(int arr[],int n){
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}

void main(){
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nArray elements before sorting\n");
    display(arr,n);
    sort(arr,n);
    printf("\nArray elements after sorting\n");
    display(arr,n);
}
/*
OUTPUT
Enter the size of the array
5
Enter array elements:
32
12
87

2
57

Array elements before sorting
32      12      87      2       57
Array elements after sorting
2       12      32      57      87
*/