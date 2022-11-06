//
// Created by Jion Biju on 11/6/2022.
//Odd number upto limit using for...loop.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter the limit:";
    std::cin>>n;
    std::cout<<"Odd number upto "<<n<<".\n";
    for (int i=1;i<=n;i++) {
        if (i%2!=0){
            std::cout<<i<<std::endl;
        }

    }
    return 0;
}

//=================OUTPUT=================
//Enter the limit:7
//Odd number upto 7.
//1
//3
//5
//7
