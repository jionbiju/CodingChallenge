#include <stdio.h>

void main() {
    int n, r;
    printf("Enter the no of Processes:\n");
    scanf("%d", &n);
    printf("Enter the no of Resources:\n");
    scanf("%d", &r);
    
    int avail[r], allocation[n][r], max[n][r], need[n][r], isFinished[n], work[r], safeSequence[n];
    
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    
    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("Enter the Available Resources:\n");
    for (int i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }
    
    for (int i = 0; i < n; i++) {
        isFinished[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    
    printf("\nNeed Matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
    
    int count = n, index = 0, found;
    while (count > 0) {
        found = 0;
        for (int i = 0; i < n; i++) {
            if (isFinished[i] == 0) {
                int flag = 0;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safeSequence[index++] = i;
                    count--;
                    isFinished[i] = 1;
                    for (int k = 0; k < r; k++) {
                        work[k] += allocation[i][k];
                    }
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("\nSystem is not in a safe state!\n");
            return;
        }
    }
    
    printf("\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
}

/*
OUTPUT-1
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

OUTPUT-2
Enter the no of Processes:
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
3
3
2
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
Enter the Available Resources:
0
0
2
Need Matrix is:
7       4       3
1       2       2
6       0       0
0       1       1
1       0       1

System is not in a safe state!
*/