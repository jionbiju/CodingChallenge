//
// Created by Jion Biju on 1/18/2023.
//Write functions to implement string operations such as compare, concatenate, string
//length. Convince the parameter passing techniques.
#include <iostream>
std::string str1,str2;
void compare();
void concatenate();
void len();

int main()
{
    std::cout<<"Enter a string: "<<std::endl;
    std::cin>>str1;
    std::cout<<"Enter another string: \n";
    std::cin>>str2;
    int choice=1;
    while(choice){
        std::cout<<"-----------MENU-------------"<<std::endl;
        std::cout<<"1.Compare"<<std::endl;
        std::cout<<"2.Concatenate"<<std::endl;
        std::cout<<"3.String Length"<<std::endl;
        std::cout<<"4.Exit"<<std::endl;
        std::cout<<"------------------------------"<<std::endl;
        std::cout<<"Enter your choice:\n";
        std::cin>>choice;
        switch (choice) {
            case 1:compare();
                break;
            case 2:concatenate();
                break;
            case 3:len();
                break;
            case 4:
                exit(0);
            default:
                std::cout<<"Invalid choice.";
                break;

        }

    }
    return 0;
}

void compare(){
    std::cout<<"First string is "<<str1<<std::endl;
    std::cout<<"Second string is "<<str2<<std::endl;
    if (str1==str2){
        std::cout<<"Strings are equal\n";
    }
    else{
        std::cout<<"Strings are not equal.\n";
    }
}

void concatenate(){
    std::string result;
    result=str1+str2;
    std::cout<<"Concatenate string is "<<result<<std::endl;
}

void len(){
    std::cout<<"Length of "<<str1<<" is "<<str1.length()<<std::endl;
    std::cout<<"Length of "<<str2<<" is "<<str2.length()<<std::endl;
}

/*==============OUTPUT==============
Enter a string:
india
        Enter another string:
kerala
-----------MENU-------------
1.Compare
2.Concatenate
3.String Length
4.Exit
------------------------------
Enter your choice:
1
First string is india
Second string is kerala
Strings are not equal.
-----------MENU-------------
1.Compare
2.Concatenate
3.String Length
4.Exit
------------------------------
Enter your choice:
2
Concatenate string is indiakerala
-----------MENU-------------
1.Compare
2.Concatenate
3.String Length
4.Exit
------------------------------
Enter your choice:
3
Length of india is 5
Length of kerala is 6
-----------MENU-------------
1.Compare
2.Concatenate
3.String Length
4.Exit
------------------------------
Enter your choice:
4

Process finished with exit code 0*/