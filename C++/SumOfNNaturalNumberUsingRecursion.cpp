//
// Created by Jion Biju on 1/14/2023.
//
#include <iostream>
int add(int n);

int main()
{
    int n;
    std::cout<<"Enter a positive integer: "<<std::endl;
    std::cin>>n;
    std::cout<<"Sum ="<<add(n);
    return 0;
}

int add(int n){
    if(n!=0)
        return n+ add(n-1);
}

//============output===========
//Enter a positive integer:
//2
//Sum =3