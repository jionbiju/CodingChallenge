//Binary Search

#include <stdio.h>
void sort(int arr[],int n){
    int i,j,flag,temp;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
    printf("Sorted array is:\n");
    for(i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}
void binarySearch(int arr[],int n,int low,int high,int k){
    int mid;
    while (low<=high){
        mid=(low+high)/2;
        if(arr[mid]==k){
            printf("%d found at index %d",k,mid);
            break;
        }
        else if(k<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(low>high){
        printf("%d is not present in the array.",k);
    }
    
}

void main(){
    int n,i,k;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array element:\n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    printf("\nEnter a element to be searched:\n");
    scanf("%d",&k);
    binarySearch(arr,n,0,n-1,k);
}

//OUTPUT
/*
Enter the size of the array:
5
Enter the array element:
99
45
2
12
9
Sorted array is:
2       9       12      45      99
Enter a element to be searched:
45
45 found at index 3
*/