//
// Created by Jion Biju on 11/3/2022.
//Progarm to dispaly day of a week using if else statements/
#include <iostream>

int main()
{
    int day;
    std::cout<<"Enter a number between 1&7 :";
    std::cin>>day;
    if (day==1){
        std::cout<<"Sunday";
    }
    else if (day==2){
        std::cout<<"Monday";
    }
    else if (day==3){
        std::cout<<"Tuesday";
    }
    else if (day==4){
        std::cout<<"Wednesday";
    }
    else if (day==5){
        std::cout<<"Thusrday";
    }
    else if (day==6){
        std::cout <<"Friday";
    }
    else if (day==7){
        std::cout<<"Saturday";
    }
    else{
        std::cout<<"Invaild number";
    }
    return 0;
}

//=======================OUTPUT================================
//Enter a number between 1&7 :1
//Sunday
