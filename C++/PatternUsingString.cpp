//
// Created by Jion Biju on 11/17/2022.
//Pattern using string.
#include <iostream>

int main()
{
    std::string text;
    std::cout<<"Enter the string: ";
    std::cin>>text;
    std::cout<<"The string you have entered: "<<text<<std::endl;
    for (int i=0;i<text.length();i++) {
        for (int j=0;j<i+1;j++) {
            std::cout<<"\t"<<text[j];
        }
        std::cout<<std::endl;
    }
    return 0;
}
//=============OUTPUT==============
//Enter the string:JION
//The string you have entered: JION
//        J
//        J       I
//        J       I       O
//        J       I       O       N
