//
// Created by Jion Biju on 11/6/2022.
//Display n natural number using for......loop
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a limit: ";
    std::cin>>n;
    std::cout<<"The numbers are "<<std::endl;
    for (int i=1;i<=n;i++) {
        std::cout<<i<<std::endl;
    }
    return 0;
}

//===================OUTPUT===============
//Enter a limit:5
//The numbers are
//1
//2
//3
//4
//5