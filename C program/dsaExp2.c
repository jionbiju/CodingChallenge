//Read ‘n’ numbers and display the odd numbers.

#include <stdio.h>
void main(){
    int n,i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers\n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("The odd numbers are:\n");
    for (i = 0; i < n; i++) {
        if(arr[i] % 2 != 0){
        printf("%d\t",arr[i]);
        }
    }
    
}

//OUTPUT
/*
Enter the number of elements:
6
Enter the numbers
1
5
55
8
888
4
The odd numbers are:
1       5       55
*/