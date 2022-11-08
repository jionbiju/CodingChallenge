//
// Created by Jion Biju on 11/8/2022.
//For loop example 5.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number:";
    std::cin>>n;
    int count=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            std::cout<<" \t"<<count;
            count++;
        }
        std::cout<<std::endl;
    }
    return 0;
}

//============OUTPUT==============
//Enter a number:4
//1
//2       3
//4       5       6
//7       8       9       10