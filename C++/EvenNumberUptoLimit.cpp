//
// Created by Jion Biju on 11/6/2022.
//Even number upto limit using for..... loop.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter the limit:";
    std::cin>>n;
    std::cout<<"Even number upto "<<n<<".\n";
    for (int i=2;i<=n;i++) {
        if (i%2==0){
            std::cout<<i<<std::endl;
        }

    }
    return 0;
}

//=========================OUTPUT=========================
//Enter the limit:15
//Even number upto 15.
//2
//4
//6
//8
//10
//12
//14