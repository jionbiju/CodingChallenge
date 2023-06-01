//
// Created by Jion Biju on 6/1/2023.
//
#include <iostream>

int main(){
    int i,limit,arr[100],searchkey;
    int flag=0;
    std::cout<<"Enter array limit:";
    std::cin>>limit;
    std::cout<<"Enter values: ";
    for (i=0;i<limit;i++) {
        std::cin>>arr[i];
    }
    std::cout<<"Enter the search key: ";
    std::cin>>searchkey;
    for (i=0;i<limit;i++) {
        if (searchkey==arr[i]){
            flag=1;
            break;
        }
    }
    if (flag==1){
        std::cout<<"Value found at position "<<i+1;
    } else{
        std::cout<<"Value not found.";
    }
    return 0;
}