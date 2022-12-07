//
// Created by Jion Biju on 12/7/2022.
//Factorial using fuction with argument and without return value.
#include <iostream>
void factorial(int);
int main()
{
    int n;
    std::cout<<"Enter a positive integer:"<<std::endl;
    std::cin>>n;
    factorial(n);
    return 0;
}
void factorial(int a){
    int fac=1;
    for (int i=1;i<=a;i++) {
        fac=fac*i;
    }
    std::cout<<"Factoral of "<<a<<"="<<fac;
}

/*=========OUTPUT===========
Enter a positive integer:
6
Factoral of 6=720*/