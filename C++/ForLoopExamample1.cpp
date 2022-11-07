//
// Created by Jion Biju on 11/7/2022.
//For loop example 1.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++){
            std::cout<<" \t"<<j;
        }
        std::cout<<std::endl;
    }
    return 0;
}

//==========OUTPUT==================
//Enter a number:4
//1       2       3       4
//1       2       3       4
//1       2       3       4
//1       2       3       4
