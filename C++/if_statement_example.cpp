//
// Created by Jion Biju on 11/1/2022.
//To display 'You have passed' if score is 18 or more using if statement.
#include <iostream>

int main()
{
    int score;
    std::cout<<"Enter your score: ";
    std::cin>>score;
    if (score>=18){
        std::cout<<"You have passed."<<std::endl;
    }
    std::cout<<"Program finished";
    return 0;
}

//==========================OUTPUT=======================
//Enter your score:55
//You have passed.
//Program finished

