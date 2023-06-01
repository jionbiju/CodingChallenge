//
// Created by Jion Biju on 6/1/2023.
//Write a program to find the number of even numbers in an array
#include <iostream>

int main(){
    int limit,i,arr[100];
    int even=0;
    std::cout<<"Enter array limit:";
    std::cin>>limit;
    std::cout<<"Enter array elements: \n";
    for (i=0; i<limit;i++) {
        std::cin>>arr[i];
    }
    for (i=0;i<limit;i++) {
        if (arr[i]%2==0){
            even++;
        }
    }
    std::cout<<"Total number of even numbers= "<<even;

    return 0;
}

//===========OUTPUT============
//Enter array limit:5
//Enter array elements:
//77
//6
//3
//2
//1
//Total number of even numbers= 2