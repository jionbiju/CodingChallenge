//
// Created by Jion Biju on 1/23/2023.
//Bubble sort.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter the array size: "<<std::endl;
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter the array elements: "<<std::endl;
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    std::cout<<"Array elements are :\n";
    for (int i=0;i<n;i++) {
        std::cout<<arr[i]<<" ";

    }
    int temp;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<(n-1-i);j++) {
            if (arr[j]>arr[j+1]){
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }

        }

    }
    std::cout<<"\nSorted elements are :\n";
    for (int i=0;i<n;i++) {
        std::cout<<arr[i]<<" ";

    }
    return 0;
}
//==================OUTPUT==========
//Enter the array size:
//4
//Enter the array elements:
//8
//3
//2
//1
//Array elements are :
//8 3 2 1
//Sorted elements are :
//1 2 3 8