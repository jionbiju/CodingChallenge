//
// Created by Jion Biju on 11/15/2022.
//Diaplay n natural number using while loop.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a limit: ";
    std::cin>>n;
    int i=0;
    while (i<=n){
        std::cout<<i<<std::endl;
        i++;
    }
    return 0;
}
//==================OUTPUT======================
//Enter a limit:6
//0
//1
//2
//3
//4
//5
//6
