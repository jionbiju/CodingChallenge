//FIFO page replacement algorithm
#include <stdio.h>

void main() {
    int pages, frames, i, j, count = 0, pf = 0;
    
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    
    int rs[pages]; 
    printf("Enter the reference string:\n");
    for (i = 0; i < pages; i++) {
        scanf("%d", &rs[i]);
    }
    
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    int m[frames];
    for (i = 0; i < frames; i++) {
        m[i] = -1;
    }
    
    printf("\nPage Reference | Frames\n");
    printf("-----------------------\n");

    for (i = 0; i < pages; i++) {
        int found = 0;
        

        for (j = 0; j < frames; j++) {
            if (rs[i] == m[j]) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            m[count] = rs[i]; 
            count = (count + 1) % frames; 
            pf++;
        }
        

        printf("     %d      | ", rs[i]);
        for (j = 0; j < frames; j++) {
            if (m[j] != -1)
                printf("%d ", m[j]);
            else
                printf("- "); 
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pf);
}
/*
OUTPUT
Enter the number of pages: 8
Enter the reference string:
3
1
2
1
6
5
1
3
Enter the number of frames: 3

Page Reference | Frames
-----------------------
     3      | 3 - -
     1      | 3 1 -
     2      | 3 1 2
     1      | 3 1 2
     6      | 6 1 2
     5      | 6 5 2
     1      | 6 5 1
     3      | 3 5 1

Total Page Faults: 7
*/