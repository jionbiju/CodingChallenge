#include<stdio.h>
void main()
{
    int n1,n2,n3;
    printf("Enter 3 numbers:\n");
    scanf("%d%d%d",&n1,&n2,&n3);
    if(n1>n2)
    {
        if(n1>n3)
        {
            printf("Largest element is %d",n1);
        }
        else
        {
             printf("Largest element is %d",n3);
        }
    }
    else
    {
        if(n2>n3)
        {
             printf("Largest element is %d",n2);
        }
        else
        {
             printf("Largest element is %d",n3);
        }
    }
}