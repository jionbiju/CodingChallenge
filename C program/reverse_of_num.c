#include <stdio.h>

void main(){
    int n, digit;
    printf("Enter a number:");
    scanf("%d", &n);
    int num=n;
    int rev = 0;
    while (n > 0)
    {
        digit = n % 10;
        rev = rev*10+digit;
        n=n/10;
    }
    printf("Reverse of %d =%d",num,rev);
}