//
// Created by Jion Biju on 12/15/2022.
//
#include <iostream>

void insert();
void display(int [],int );
int main()
{
    insert();
    return 0;
}

void insert(){
    int n;
    std::cout<<"Enter array size:";
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter the array elements:";
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    display(arr,n);
}

void display(int arr[],int n){
    std::cout<<"Array elements are:";
    for (int i = 0; i < n; i++) {
        std::cout<<arr[i]<<std::endl;
    }
}
/*==========OUTPUT============
Enter array size:6
Enter the array elements:47
95
78
14
23
157
Array elements are:47
95
78
14
23
157*/