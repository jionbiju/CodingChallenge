//
// Created by Jion Biju on 5/31/2023.
//
#include <iostream>

int main(){
    int num,sum=0;
    std::cout<<"Enter a limit:";
    std::cin>>num;
    std::cout<<"Odd numbers are:";
    for (int i=1;i<=num;i++) {
        if (i%2!=0){
            std::cout<<i<<",";
            sum=sum+i;
        }
    }
    std::cout<<"\nSum of odd numbers is "<<sum;
    return 0;
}