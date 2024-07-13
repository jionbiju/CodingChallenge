//Read the roll number, name, and total mark of one student and display the data.
#include <stdio.h>

struct student
{
    int roll_num,mark;
    char name[50];
   
}st;
void main(){
    printf("Enter the name of the student:\n");
    scanf("%s",st.name);
    printf("Enter the Roll Number:\n");
    scanf("%d",&st.roll_num);
    printf("Enter the Total Mark:\n");
    scanf("%d",&st.mark);
    printf("Name of the student is %s\n",st.name);
    printf("Roll Number-%d\n",st.roll_num);
    printf("Total Mark-%d\n",st.mark);
}

//OUTPUT
/*
Enter the name of the student:
sergio
Enter the Roll Number:
32
Enter the Total Mark:
45
Name of the student is sergio
Roll Number-32
Total Mark-45
*/