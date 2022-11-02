//
// Created by Jion Biju on 11/2/2022.
//To check whether the number is positive or negative using if, else statement.
#include <iostream>

int main()
{
    int num;
    std::cout<<"Enter a number: ";
    std::cin>>num;
    if (num>0){
        std::cout<<num<<" is positive";
    }
    else{
        std::cout<<num<<" is negative";
    }
    return 0;
}

//========================OUTPUT===================================
//Enter a number:22
//22 is positive