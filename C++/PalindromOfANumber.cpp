//
// Created by Jion Biju on 11/13/2022.
//Check whether the number palindrome or not.
#include <iostream>
int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    int number=n;
    int digit;
    int rev=0;
    while (n>0){
        digit=n%10;
        rev=rev*10+digit;
        n=n/10;
    }
   if (rev==number){
       std::cout<<number<<" is palindrome";
   }
   else{
       std::cout<<number<<" is not palindrome";
   }
    return 0;
}

//========================OUTPUT========================

//Enter a number:254
//254 is not palindrome

//======================================================
//Enter a number:121
//121 is palindrome        