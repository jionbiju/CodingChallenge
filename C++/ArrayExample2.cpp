//
// Created by Jion Biju on 11/16/2022.
//Array example 2
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter the limit of the String: ";
    std::cin>>n;
    char letter[n];
    for (int i=0;i<n;i++) {
        std::cout<<"Enter a letter: ";
        std::cin>>letter[i];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<i+1;j++) {
            std::cout<<"\t"<<letter[j];
        }
        std::cout<<std::endl;
    }
    return 0;
}

//===============OUTPUT===================
//Enter the limit of the String:4
//Enter a letter:J
//Enter a letter:I
//Enter a letter:O
//Enter a letter:N
//        J
//        J       I
//        J       I       O
//        J       I       O       N
