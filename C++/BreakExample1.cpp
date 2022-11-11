//
// Created by Jion Biju on 11/11/2022.
//Break example.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    for (int i=0;i<n;i++) {
        if (i==5){
            break;
        }
        std::cout<<"\t"<<i;
    }
    return 0;
}

//==================OUTPUT================
//Enter a number:45
//0       1       2       3       4