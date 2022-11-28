//
// Created by Jion Biju on 11/28/2022.
//To find smallest element in an array.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter the limit of the array: ";
    std::cin>>n;
    int arr[n];
    int smallest;
    std::cout<<"\nEnter the elements: "<<std::endl;
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    std::cout<<"Array elements are: "<<std::endl;
    for (int i=0;i<n;i++) {
        std::cout<<arr[i]<<std::endl;
    }
    smallest=arr[0];
    for (int i=1; i<n;i++) {
        if (smallest>arr[i]){
            smallest=arr[i];
        }

    }
    std::cout<<"Smallest element in the array is "<<smallest;

    return 0;
}

/*=============OUTPUT=============
Enter the limit of the array:4

Enter the elements:
77
88
99
44
Array elements are:
77
88
99
44
Smallest element in the array is 44 */