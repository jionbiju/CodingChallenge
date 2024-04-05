//Palindrome of a string without using string handaling functions
#include <stdio.h>
void main()
{
    int n=0,flag=1;
    char a[50];
    printf("Enter a string:\n");
    scanf("%[^\n]s",a);
    for(int i=0; a[i]!='\0'; i++)
    {
        n++;
    }
    for(int i=0; i<n/2; i++)
    {
        if(a[i]!=a[n-1-i])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    printf("Palindrome");
    else
    printf("Not Palindrome");
}


/*
OUTPUT
Enter a string:
malayalam
Palindrome

Enter a string:
hello
Not Palindrome

*/