//Read roll number, name, and total mark of n students and display in ascending order of total mark.

#include <stdio.h>

struct student
{
    int roll_num,mark;
    char name[50];
   
};

void main(){
    int i,j,n;
    printf("Enter the number of students;\n");
    scanf("%d",&n);
    struct student st[n],temp;
    for(int i=0; i<n; i++){
    printf("Enter the details of the student %d.\n",i+1);
    printf("Enter the name of the student:\n");
    scanf("%s",st[i].name);
    printf("Enter the Roll Number:\n");
    scanf("%d",&st[i].roll_num);
    printf("Enter the Total Mark:\n");
    scanf("%d",&st[i].mark);
    }
    for(i=0; i<n; i++ ){
        for(j=0; j<n-1-i; j++){
            if(st[i].mark>st[i+1].mark){
                temp=st[i];
                st[i]=st[i+1];
                st[i+1]=temp;
            }
        }
    }

    printf("Details of the students are:\n");
    for(int i=0; i<n; i++){
    printf("Name of the student is %s\n",st[i].name);
    printf("Roll Number-%d\n",st[i].roll_num);
    printf("Total Mark-%d\n",st[i].mark);

    }
}