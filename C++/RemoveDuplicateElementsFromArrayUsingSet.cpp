//
// Created by Jion Biju on 11/24/2022.
//Remove the duplicate element of a array using set.
#include <iostream>
#include <set>
int main()
{
    int n;
    std::cout<<"Enter size of  the array : ";
    std::cin>>n;
    int arr[n];
    std::set<int> newset;
    std::cout<<"Enter the element: "<<std::endl;
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    std::cout<<"\n Array elements are: "<<std::endl;
    for (int i=0;i<n;i++) {
        std::cout<<arr[i]<<std::endl;
    }
    for (int i=0;i<n;i++) {
        newset.insert(arr[i]);
    }

    std::cout<<"\n Array elements are afther deleting the duplicate element: "<<std::endl;
    for (auto itr : newset)
    {
        std::cout << itr << " ";
    }
    return 0;
}

//=============OUTPUT===============
//Enter size of  the array :5
//Enter the element:
//1
//2
//1
//5
//5
//
//Array elements are:
//1
//2
//1
//5
//5
//
//Array elements are afther deleting the duplicate element:
//1 2 5