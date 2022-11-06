//
// Created by Jion Biju on 11/6/2022.
//Sum of n natural number using for..loop.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a positive integer:";
    std::cin>>n;
    int sum;
    for (int i=0;i<=n;i++) {
        sum+=i;
    }
    std::cout<<"Sum = "<<sum;
    return 0;
}

//========OUTPUT==========
//Enter a positive integer:5
//Sum = 15
