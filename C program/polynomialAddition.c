//Polynomial Addition
#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
};

int polyread(struct poly p[]){
    int n;
    printf("Enter number of terms in the polynomial: \n");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter coefficient and power of term %d \n",i+1);
        scanf("%d%d",&p[i].coeff,&p[i].expo);
    }
    return n;
}

int polyadd(struct poly p1[],struct poly p2[],struct poly p3[],int t1,int t2){
    int i=0,j=0,k=0;
    while(i<t1 && j<t2){
        if(p1[i].expo == p2[j].expo){
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        }
        else if(p1[i].expo > p2[j].expo){
            p3[k] = p1[i];
            i++;
            k++;
        }
        else{
            p3[k] = p2[j];
            j++;
            k++;
        }
    }
    while(i < t1){
        p3[k] = p1[i];
        i++;
        k++;
     }
    while(j < t2){
        p3[k] = p2[j];
        j++;
        k++;
     }
     return k;
}

void display(struct poly p[],int t){
    for(int i=0; i<t; i++){
        if(p[i].expo > 0){
        printf("%dx^%d ",p[i].coeff,p[i].expo);
        }
        else{
        printf("%d",p[i].coeff);
        }
        if (i != (t-1)) {
            printf(" + ");
        }
    }
    printf("\n");
    
}

void main(){
    int t1,t2,t3;
    struct poly p1[10],p2[10],p3[10];
    printf("Reading first polynomial\n");
    t1 = polyread(p1);
    printf("Reading second polynomial\n");
    t2 = polyread(p2);
    printf("Polynomial 1 is: ");
    display(p1,t1);
    printf("Polynomial 2 is: ");
    display(p2,t2);
    t3 = polyadd(p1,p2,p3,t1,t2);
    printf("Polynomial sum is: ");
    display(p3,t3);
}

/*
OUTPUT
Reading first polynomial
Enter number of terms in the polynomial:
4
Enter coefficient and power of term 1
5
3
Enter coefficient and power of term 2
2
2
Enter coefficient and power of term 3
3
1
Enter coefficient and power of term 4
2
0
Reading second polynomial
Enter number of terms in the polynomial:
3
Enter coefficient and power of term 1
4
2
Enter coefficient and power of term 2
2
1
Enter coefficient and power of term 3
1
0
Polynomial 1 is: 5x^3 + 2x^2 + 3x^1 + 2
Polynomial 2 is: 4x^2 + 2x^1 + 1
Polynomial sum is: 5x^3 + 6x^2 + 5x^1 + 3
*/