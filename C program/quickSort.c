//Quick sort
#include <stdio.h>
int partition(int arr[],int l,int h){
    int pivot =arr[h],temp;
    int i=l;
    for(int j=l; j<h; j++){
        if(arr[j]<pivot){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
        }
    }
    temp=arr[h];
    arr[h]=arr[i];
    arr[i]=temp;
    return i;
}

void quicksort(int arr[],int l, int h){
    if(l<h){
        int p=partition(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
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
    quicksort(arr,0,n-1);
    printf("\nArray elements after sorting\n");
    display(arr,n);
}
/*
OUTPUT
Enter the size of the array
5
Enter array elements:
123
8
56
2
28

Array elements before sorting
123     8       56      2       28
Array elements after sorting
2       8       28      56      123
*/