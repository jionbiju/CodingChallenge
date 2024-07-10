//Read ‘n’ numbers and display the numbers. [using functions read(), display()].

#include <stdio.h>
void read(int arr[],int n){
    int i;
    printf("Enter the numbers\n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
}

void display(int arr[],int n){
    int i;
    printf("Numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t",arr[i]);
    }
}

void main(){
    int n;
    printf("Enter the number of elememts:\n");
    scanf("%d",&n);
    int arr[n];
    read(arr,n);
    display(arr,n);
}

//OUTPUT
/*
Enter the number of elememts:
6
Enter the numbers
1
22
3
44
5
6
Numbers are:
1       22      3       44      5       6
*/