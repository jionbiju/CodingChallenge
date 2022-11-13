//
// Created by Jion Biju on 11/13/2022.
//Reverse of a number using while loop.
#include <iostream>
int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    int number=n;
    int digit;
    int rev=0;
    while (n>0){
        digit=n%10;
        rev=rev*10+digit;
        n=n/10;
    }
    std::cout<<"Reverse="<<rev;
    return 0;
}

//====================OUTPUT====================
//Enter a number:457
//Reverse=754
//
//==============================================
//Enter a number:457
//Reverse=754
