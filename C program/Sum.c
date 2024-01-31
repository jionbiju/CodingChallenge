#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a,b,c;
    printf("enter a num :7");
    scanf("%d",&a);
    printf("\nyou have entered %d",a);
    printf("\nEnter another number ");
    scanf("%d",&b);
    c=a+b;
    printf("Sum= %d",c);

    return EXIT_SUCCESS;
}