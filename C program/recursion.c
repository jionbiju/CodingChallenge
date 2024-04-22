#include <stdio.h>
int fab(int);
void main()
{
    int n;
    printf("Enter a limit:\n");
    scanf("%d",&n);
    printf("Fibonacci series are:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",fab(i));
    }
}

int fab(int a)
{
    if(a==0)
    return 0;
    else if(a==1)
    return 1;
    else
    return fab(a-1)+fab(a-2);
}

/*
Output
Enter a limit:
6
Fibonacci series are:
0       1       1       2       3       5
*/