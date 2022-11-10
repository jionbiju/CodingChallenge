//
// Created by Jion Biju on 11/10/2022.
//For loop example 7
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    char alphabet='A';
    for (int i=n;i>=1;--i){
        for (int j=1;j<=i;j++){
            std::cout<<" \t"<<alphabet;
            alphabet++;
        }
        std::cout<<std::endl;
    }
    return 0;
}
//=============OUTPUT==============
//Enter a number:6
//        A       B       C       D       E       F
//        G       H       I       J       K
//        L       M       N       O
//        P       Q       R
//        S       T
//        U
