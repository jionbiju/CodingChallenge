//
// Created by Jion Biju on 11/1/2022.
//Find the largest number among three numbers using if,else if statement

#include <iostream>

int main()
{
    int a,b,c;
    std::cout<<"Enter first number"<<std::endl;
    std::cin>>a;
    std::cout<<"Enter the second number"<<std::endl;
    std::cin>>b;
    std::cout<<"Enter the third number"<<std::endl;
    std::cin>>c;
    std::cout<<"First number is "<<a<<" Second number is "<<b<<" Third number is "<<c<<std::endl;
    if(a>b && a>c){
        std::cout<<a<<" is Greater";
    }
    else if(b>a && b>c){
        std::cout<<b<<" is Greater";
    }
    else {
        std::cout<<c<<" is Greater";
    }
    return 0;
}

//================OUTPUT=======================
//Enter first number
//15
//Enter the second number
//5
//Enter the third number
//30
//First number is 15 Second number is 5 Third number is 30
//30 is Greater

