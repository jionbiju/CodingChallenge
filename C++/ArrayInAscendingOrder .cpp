//
// Created by Jion Biju on 12/1/2022.
//Sorting values in an array in ascending order.
#include <iostream>

int main()
{
    int num,temp;
    std::cout<<"Enter the array limit: ";
    std::cin>>num;
    int array[num];
    std::cout<<"Enter the values: "<<std::endl;
    for (int i=0;i<num;i++) {
        std::cin>>array[i];
    }
    std::cout<<"The values are:"<<std::endl;
    for (int i=0;i<num;i++) {
        std::cout<<array[i]<<std::endl;
    }
    for (int i=0;i<num-1;i++) {
        for (int j=i+1;j<num;j++) {
            if (array[i]>array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }

    }
    std::cout<<"Values sorted in ascending order:"<< std::endl;
    for (int i=0;i<num;i++) {
        std::cout<<array[i]<<std::endl;
    }
    return 0;
}
/*===========OUTPUT============
Enter the array limit:
10
Enter the values:
10
9
8
7
6
5
4
2
3
1
The values are:
10
9
8
7
6
5
4
2
3
1
Values sorted in ascending order:
1
2
3
4
5
6
7
8
9
10*/