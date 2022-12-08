//
// Created by Jion Biju on 12/8/2022.
//Factorial using fuction with argument and with return value.
#include <iostream>

int factorial(int);
int main()
{
    int n,k;
    std::cout<<"Enter a positive integer: "<<std::endl;
    std::cin>>n;
    k=factorial(n);
    std::cout<<"Factorial of "<<n<<"="<<k;
    return 0;
}
int factorial(int a){
    int fac=1;
    for (int i=1;i<=a;i++) {
        fac=fac*i;
    }
    return fac;
}
/*============OUTPUT==========
Enter a positive integer:
4
Factorial of 4=24*/