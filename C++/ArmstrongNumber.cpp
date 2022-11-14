//
// Created by Jion Biju on 11/14/2022.
//To check whether the number is armstrong or not, using while loop.
#include <iostream>
int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    int number=n;
    int digit;
    int armstrong=0;
    while (n>0){
        digit=n%10;
        armstrong=armstrong+(digit*digit*digit);
        n=n/10;
    }

    if (armstrong==number){
        std::cout<<number<<" is armstrong number.";
    }
    else{
        std::cout<<number<<" is not a armstrong number.";
    }
    return 0;
}

//===============OUTPUT====================
//Enter a number:371
//371 is armstrong number.