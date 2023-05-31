//
// Created by Jion Biju on 5/31/2023.
//Write a program to print the multiplication table of given number.
#include <iostream>

int main(){
    int num,result;
    std::cout<<"Enter a number:";
    std::cin>>num;
    for (int i = 1; i <=10 ; i++) {
        result=i*num;
        std::cout<<i<<"*"<<num<<"="<<result<<"\n";
    }
    return 0;
}