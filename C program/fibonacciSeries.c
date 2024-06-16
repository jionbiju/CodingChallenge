#include <stdio.h>
void main(){
    int i,num1=0,num2=1,num3,n;
    printf("Enter the limit:\n");
    scanf("%d",&n);
    printf("Fibonacci Series is\n");
    for(i=0; i<=n; i++){
        printf("%d\t",num1);
        num3=num1+num2;
        num1=num2;
        num2=num3;
    }
}

