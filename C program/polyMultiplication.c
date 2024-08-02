//Polynomial Multiplication.
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
    printf("\b");
    printf("\n");
    
}

int polyproduct(struct poly p1[],struct poly p2[],struct poly p3[],int t1,int t2){
    int i,j,k=0,c,e;
    for(i=0; i<t1; i++){
        for(j=0; j<t2; j++){
            c = p1[i].coeff * p2[j].coeff;
            e = p1[i].expo + p2[j].expo;
            k= attach(p3,c,e,k);
        }
    }
    return k;
}

int attach(struct poly p3[], int c, int e, int k) {
    for (int i = 0; i < k; i++) {
        if (p3[i].expo == e) {
            p3[i].coeff += c;
            return k;
        }
    }
    p3[k].coeff = c;
    p3[k].expo = e;
    return k + 1;
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
    t3 = polyproduct(p1,p2,p3,t1,t2);
    printf("Polynomial product is: ");
    display(p3,t3);
}

/*
OUTPUT
Reading first polynomial
Enter number of terms in the polynomial:
3
Enter coefficient and power of term 1
2
2
Enter coefficient and power of term 2
3
1
Enter coefficient and power of term 3
1
0
Reading second polynomial
Enter number of terms in the polynomial:
2
Enter coefficient and power of term 1
2
1
Enter coefficient and power of term 2
1
0
Polynomial 1 is: 2x^2 + 3x^1 + 1
Polynomial 2 is: 2x^1 + 1
Polynomial product is: 4x^3 + 8x^2 + 5x^1 + 1
*/