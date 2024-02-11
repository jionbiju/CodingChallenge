#include <stdio.h>

void main (){
    int a,b,temp;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    printf("You have entered %d & %d \n",a,b);

    temp=a;
    a=b;
    b=temp;
    printf("After swaping numbers are %d & %d",a,b);
    
}