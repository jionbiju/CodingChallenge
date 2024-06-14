//Write a C Program to check if a given number is a strong number or not.
#include <stdio.h>
void main(){
    int num,d,temp,sum=0,f;
    printf("Enter a number:");
    scanf("%d",&num);
    temp=num;
    while(num>0){
        d=num%10;
        f=1;
        for(int i=1;i<=d; i++){
            f=f*i;
        }
        sum=sum+f;
        num=num/10;
    }
    if(sum==temp)
    printf("\n%d is a Strong Number\n",temp);
    else
    printf("%d is not a Strong Number.",temp);
}
/*
OUTPUT
Enter a number:145

145 is Strong Number

Enter a number:333
333 is not a Strong Number.
*/