//
// Created by Jion Biju on 12/14/2022.
//Array using fuction with argument and without return value.
#include <iostream>
void display(int [],int );
int main()
{
    int n;
    std::cout<<"Enter array size: ";
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter array elements:"<<std::endl;
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    display(arr,n);
    return 0;
}
void display(int arr[],int n){
    std::cout<<"Array elements are:"<<std::endl;
    for (int i=0;i<n;i++) {
        std::cout<<arr[i]<<std::endl;
    }
}

/*==========OUTPUT============
Enter array size:4
 Enter array elements:
44
77
88
99
Elements are:
44
77
88
99*/
