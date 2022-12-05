//
// Created by Jion Biju on 12/5/2022.
//Fuction with Argument and With Return Value.
#include <iostream>
int sum(int,int);
int main()
{
    int a,b,k;
    std::cout<<"Enter 2 numbers:"<<std::endl;
    std::cin>>a>>b;
    k=sum(a,b);
    std::cout<<"Sum ="<<k;
    return 0;
}
int sum(int num1,int num2){
    int result;
    result=num1+num2;
    return result;
}

/*=============OUTPUT=============
Enter 2 numbers:
4
1
Sum =5*/