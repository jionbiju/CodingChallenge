/*
Create a structure for an employee with following information:employee id, name and salary. Write 
a program to read the details of ‘n’ employees and display the details 
of employees whose salary is above 10000. Use pointers to structure.
*/
#include <stdio.h>
struct employee{
    int id;
    char name[40];
    int salary;
};
void main(){
    int n;
    printf("Enter number of employee.\n");
    scanf("%d",&n);
    struct employee em[n];
    struct employee *ptr=em;
    for(int i=0; i<n; i++){
        printf("Enter the details of employee %d\n",i+1);
        printf("Employee Id:\n");
        scanf("%d",&ptr->id);
        printf("Employee Name:\n");
        scanf("%s",ptr->name);
        printf("Employee salary:\n");
        scanf("%d",&ptr->salary);
        ptr++;
    }
    printf("Employee with salary above 10000\n");
    ptr=em;
    for(int i=0; i<n; i++){
        if(ptr->salary>10000){
            printf("Employee Id:%d\n",ptr->id);
            printf("Employee Name:%s\n",ptr->name);
            printf("Employee Salary:%d\n",ptr->salary);
        }
        ptr++;
    }
}

/*
Output
Enter number of employee.
3
Enter the details of employee 1
Employee Id:
144
Employee Name:
ab
Employee salary:
9999
Enter the details of employee 2
Employee Id:
747
Employee Name:
cd
Employee salary:
12997
Enter the details of employee 3
Employee Id:
685
Employee Name:
ef
Employee salary:
10001
Employee with salary above 10000
Employee Id:747
Employee Name:cd
Employee Salary:12997
Employee Id:685
Employee Name:ef
Employee Salary:10001
*/