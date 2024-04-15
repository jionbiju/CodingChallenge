//sum and average of elements of an array
#include <stdio.h>
void main()
{
    int i,n=0;
    float sum=0,avg;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0; i<n; i++)
    {
        sum=sum+arr[i];
    }
    printf("Sum of elements=%f\n",sum);
    avg=sum/n;
    printf("Averge=%f\n",avg);
}
/*
OUTPUT
Enter the size of the array:
5
Enter the elements:
1
2
3
4
5
Sum of elements=15.00
Averge=3.000000                     
*/ 