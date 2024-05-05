/*Write a function namely myFact in C to find the factorial of a given number. Also, write
another function in C namely nCr which accepts two positive integer parameters n and r and
returns the value of the mathematical function C(n,r)( n! / ( r! x (n - r)!) ). The function nCr is
expected to make use of the factorial function myFact.*/
#include <stdio.h>
int myFact(int num)
{
    int f=1;
    for(int i=1; i<=num; i++)
    {
        f=f*i;
    }
    return f;
}

int nCr(int n, int r)
{
    int result;
    if(n<0 || r<0 || n<r)
    {
        printf("Enter valid input.\n");
        return 0;
    }
    else
    {
        result=myFact(n)/(myFact(r)*myFact(n-r));
    }
    return result;
}

void main()
{
    int c;
    int n,r;
    printf("Enter value of n:\n");
    scanf("%d",&n);
    printf("Enter value of r:\n");
    scanf("%d",&r);
    c=nCr(n,r);
    if(c!=0)
    printf("C(%d,%d)=%d",n,r,c);
}

/*
Output
Enter value of n:
3
Enter value of r:
2
C(3,2)=3

Enter value of n:
5
Enter value of r:
8
Enter valid input.

Enter value of n:
-6
Enter value of r:
7
Enter valid input.
*/