//
// Created by Jion Biju on 12/7/2022.
//Fuction without Argument and With Return Value.
#include <iostream>

int sum();
int main()
{
    int k;
    k=sum();
    std::cout<<"sum ="<<k;
    return 0;
}
int sum(){
    int a,b,c;
    std::cout<<"Enter 2 numbers:"<<std::endl;
    std::cin>>a>>b;
    c=a+b;
    return c;

}
/*=====OUTPUT==========
Enter 2 numbers:
7
8
sum =15*/