//Read first ‘n’ natural numbers and display the list.
#include <stdio.h>
void main(){
    int n,i;
    printf("Enter the limit:\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i++){
        arr[i]=i+1;
    }
    printf("First %d natural numbers are:\n",n);
    for (i = 0; i < n; i++) {
        printf("%d\t",arr[i]);
    }
    
}