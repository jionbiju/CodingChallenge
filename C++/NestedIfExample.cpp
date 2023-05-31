//
// Created by Jion Biju on 5/30/2023
//Different operation using if else statement.
#include <iostream>

int main(){
    int num1,num2,choice,result;
    std::cout<<"Enter 2 numbers: ";
    std::cin>>num1>>num2;
    std::cout<<"1.Addition \n 2.Substration \n 3.Multiplication \n 4.Division \n Enter your choice:";
    std::cin>>choice;
    if (choice==1){
     result=num1+num2;
     std::cout<<"Answer="<<num1<<"+"<<num2<<"="<<result;
    }
    else if (choice==2){
        result=num1-num2;
        std::cout<<"Answer="<<num1<<"-"<<num2<<"="<<result;
    }
    else if (choice==3){
        result=num1*num2;
        std::cout<<"Answer="<<num1<<"*"<<num2<<"="<<result;
    }
    else if (choice==4){
        result=num1/num2;
        std::cout<<"Answer="<<num1<<"/"<<num2<<"="<<result;
    } else{
        std::cout<<"Invalid input.";
    }
    return 0;
}