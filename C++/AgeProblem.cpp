//
// Created by Jion Biju on 11/1/2022.
//find wheather the person is adult or minor.
#include <iostream>

int main()
{
    int age;
    std::cout<<"Enter your age :";
    std::cin>>age;
    if(age>=18){
        std::cout<<"Your age is "<<age<<". you are a adult.";
    }
    else{
        std::cout<<"Your age is "<<age<<". you are a minor.";
    }
    return 0;
}

//=======================OUTPUT=====================
//Enter your age :10
//Your age is 10. you are a minor.
