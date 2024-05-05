/*
Read two inputs each representing the distances between two points in the Euclidean space, store these in
structure variables and add the two distance values.
*/
#include <stdio.h>
#include <math.h>
struct point
{
    float x;
    float y;
}p1,p2;
void main()
{
    float x,y,distance;
    printf("Enter the x and y coordiantes of point 1.\n");
    scanf("%f%f",&p1.x,&p1.y);
    printf("Enter the x and y coordiantes of point 2.\n");
    scanf("%f%f",&p2.x,&p2.y);
    x=p2.x-p1.x;
    y=p2.y-p1.y;
    distance=sqrt((x*x)+(y*y));
    printf("Distance between point 1 and point 2 is %f\n",distance);
}

/*
Output
Enter the x and y coordiantes of point 1.
2
4
Enter the x and y coordiantes of point 2.
5
3
Distance between point 1 and point 2 is 3.162278
*/