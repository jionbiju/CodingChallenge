#include <stdio.h>
void main()
{
    int i,j ;
    char a[6]={'H','E','L','L','O','\0'};
    for(i=0; i<5;i++)
    {
        for(j=0; j<=i; j++)
        {
             printf("%c ",a[j]);
        }
         printf("\n");
    }
   
}

/*
OUTPUT

H 
H E
H E L
H E L L
H E L L O
*/