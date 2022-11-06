//
// Created by Jion Biju on 11/6/2022.
//Addition table using for...loop.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    std::cout<<"Addition table of "<<n<<" is given below:\n";
    for (int i=0;i<=10;i++) {
        std::cout<<i<<"+"<<n<<"="<<i+n<<std::endl;
    }
    return 0;
}

//==============OUTPUT========================
//Enter a number:8
//Addition table of 8 is given below:
//0+8=8
//1+8=9
//2+8=10
//3+8=11
//4+8=12
//5+8=13
//6+8=14
//7+8=15
//8+8=16
//9+8=17
//10+8=18
