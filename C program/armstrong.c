/* Armstrong number between 100 and 1000*/

#include <stdio.h>
void main()
{
    int d,sum,temp;
    for(int i=100; i<1000; i++)
    {
        temp=i;
        sum=0;
        while (temp!=0)
        {
         d=temp%10;
         sum=sum+(d*d*d);
         temp=temp/10;
        }
        if(sum==i)
        {
            printf("%d\t",i);
        }

    }
}

//Output
//153     370     371     407