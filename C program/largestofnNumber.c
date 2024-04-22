//Largest among n numbers using fuction
#include <stdio.h>
int largest(int num[10],int a)
{
    int larger=num[0];
    for(int i=1; i<a; i++)
    {
        if(num[i]>larger)
        {
            larger=num[i];
        }
    }
    return larger;
}

void main()
{
    int n,c;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array elements are:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
    c=largest(arr,n);
    printf("\nLargest Number is %d",c);
}

/*
Output
Enter the size of the array:
5
Enter elements:
11
22
33
44
55
Array elements are:
11      22      33      44  
Largest Number is 55
*/