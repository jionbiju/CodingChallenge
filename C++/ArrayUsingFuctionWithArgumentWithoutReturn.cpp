//
// Created by Jion Biju on 12/14/2022.
//Array using fuction with argument and without return value.
#include <iostream>
void array(int);
int main()
{
    int n;
    std::cout<<"Enter array size: ";
    std::cin>>n;
    array(n);
    return 0;
}
void array(int a){
    int arr[a];
    std::cout<<"Enter array elements:"<<std::endl;
    for (int i=0;i<a;i++) {
        std::cin>>arr[i];
    }
    std::cout<<"Array elements are:"<<std::endl;
    for (int i=0;i<a;i++) {
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
