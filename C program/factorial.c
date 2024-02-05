#include <stdio.h>

void main (){
    int n;
    int f=1;
    printf("Enter a number:");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        f=f*i;
    }
    printf("Factorial is %d",f);
}