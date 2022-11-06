//
// Created by Jion Biju on 11/6/2022.
//
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    std::cout<<"Multiplication table of "<<n<<" is given below:\n";
    for (int i=1;i<=10;i++) {
        std::cout<<i<<"*"<<n<<"="<<i*n<<std::endl;
    }
    return 0;
}

//===============================OUTPUT=============================
//Enter a number:5
//Multiplication table of 5 is given below
//1*5=5
//2*5=10
//3*5=15
//4*5=20
//5*5=25
//6*5=30
//7*5=35
//8*5=40
//9*5=45
//10*5=50


