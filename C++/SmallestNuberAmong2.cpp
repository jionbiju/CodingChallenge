//
// Created by Jion Biju on 11/1/2022.
// Find the smallest number among two
#include <iostream>

int main()
{ int a,b;
    std::cout<<"Enter first number"<<std::endl;
    std::cin>>a;
    std::cout<<"Enter the second number"<<std::endl;
    std::cin>>b;
    std::cout<<"First number is "<<a<<" Second number is "<<b<<std::endl;
    if(a<b){
        std::cout<<a<<" is Smaller";
    }else{
        std::cout<<b<<" is Smaller";
    }
    return 0;
}

//=====================OUTPUT====================
//Enter first number
//7
//Enter the second number
//10
//First number is 7 Second number is 10
//7 is Smaller

