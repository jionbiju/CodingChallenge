//
// Created by Jion Biju on 11/9/2022.
//For loop example 7
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    for (int i=n;i>=1;--i){
        for (int j=1;j<=i;j++){
            std::cout<<" \t"<<"*";
        }
        std::cout<<std::endl;
    }
    return 0;
}

//=============OUTPUT===========
//Enter a number:5
//*       *       *       *       *
//*       *       *       *
//*       *       *
//*       *
//*
