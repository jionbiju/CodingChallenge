#include <stdio.h>
void main()
{
    char temp, s[100];
    int len = 0;
    printf("Enter a string:");
    gets(s);
    //scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        len++;
    }
    printf("String length is %d\n", len);
    for (int j = 0; j < len / 2; j++)
    {
        temp = s[j];
        s[j] = s[len - 1 - j];
        s[len - 1 - j] = temp;
    }
    printf("Reverse of string is %s",s);
}

/*
OUTPUT
Enter a string:Hello
String length is 5
Reverse of string is olleH
*/