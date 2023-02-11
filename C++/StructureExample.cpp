//
// Created by Jion Biju on 1/26/2023.
//Structure example.
#include <iostream>
struct person{
    char name[50];
    int age;
    float salary;
};

int main()
{
    person p1;
    std::cout<<"Enter your name: "<<std::endl;
    std::cin>>p1.name;
    std::cout<<"Enter your age :"<<std::endl;
    std::cin>>p1.age;
    std::cout<<"Enter your salary: "<<std::endl;
    std::cin>>p1.salary;
    std::cout<<"\nDisplaying Information"<<std::endl;
    std::cout<<"\nName:"<<p1.name;
    std::cout<<"\nAge:"<<p1.age;
    std::cout<<"\nSalary:"<<p1.salary;
    return 0;
}

//===================OUTPUT===============
//Enter your name:
//Ronaldo
//        Enter your age :
//37
//Enter your salary:
//10000
//
//Displaying Information
//
//Name:Ronaldo
//        Age:37
//Salary:10000