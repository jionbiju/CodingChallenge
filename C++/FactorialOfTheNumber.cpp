//
// Created by Jion Biju on 11/24/2022.
//Factorial of a number using for loop.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    long fac=1;
    for (int i=1;i<=n;i++) {
        fac=fac*i;
    }
    std::cout<<"Factorial of "<<n<<" ="<<fac;
    return 0;
}

//===============OUTPUT=============
//Enter a number:6
//Factorial of 6 =720
