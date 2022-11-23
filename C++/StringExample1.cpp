//
// Created by Jion Biju on 11/23/2022.
//Palindrom of words.
#include <algorithm>
#include <iostream>
#include <string>
int main()
{
    std::string str;
    std::cout<<"Enter the string: ";
    std::cin>>str;
    std::string words=str;
    reverse(str.begin(), str.end());
    std::cout<<"Reverse of the string is :"<<str<<std::endl;
    if (words==str){
        std::cout<<words<<" is a palindrom."<<std::endl;
    }
    else{
        std::cout<<words<<" is not a palindrom.";
    }

    return 0;
}

//==============OUTPUT===========
//Enter the string:malayalam
//Reverse of the string is :malayalam
//malayalam is a palindrom.