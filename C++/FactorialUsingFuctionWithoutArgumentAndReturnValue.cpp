//
// Created by Jion Biju on 12/7/2022.
//Factorial using Fuction without Argument and Without Return Value.
#include <iostream>

void factorial();
int main()
{
    factorial();
    return 0;
}
void factorial(){
    int n;
    std::cout<<"Enter a positive integer:"<<std::endl;
    std::cin>>n;
    int fac=1;
    for (int i=1;i<=n;i++) {
        fac=fac*i;
    }
    std::cout<<"Factorial of "<<n<<"="<<fac;
}

/*============OUTPUT===========
Enter a positive integer:
5
Factorial of 5=120*/