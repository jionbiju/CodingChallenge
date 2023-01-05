//
// Created by Jion Biju on 1/5/2023.
/* A:Creating an array n integer element
 * B:Display of an array element.
 * C:Insert an element at a given valid position.
 * D:Delete an element at a given valid position.
 * E:Exit*/
#include <iostream>
int arr[10];
int n,pos,value;
void create();
void display();
void insert();
void del();

int main()
{
    int choice=1;
    while (choice) {
        std::cout << "\n----------Menu----------\n";
        std::cout << "1.CREATE\n";
        std::cout << "2.DISPLAY\n";//display all the elements of the array.
        std::cout << "3.INSERT\n";
        std::cout << "4.DELETE\n";
        std::cout << "5.EXIT\n";
        std::cout << "---------------------------\n";
        std::cout << "Enter your choice:\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                del();
                break;
            case 5:
                exit(0);
            default:
                std::cout << "Invalid choice.";
                break;
        }
    }
    return 0;
}
void create(){
    std::cout<<"Enter the size of the array:";
    std::cin>>n;
    std::cout<<"Enter the elements for the array:"<<std::endl;
    for (int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
}

void display(){
    std::cout<<"\nThe array elements are:\n";
    for (int i=0;i<n;i++) {
        std::cout<<arr[i]<<std::endl;
    }
}

void insert(){
    std::cout<<"\nEnter the position for the element:";
    std::cin>>pos;
    std::cout<<"\nEnter the element to be inserted:";
    std::cin>>value;
    for (int i=n-1;i>=pos;i--) {
        arr[i+1]=arr[i];
    }
    arr[pos]=value;
    n=n+1;
    std::cout<<value<<" is inserted in the position "<<pos;
}

void del(){
    std::cout<<"Enter the position of the element to be deleted:";
    std::cin>>pos;
    value=arr[pos];
    for (int i=pos;i<n-1;i++) {
        arr[i]=arr[i+1];
    }
    n=n-1;
    std::cout<<"\nThe deleted element is "<<value;

}

/*=================OUTPUT=========
----------Menu----------
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.EXIT
---------------------------
Enter your choice:
1
Enter the size of the array:4
Enter the elements for the array:
12
4
9
33

----------Menu----------
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.EXIT
---------------------------
Enter your choice:
2

The array elements are:
12
4
9
33

----------Menu----------
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.EXIT
---------------------------
Enter your choice:
3

Enter the position for the element:2

Enter the element to be inserted:17
17 is inserted in the position 2
----------Menu----------
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.EXIT
---------------------------
Enter your choice:
2

The array elements are:
12
4
17
9
33

----------Menu----------
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.EXIT
---------------------------
Enter your choice:
4
Enter the position of the element to be deleted:3

The deleted element is 9
----------Menu----------
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.EXIT
---------------------------
Enter your choice:
2

The array elements are:
12
4
17
33

----------Menu----------
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.EXIT
---------------------------
Enter your choice:
5

Process finished with exit code 0 */