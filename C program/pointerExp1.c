//Write a C program to reverse a string using pointers.
#include <stdio.h>
#include <string.h>
void main()
{
    char temp, s[100];
    int len;
    printf("Enter a string:");
    gets(s);
    char *ptr=s;
    char *t=&temp;
    len=strlen(ptr);;
    for (int j = 0; j < len / 2; j++) {
        *t = *(ptr + j);
        *(ptr + j) = *(ptr + len - 1 - j);
        *(ptr + len - 1 - j) = *t;
    }
    printf("Reverse of string is %s",ptr);
}
/*
Output
Enter a string:jion biju
Reverse of string is ujib noij
*/