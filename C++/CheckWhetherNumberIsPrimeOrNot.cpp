//
// Created by Jion Biju on 11/20/2022.
//To check whether the number is prime or not.
#include <iostream>

int main()
{
    int n;
    bool is_prime= true;
    std::cout<<"Enter a positive integer: ";
    std::cin>>n;
    if (n==0||n==1){
        is_prime= false;
    }
    if(n>2){
    for (int i=2;i<=n/2;i++) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }
    }
    if (is_prime) {
        std::cout << n << " is a prime number." << std::endl;
    } else {
        std::cout << n << " is not a prime number.";
    }

    return 0;
}

//========OUTPUT=========
//Enter a positive integer:7
//7 is a prime number.