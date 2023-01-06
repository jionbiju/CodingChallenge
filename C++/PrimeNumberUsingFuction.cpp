//
// Created by Jion Biju on 1/6/2023.

//Implement using functions to check whether the given number is prime and
//display appropriate messages (No built in Math Function).

#include <iostream>
int checkprime(int);
int main()
{
    int n;
    std::cout<<"Enter a integer:"<<std::endl;
    std::cin>>n;
    if (checkprime(n)){
        std::cout<<n<<" is prime number.";
    }
    else{
       std::cout<<n<<" is not a prime number.";
    }
    return 0;
}

int checkprime(int n){
    bool prime= true;
    if (n==0||n==1 || n<0){
        prime= false;
    }
    for (int i=2;i<=n/2;i++) {
        if (n%i==0){
            prime= false;
        }
    }
    return prime;
}

/*===================OUTPUT===============
Enter a positive integer:
7
7 is prime.*/