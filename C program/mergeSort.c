//Merge sort
#include <stdio.h>

void merge(int arr[],int low,int mid,int high){
    int n1,n2;
    n1=mid-low+1;
    n2=high-mid;
    int l[n1],r[n2];
    for(int i=0; i<n1; i++){
        l[i]=arr[low+i];
    }
    for(int j=0; j<n2; j++){
        r[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    mergesort(arr,0,n-1);
    printf("\nArray elements after sorting\n");
    display(arr,n);
}
/*
OUTPUT
Enter the size of the array
5
Enter array elements:
77
185
252
4
29

Array elements before sorting
77      185     252     4       29
Array elements after sorting
4       29      77      185     252
*/