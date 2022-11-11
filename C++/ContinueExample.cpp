//
// Created by Jion Biju on 11/11/2022.
//Continue example.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    for (int i=0;i<=n;i++) {
        if (i==6){
            continue;
        }
        std::cout<<"\t"<<i;
    }
    return 0;
}

//==================OUTPUT================
//Enter a number:10
//0       1       2       3       4       5       7       8       9