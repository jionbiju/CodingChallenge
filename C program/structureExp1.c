/*Write a C program to declare a structure Student to store the details (roll_number, name,
mark_for_C) of a student. Display the average mark obtained by the students in the class for the
subject Programming in C (using the field mark_for_C). Use an array of structures to store the
required data.*/
#include <stdio.h>
struct student
{
    char name[50];
    int roll_number;
    int mark_for_C;
};

void main()
{
    int n,sum=0;
    float avg;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    struct student st[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter details for student %d\n",i+1);
        printf("Name:\n");
        scanf("%s",st[i].name);
        printf("Roll Number:\n");
        scanf("%d",&st[i].roll_number);
        printf("Mark for C:\n");
        scanf("%d",&st[i].mark_for_C);
        sum=sum+st[i].mark_for_C;
    }
    avg=sum/n;
    printf("Averge mark of C: %f",avg);
}
/*
Output
Enter the number of students:
2
Enter details for student 1
Name:
messi
Roll Number:
2
Mark for C:
33
Enter details for student 2
Name:
ronaldo
Roll Number:
1
Mark for C:
49
Averge mark of C: 41.000000
*/