//
// Created by Jion Biju on 11/4/2022.
//Week problem using switch statement.
#include <iostream>

int main()
{
    int day;
    std::cout<<"Enter a number between 1 & 7: ";
    std::cin>>day;
    switch (day) {
        case 1:std::cout<<"Sunday";
            break;
        case 2:std::cout<<"Monday";
            break;
        case 3:std::cout<<"Tuesday";
            break;
        case 4:std::cout<<"Wednsday";
            break;
        case 5:std::cout<<"Thursday";
            break;
        case 6:std::cout<<"Friday";
            break;
        case 7:std::cout<<"Saturday";
            break;
        default:std::cout<<"Invaild input";
    }
    return 0;
}

//======================OUTPUT=============================
//Enter a number between 1 & 7:1
//Sunday