#include <stdio.h>

void first_fit(int block[], int nb, int process[], int np) {
    int block_size[np], internal_fragmentation[np], block_no[np], block_status[nb];

    for (int i = 0; i < np; i++) {
        block_size[i] = 0;
        block_no[i] = -1;
        internal_fragmentation[i] = -1;
    }

    for (int i = 0; i < nb; i++) {
        block_status[i] = -1;
    }

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (block_status[j] == -1 && block[j] >= process[i]) {
                block_no[i] = j;
                block_status[j] = 1;
                internal_fragmentation[i] = block[j] - process[i];
                block_size[i] = block[j];
                break;
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\tBlock Size\tInternal Fragmentation\n");
    for (int i = 0; i < np; i++) {
        if (block_no[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, process[i], block_no[i] + 1, block_size[i], internal_fragmentation[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t-\t\t-\n", i + 1, process[i]);
    }
}

void best_fit(int block[], int nb, int process[], int np) {
    int block_size[np], internal_fragmentation[np], block_no[np], block_status[nb];

    for (int i = 0; i < np; i++) {
        block_size[i] = 0;
        block_no[i] = -1;
        internal_fragmentation[i] = -1;
    }

    for (int i = 0; i < nb; i++) {
        block_status[i] = -1;
    }

    for (int i = 0; i < np; i++) {
        int best_idx = -1;
        for (int j = 0; j < nb; j++) {
            if (block_status[j] == -1 && block[j] >= process[i]) {
                if (best_idx == -1 || block[j] < block[best_idx]) {
                    best_idx = j;
                }
            }
        }

        if (best_idx != -1) {
            block_no[i] = best_idx;
            block_status[best_idx] = 1;
            internal_fragmentation[i] = block[best_idx] - process[i];
            block_size[i] = block[best_idx];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\tBlock Size\tInternal Fragmentation\n");
    for (int i = 0; i < np; i++) {
        if (block_no[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, process[i], block_no[i] + 1, block_size[i], internal_fragmentation[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t-\t\t-\n", i + 1, process[i]);
    }
}

void worst_fit(int block[], int nb, int process[], int np) {
    int block_size[np], internal_fragmentation[np], block_no[np], block_status[nb];

    for (int i = 0; i < np; i++) {
        block_size[i] = 0;
        block_no[i] = -1;
        internal_fragmentation[i] = -1;
    }

    for (int i = 0; i < nb; i++) {
        block_status[i] = -1;
    }

    for (int i = 0; i < np; i++) {
        int worst_idx = -1;
        for (int j = 0; j < nb; j++) {
            if (block_status[j] == -1 && block[j] >= process[i]) {
                if (worst_idx == -1 || block[j] > block[worst_idx]) {
                    worst_idx = j;
                }
            }
        }

        if (worst_idx != -1) {
            block_no[i] = worst_idx;
            block_status[worst_idx] = 1;
            internal_fragmentation[i] = block[worst_idx] - process[i];
            block_size[i] = block[worst_idx];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\tBlock Size\tInternal Fragmentation\n");
    for (int i = 0; i < np; i++) {
        if (block_no[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, process[i], block_no[i] + 1, block_size[i], internal_fragmentation[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t-\t\t-\n", i + 1, process[i]);
    }
}

int main() {
    int ch, nb, np;
    
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    
    int block[nb], process[np];

    for (int i = 0; i < nb; i++) {
        printf("Enter the size of block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    for (int i = 0; i < np; i++) {
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    do {
        printf("\nEnter your choice:\n");
        printf("1 - First Fit\n");
        printf("2 - Best Fit\n");
        printf("3 - Worst Fit\n");
        printf("4 - Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                first_fit(block, nb, process, np);
                break;
            case 2:
                best_fit(block, nb, process, np);
                break;
            case 3:
                worst_fit(block, nb, process, np);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (ch != 4);

    return 0;
}
/*
OUTPUT
>>
Enter the number of blocks: 6
Enter the number of processes: 5
Enter the size of block 1: 300
Enter the size of block 2: 600
Enter the size of block 3: 350
Enter the size of block 4: 200
Enter the size of block 5: 750
Enter the size of block 6: 125
Enter the size of process 1: 115
Enter the size of process 2: 500
Enter the size of process 3: 358
Enter the size of process 4: 200
Enter the size of process 5: 375

Enter your choice:
1 - First Fit
2 - Best Fit
3 - Worst Fit
4 - Exit
1

Process No      Process Size    Block No        Block Size      Internal Fragmentation
1               115             1               300             185
2               500             2               600             100
3               358             5               750             392
4               200             3               350             150
5               375             Not Allocated   -               -

Enter your choice:
1 - First Fit
2 - Best Fit
3 - Worst Fit
4 - Exit
2

Process No      Process Size    Block No        Block Size      Internal Fragmentation
1               115             6               125             10
2               500             2               600             100
3               358             5               750             392
4               200             4               200             0
5               375             Not Allocated   -               -

Enter your choice:
1 - First Fit
2 - Best Fit
3 - Worst Fit
4 - Exit
3

Process No      Process Size    Block No        Block Size      Internal Fragmentation
1               115             5               750             635
2               500             2               600             100
3               358             Not Allocated   -               -
4               200             3               350             150
5               375             Not Allocated   -               -

Enter your choice:
1 - First Fit
2 - Best Fit
3 - Worst Fit
4 - Exit
4
Exiting program...
*/