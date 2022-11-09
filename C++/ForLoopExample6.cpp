//
// Created by Jion Biju on 11/9/2022.
//For loop example
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    char alphabet='A';
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            std::cout<<" \t"<<alphabet;
            alphabet++;
        }
        std::cout<<std::endl;
    }
    return 0;
}
//===================OUTPUT===================
//Enter a number:5
//        A
//        B       C
//        D       E       F
//        G       H       I       J
//        K       L       M       N       O
