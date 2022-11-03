//
// Created by Jion Biju on 11/3/2022.
//Grade problem using else if ladder.
#include <iostream>

int main()
{
    int score;
    std::cout<<"Enter your score: ";
    std::cin>>score;
    if (score>=80){
        std::cout<<"A Grade"<<"\n You have passed";
    }
    else if (score>=60){
        std::cout<<"B Grade"<<"\n You have passed";
    }
    else if (score>=40){
        std::cout<<"C Grade"<<"\n You have passed";
    }
    else if (score>=30){
        std::cout<<"D Grade"<<"\n You have passed";
    }
    else{
        std::cout<<"E Grade"<<"\n You failed";
    }
    return 0;
}

//============================OUTPUT==========================
//Enter your score:95
//A Grade
//You have passed
