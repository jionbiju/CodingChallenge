#include <stdio.h>

void main(){
    int n,num;
    int flag=0;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Elements are:");
    for (int j = 0; j < n; j++)
    {
        printf("%d \n",arr[j]);
    }
    printf("Enter a element to be search:");
    scanf("%d",&num);
    for(int k=0; k<n; k++){
        if (arr[k]==num)
        {
            printf("Element found at index:%d ",k);
            flag=1;
            break;
        }
        
    }
    if(flag==0){
        printf("Element not found");
    }
    
    
}