//Read the roll number, name, and total mark of 10 students and display the data.

#include <stdio.h>

struct student
{
    int roll_num,mark;
    char name[50];
   
}st[10];

void main(){
    for(int i=0; i<10; i++){
    printf("Enter the details of the student %d.\n",i+1);
    printf("Enter the name of the student:\n");
    scanf("%s",st[i].name);
    printf("Enter the Roll Number:\n");
    scanf("%d",&st[i].roll_num);
    printf("Enter the Total Mark:\n");
    scanf("%d",&st[i].mark);
    }
    printf("Details of the students are:\n");
    for(int i=0; i<10; i++){
    printf("Name of the student is %s\n",st[i].name);
    printf("Roll Number-%d\n",st[i].roll_num);
    printf("Total Mark-%d\n",st[i].mark);

    }
}