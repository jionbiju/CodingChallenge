//
// Created by Jion Biju on 11/7/2022.
//
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<i+1;j++){
            std::cout<<" \t"<<j;
        }
        std::cout<<std::endl;
    }
    return 0;
}