//Write a C program to print the position of the largest of n numbers using arrays
#include <stdio.h>
void main(){
    int n,i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int largest=arr[0];
    int index=0;
    for(i=1; i<n; i++){
        if(arr[i]>largest){
            largest=arr[i];
            index=i;
        }
    }
    printf("Largest number is %d at the index %d",largest,index);

}
/*
OUTPUT
Enter the number of elements:
5
Enter the elements:
2
7
1
8
6
Largest number is 8 at the index 3
*/