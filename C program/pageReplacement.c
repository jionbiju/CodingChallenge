//Page Replacement Algorithms - FIFO, LRU, LFU
#include <stdio.h>
int pages, frames;
int rs[100];

//FIFO Page Replacement Algorithm
void fifo() {
    int i, j, count = 0, pf = 0;
    int m[frames];
    
    for (i = 0; i < frames; i++) {
        m[i] = -1;
    }
    
    printf("=== FIFO PAGE REPLACEMENT ===\n");
    printf("Page Reference | Frames\n");
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

//LRU Page Replacement Algorithm
void lru() {
    int i, j, pf = 0;
    int m[frames], time[frames];
    
    for (i = 0; i < frames; i++) {
        m[i] = -1;
        time[i] = 0;
    }
    
    printf("\n=== LRU PAGE REPLACEMENT ===\n");
    printf("Page Reference | Frames\n");
    printf("-----------------------\n");
    
    for (i = 0; i < pages; i++) {
        int found = 0, pos = -1;
        
        for (j = 0; j < frames; j++) {
            if (rs[i] == m[j]) {
                found = 1;
                pos = j;
                break;
            }
        }
        
        if (!found) {   
            int lru_pos = 0;
            for (j = 1; j < frames; j++) {
                if (time[j] < time[lru_pos]) {
                    lru_pos = j;
                }
            }
            m[lru_pos] = rs[i];
            time[lru_pos] = i + 1;
            pf++;
        } else {
            time[pos] = i + 1;
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

//LFU Page Replacement Algorithm
void lfu() {
    int i, j, pf = 0;
    int m[frames], freq[frames];
    
    for (i = 0; i < frames; i++) {
        m[i] = -1;
        freq[i] = 0;
    }
    
    printf("\n=== LFU PAGE REPLACEMENT ===\n");
    printf("Page Reference | Frames\n");
    printf("-----------------------\n");
    
    for (i = 0; i < pages; i++) {
        int found = 0, pos = -1;
        
        for (j = 0; j < frames; j++) {
            if (rs[i] == m[j]) {
                found = 1;
                pos = j;
                break;
            }
        }
        
        if (!found) {
            int lfu_pos = 0;
            for (j = 1; j < frames; j++) {
                if (freq[j] < freq[lfu_pos]) {
                    lfu_pos = j;
                }
            }
            m[lfu_pos] = rs[i];
            freq[lfu_pos] = 1;
            pf++;
        } else {
            freq[pos]++;
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

void main() {
    int i;
    
    printf("PAGE REPLACEMENT ALGORITHMS\n");
    printf("===========================\n");
    
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    
    printf("Enter the reference string:\n");
    for (i = 0; i < pages; i++) {
        scanf("%d", &rs[i]);
    }
    
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    fifo();
    lru();
    lfu();
}
/*
OUTPUT
PAGE REPLACEMENT ALGORITHMS
===========================
Enter the number of pages: 15
Enter the reference string:
3
8
2
3
9
1
6
3
8
9
3
6
2
1
3
Enter the number of frames: 5
=== FIFO PAGE REPLACEMENT ===
Page Reference | Frames
-----------------------
     3      | 3 - - - -
     8      | 3 8 - - -
     2      | 3 8 2 - -
     3      | 3 8 2 - -
     9      | 3 8 2 9 -
     1      | 3 8 2 9 1
     6      | 6 8 2 9 1
     3      | 6 3 2 9 1
     8      | 6 3 8 9 1
     9      | 6 3 8 9 1
     3      | 6 3 8 9 1
     6      | 6 3 8 9 1
     2      | 6 3 8 2 1
     1      | 6 3 8 2 1
     3      | 6 3 8 2 1

Total Page Faults: 9

=== LRU PAGE REPLACEMENT ===
Page Reference | Frames
-----------------------
     3      | 3 - - - -
     8      | 3 8 - - -
     2      | 3 8 2 - -
     3      | 3 8 2 - -
     9      | 3 8 2 9 -
     1      | 3 8 2 9 1
     6      | 3 6 2 9 1
     3      | 3 6 2 9 1 
     8      | 3 6 8 9 1
     9      | 3 6 8 9 1
     3      | 3 6 8 9 1
     6      | 3 6 8 9 1
     2      | 3 6 8 9 2
     1      | 3 6 1 9 2
     3      | 3 6 1 9 2

Total Page Faults: 9

=== LFU PAGE REPLACEMENT ===
Page Reference | Frames
-----------------------
     3      | 3 - - - -
     8      | 3 8 - - -
     2      | 3 8 2 - -
     3      | 3 8 2 - -
     9      | 3 8 2 9 -
     1      | 3 8 2 9 1
     6      | 3 6 2 9 1
     3      | 3 6 2 9 1
     8      | 3 8 2 9 1
     3      | 3 6 2 9 1
     8      | 3 8 2 9 1
     8      | 3 8 2 9 1
     9      | 3 8 2 9 1
     3      | 3 8 2 9 1
     6      | 3 6 2 9 1
     2      | 3 6 2 9 1
     1      | 3 6 2 9 1
     3      | 3 6 2 9 1

Total Page Faults: 8
*/