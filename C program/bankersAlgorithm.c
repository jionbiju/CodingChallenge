#include <stdio.h>

void main(){
    int n,r;
    printf("Enter the no of Proceses:\n");
    scanf("%d",&n);
    printf("Enter the no of Resources:\n");
    scanf("%d",&r);
    int avail[r],allocation[n][r],max[n][r],need[n][r],isFinished[n],work[r],safeSequence[n];
    printf("Enter the Allocation Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<r; j++){
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("Allocation Matrix is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<r; j++){
            printf("%d\t",allocation[i][j]);
        }
        printf("\n");
    }
    printf("Enter the Max Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<r; j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Max Matrix is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<r; j++){
            printf("%d\t",max[i][j]);
        }
        printf("\n");
    }
    printf("Enter the Available Matrix:\n");
    for(int i=0; i<r; i++){
        scanf("%d",&avail[i]);
        work[i]=avail[i];
    }
    printf("Available Matrix is:\n");
    for (int i = 0; i < r; i++){
        printf("%d\t",avail[i]);
    }
    
    for(int i=0; i<n; i++){
        isFinished[i]=0;
    }
    int count=n;
    for(int i=0; i<n; i++){
        for(int j=0; j<r; j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    printf("\nNeed Matrix is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<r; j++){
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    int index=0;
    while(count!=0){
        for(int i=0; i<n; i++){
            if(isFinished[i] == 0){
                int flag=0;
                for(int j=0; j<r; j++){
                    if(need[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safeSequence[index++]=i;
                    count--;
                    isFinished[i]=1;
                    for(int k=0; k<r; k++){
                        work[k]+=allocation[i][k];
                    }
                }
            }
        }
    }
    printf("Safe sequence is:");
    for(int i=0; i<n; i++){
        printf("P%d\t",safeSequence[i]);
    }
}
/*
OUTPUT
Enter the no of Proceses:
5
Enter the no of Resources:
3
Enter the Allocation Matrix:
0
1
0
2
0
0
3
0
2
2
1
1
0
0
2
Allocation Matrix is:
0       1       0
2       0       0
3       0       2
2       1       1
0       0       2
Enter the Max Matrix:
7
5
3
3
2
2
9
0
2
2
2
2
4
3
3
Max Matrix is:
7       5       3
3       2       2
9       0       2
2       2       2
4       3       3
Enter the Available Matrix:
3
3
2
Available Matrix is:
3       3       2
Need Matrix is:
7       4       3
1       2       2
6       0       0
0       1       1
4       3       1
Safe sequence is:P1     P3      P4      P0      P2
*/