//Seletion Sort
#include <stdio.h>
void sort(int arr[],int n){
    int min,temp;
    for(int i=0; i<n-1; i++){
        min=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
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
34
685
2
87
4

Array elements before sorting
34      685     2       87      4
Array elements after sorting
*/