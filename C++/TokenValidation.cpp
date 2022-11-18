//
// Created by Jion Biju on 11/18/2022.
//If sum of the last 2 numbers of a 4 digit number is 10 or 15 then the it is a valid token else not.
//Example 1564 ==>6+4=10, then it is a valid token.
#include <iostream>

int main()
{
    int n;
    std::cout<<"Enter a 4 digit number: ";
    std::cin>>n;
    int num=n;
    int digit;
    int arr[4];
    int i=0;
    int sum;
    while (n>0){
        digit=n%10;
        arr[i]=digit;
        sum=arr[0]+arr[1];
        n=n/10;
        i++;
    }
    std::cout<<"You have entered "<<num<<std::endl;
    std::cout<<"sum of last 2 digits "<<arr[1]<<"+"<<arr[0]<<"="<<sum<<std::endl;
    if (sum==10||sum==15){
        std::cout<<"The token is valid.";
    }
    else{
        std::cout<<"The token is invalid";
    }

    return 0;
}


//=====================OUTPUT============
//Enter a 4 digit number:4578
//You have entered 4578
//sum of last 2 digits 7+8=15
//The token is valid.