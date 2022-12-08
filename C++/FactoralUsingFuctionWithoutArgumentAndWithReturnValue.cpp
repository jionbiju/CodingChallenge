//
// Created by Jion Biju on 12/8/2022.
//Factorial using fuction without argument and with return value.
#include <iostream>

int factorial();
int main()
{
    int k;
    k=factorial();
    std::cout<<"Factorial "<<"= "<<k;
    return 0;
}

int factorial(){
    int n;
    std::cout<<"Enter a positive integer: "<<std::endl;
    std::cin>>n;
    int fac=1;
    for (int i=1;i<=n;i++) {
        fac=fac*i;
    }
    return fac;
}
/*============OUTPUT==========
Enter a positive integer:
4
Factorial =24*/