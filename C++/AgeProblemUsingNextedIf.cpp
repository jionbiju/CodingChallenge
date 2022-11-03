//
// Created by Jion Biju on 11/3/2022.
//Age problem using nexted if.
#include <iostream>

int main()
{
    int age;
    std::cout<<"Enter your age: ";
    std::cin>>age;
    if (age<25){
        std::cout<<"Your age is "<<age<<".";
        if (age<=14){
            std::cout<<"\n You are a child.";
        }
        else{
            std::cout<<"\n You are young.";
        }
    }
    else{
        std::cout<<"Your age is "<<age<<".";
        if (age<=64){
            std::cout<<"\n You are a adult.";
        }
        else{
            std::cout<<"\n You are a senior citizen.";
        }
    }
    return 0;
}

//====================OUTPUT========================
//Enter your age:25
//Your age is 25.
//You are a adult.