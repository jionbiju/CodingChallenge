//
// Created by Jion Biju on 11/2/2022.
//Check whether the number is even or odd using if, else statement.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    if (n%2==0){
        std::cout<<n<<" is even";
    }
    else{
        std::cout<<n<<" is odd";
    }
    return 0;
}

//====================OUTPUT=========================
//Enter a number:75
//75 is old

