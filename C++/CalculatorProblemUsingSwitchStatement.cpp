//
// Created by Jion Biju on 11/4/2022.
//
#include <iostream>

int main()
{
    int ch,a,b, answer=0;
    while (1){
        std::cout<<"\n--------------MENU------------------";
        std::cout << "\n1.Addition\n2.Substraction\n3.Multiplication\n4.Division\n5.Exit";
        std::cout << "\nEnter your choice:";
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cout << "Enter a numbers:";
                std::cin >> a;
                std::cout << "Enter another number:";
                std::cin >> b;
                answer = a + b;
                std::cout << "Sum of " << a << "+" << b << "=" << answer;
                break;
            case 2:
                std::cout << "Enter a numbers:";
                std::cin >> a;
                std::cout << "Enter another number:";
                std::cin >> b;
                answer = a - b;
                std::cout << "Result=" << a << "-" << b << "=" << answer;
                break;
            case 3:
                std::cout << "Enter a numbers:";
                std::cin >> a;
                std::cout << "Enter another number:";
                std::cin >> b;
                answer = a * b;
                std::cout << "Result=" << a << "*" << b << "=" << answer;
                break;
            case 4:
                std::cout << "Enter a numbers:";
                std::cin >> a;
                std::cout << "Enter another number:";
                std::cin >> b;
                if (b > a) {
                    std::cout << "Wrong input\n";
                } else {
                    answer = a / b;
                    std::cout << "Result=" << a << "/" << b << "=" << answer;
                }
                break;
            case 5:
                exit(0);
            default:
                std::cout << "Wrong Input";
        }
    }
    return 0;
}

