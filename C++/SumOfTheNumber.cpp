//
// Created by Jion Biju on 11/18/2022.
//Sum of the Number Problem.
//example 123
//1+2+3=6
#include <iostream>

int main()
{
    int num;
    std::cout<<"Enter a number: ";
    std::cin>>num;
    int digit;
    int sum=0;
    std::cout<<"Sum of ";
    while (num>0){
        digit=num%10;
        std::cout<<digit<<"+";
        sum=sum+digit;
        num=num/10;
    }
    std::cout<<"="<<sum;
    return 0;
}
