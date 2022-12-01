//
// Created by Jion Biju on 12/1/2022.
//Swap two numbers.
#include <iostream>

int main()
{
    int a,b,temp;
    std::cout<<"Enter two numbers: "<<std::endl;
    std::cin>>a>>b;
    std::cout<<"Numbers are:"<<a<<" & "<<b<<std::endl;
    temp=a;
    a=b;
    b=temp;
    std::cout<<"After swapping: "<<std::endl;
    std::cout<<"a="<<a<<", b="<<b<<std::endl;
    return 0;
}

/*=============OUTPUT=============
Enter two numbers:
10
2
Numbers are:10 & 2
After swapping:
a=2, b=10 */