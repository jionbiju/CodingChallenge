#include <stdio.h>

void main(){
    int num,d;
    int digit=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    int temp=num;

    while (num>0)
    {
        d=num%10;
        digit=digit*10+d;
        num=num/10;
    }
    if (temp==digit)
    {
        printf("%d is Palindrom",temp);
    }
    else{
        printf("%d is not palindrom",temp);
    }
    
    
}