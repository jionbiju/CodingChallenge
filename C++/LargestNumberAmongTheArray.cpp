//
// Created by Jion Biju on 11/27/2022.
//To find largest element in an array.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter size of the array: ";
    std::cin>>n;
    int arr[n];
    int largest;
    std::cout<<"Enter the elements: ";
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    std::cout<<"The elements are:";
    for (int i=0;i<n;i++) {
        std::cout<<"'"<<arr[i]<<"'"<<std::endl;
    }
    largest=arr[0];
    for (int i=1;i<n;i++) {
        if (largest<arr[i]){
            largest=arr[i];
        }
    }
    std::cout<<"Largest element in the array is "<<largest;
    return 0;
}

/*=================OUTPUT============
Enter size of the array:5
Enter the elements:12
48
77
56
35
 The elements are:'25'
'11'
'44'
'2'
Largest element in the array is 77*/