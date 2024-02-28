#include <stdio.h>

void main(){
    int ch;
    float area;
    printf("Enter your choice : \n 1-Circle \n 2- Triangle \n 3-Square");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:{
            int r;
            printf("Enter radius of the circle:");
            scanf("%d",&r);
            area=3.14*r*r;
            break;
    }
    case 2:{
            int b,h;
            printf("Enter height & breadth");
            scanf("%d%d",&b,&h);
            area=b*h*0.5;
            break; 
    }
    case 3:{
            int a;
            printf("Enter side of the square");
            scanf("%d",&a);
            area=a*a;
            break;
    }
    default:printf("Enter number between 1 to 3");
        break;
    }
    printf("Area=%f",area);
}