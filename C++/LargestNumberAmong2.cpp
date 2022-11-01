//
// Created by Jion Biju on 11/1/2022.
//
#include <iostream>

int main()
{
    int a,b;
    std::cout<<"Enter first number"<<std::endl;
    std::cin>>a;
    std::cout<<"Enter the second number"<<std::endl;
    std::cin>>b;
    std::cout<<"First number is "<<a<<" Second number is "<<b<<std::endl;
    if(a>b){
        std::cout<<a<<" is Greater";
    }else{
        std::cout<<b<<" is Greater";
    }

    return 0;
}
//=================OUTPUT=================
//Enter first number
//20
//Enter the second number
//10
//First number is 20 Second number is 10
//20 is Greater

