#include <stdio.h>

void main(){
    int n;
    printf("Enter a limit:");
    scanf("%d",&n);
    int product;
    for (int i=1; i<=n; i++)
    {
        product=5*i;
        printf("5*%d = %d \n",i,product);
    
    }
    
}