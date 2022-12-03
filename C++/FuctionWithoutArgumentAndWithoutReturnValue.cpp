//
// Created by Jion Biju on 12/3/2022.
//Fuction without Argument and Without Return Value.
#include <iostream>
void sum(){
    int a,b,c;
    std::cout<<"Enter 2 numbers:"<<"\n";
    std::cin>>a>>b;
    c=a+b;
    std::cout<<"Result="<<a<<"+"<<b<<"="<<c;
}
int main()
{
    sum();
    return 0;
}
/*===========OUTPUT=============
Enter 2 numbers:
20
17
Result=20+17=37*/
