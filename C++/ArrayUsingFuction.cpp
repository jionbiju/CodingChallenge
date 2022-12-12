//
// Created by Jion Biju on 12/12/2022.
//Array using fuction.
#include <iostream>
void array();
int main()
{
    array();
    return 0;
}
void array(){
    int n;
    std::cout<<"Enter array size:";
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter array elements: "<<std::endl;
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    std::cout<<"Array elements are:"<<std::endl;
    for (int i=0;i<n;i++) {
        std::cout<<arr[i]<<std::endl;
    }
}

/*=============OUTPUT==============
Enter array size:4
Enter array elements:
74
85
12
99
Array elements are:
74
85
12
99*/
