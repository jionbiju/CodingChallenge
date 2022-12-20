//
// Created by Jion Biju on 12/20/2022.
//
#include <iostream>

int arr[100];
int n;
void insert();
void display();
int main()
{
    int a;
    std::cout<<"Enter a number:";
    std::cin>>a;
    switch (a) {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            std::cout<<"Wrong input";


    }
    return 0;
}

void insert(){
    std::cout<<"Enter array size:";
    std::cin>>n;
    std::cout<<"Enter array elements:";
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
}
void display(){
    std::cout<<"Array elements are:";
    for (int i=0;i<n;i++) {
        std::cout<<arr[i];
    }
}