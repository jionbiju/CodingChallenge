//
// Created by Jion Biju on 12/4/2022.
//Fuction with Argument and Without Return Value.
#include <iostream>

void sum(int,int);
int main()
{
    int a,b;
    std::cout<<"Enter 2 numbers:"<<std::endl;
    std::cin>>a>>b;
    sum(a,b);
    return 0;
}
void sum(int num1,int num2){
    int result;
    result=num1+num2;
    std::cout<<"Sum ="<<result;
}
/*==============OUTPUT==========
Enter 2 numbers:
88
77
Sum =165*/