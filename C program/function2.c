/*Write a C program to find the value of a mathematical function f which is defined as follows.
f(n) = n! / (sum of factors of n), if n is not prime and
f(n) = n! / (sum of digits of n), if n is prime.
*/
#include <stdio.h>
int fact(int num)
{
    int i,f=1;
    for(i=1; i<=num; i++)
    {
        f=f*i;
    }
    return f;
}

int prime(int num)
{
    if(num <=1)
    return 0;
    for(int i=1; i<num/2; i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int sumOfFact(int num)
{
    int i,sum=0;
    for(i=1; i<=num; i++)
    {
        if(num%i==0)
        sum+=i;
    }
    return sum;
}

int sumOfDigit(int num)
{
    int d,sum=0;
    while(num!=0)
    {
        d=num%10;
        sum+=d;
        num=num/10;
    }
    return sum;
}

int calc(int n)
{
    int result;
    if(prime(n))
    {
        result=fact(n)/sumOfDigit(n);
    }
    else
    {
        result=fact(n)/sumOfFact(n);
    }   
    return result;
}
void main()
{
    int a,c;
    printf("Enter a positive number\n");
    scanf("%d",&a);
    if(a<1)
    printf("Invalid input.\n");
    c=calc(a);
    printf("f(%d)=%d",a,c);
}

/*
Output
Enter a positive number
6
f(6)=60

Enter a positive number
-7
Invalid input
*/