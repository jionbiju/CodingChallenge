//Read emp id, emp name, and salary of n employees and display in the
// ascending order of salary using function [read, display, sort].
#include <stdio.h>
struct employee{
    int id;
    char name[50];
    float salary;
};
void read(struct employee em[],int n){
    int i;
    for(i=0; i<n; i++){
    printf("Enter the details of employee %d\n",i+1);
    printf("Enter the name:\n");
    scanf("%s",em[i].name);
    printf("Enter the employee id:\n");
    scanf("%d",&em[i].id);
    printf("Enter your salary:\n");
    scanf("%f",&em[i].salary);
    }
}
void sort(struct employee em[],int n){
    int i,j;
    struct employee temp;
    for(i=0; i<n; i++ ){
        for(j=0; j<n-1-i; j++){
            if(em[i].salary>em[i+1].salary){
                temp=em[i];
                em[i]=em[i+1];
                em[i+1]=temp;
            }
        }
    }
}

void display(struct employee em[],int n){
    int i;
    printf("\nEmployee details in ascending order of salary:\n");
    for(i=0; i<n; i++){
        printf("Name-%s\nID-%d\nSalary-%f\n",em[i].name,em[i].id,em[i].salary);
    }
}

void main(){
    int n;
    printf("Enter the number of employees:\n");
    scanf("%d",&n);
    struct employee em[n];
    read(em,n);
    sort(em,n);
    display(em,n);
}