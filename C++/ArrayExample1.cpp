//
// Created by Jion Biju on 11/15/2022.
//Display the value stored in the array.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a array limit: ";
    std::cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        std::cout<<"Enter the element: ";
        std::cin>>arr[i];
    }
        std::cout<<"Array elements are: "<<"\n";
    for (int i=0; i<n; i++) {
        std::cout<<arr[i]<<"\n";
    }
    return 0;
}
//===========OUTPUT==============
//Enter a array limit:4
//Enter the element:454
//Enter the element:444
//Enter the element:777
//Enter the element:4444
//Array elements are:
//454
//444
//777
//4444
