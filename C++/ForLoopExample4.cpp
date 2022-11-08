//
// Created by Jion Biju on 11/8/2022.
//For loop example 4.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<i+1;j++){
            std::cout<<" \t"<<i;
        }
        std::cout<<std::endl;
    }
    return 0;
}
//===========OUTPUT===============
//Enter a number:4
//1
//2       2
//3       3       3
//4       4       4       4
