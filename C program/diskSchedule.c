//Disk Scheduling using FCFS,SCAN,CSCAN algorithms
#include <stdio.h>
#include <stdlib.h>

void display(int seq[], int count, int total_movement) {
    printf("\nTraversed Order: ");
    for (int i = 0; i < count; i++)
        printf("%d ", seq[i]);
    printf("\nTotal Head Movement: %d\n", total_movement);
}

void fcfs(int n,int req[],int currhead){
    int total_movement=0,seq[50],index=0;
    seq[index++]=currhead;
    for(int i=0; i<n; i++){
        seq[index++]=req[i];
        total_movement+=abs(currhead-req[i]);
        currhead=req[i];
    }
    display(seq,index,total_movement);
}

void scan(int n, int req[], int currhead, int disk_size) {
    int total_movement = 0, seq[50], index = 0;
    
    // Sort requests
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
    seq[index++] = currhead;
    int i;
    // Find the first request greater than or equal to the current head
    for (i = 0; i < n; i++) {
        if (req[i] >= currhead) break;
    }

    // Move right (servicing requests in ascending order)
    for (int j = i; j < n; j++) {
        seq[index++] = req[j];
        total_movement += abs(currhead - req[j]);
        currhead = req[j];
    }

    // Move to the end of disk
    if (currhead != disk_size - 1) { 
        seq[index++] = disk_size - 1;
        total_movement += abs(currhead - (disk_size - 1));
        currhead = disk_size - 1;
    }

    // Move left (servicing remaining requests)
    for (int j = i - 1; j >= 0; j--) {
        seq[index++] = req[j];
        total_movement += abs(currhead - req[j]);
        currhead = req[j];
    }

    display(seq, index, total_movement);
}

void cscan(int n, int req[], int currhead, int disk_size) {
    int total_movement = 0, seq[50], index = 0;

    // Sort requests
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Add initial head position to sequence (optional)
    seq[index++] = currhead;  

    int i;
    // Find the first request greater than or equal to the current head
    for (i = 0; i < n; i++) {
        if (req[i] >= currhead) break;
    }

    // Move right (servicing requests in ascending order)
    for (int j = i; j < n; j++) {
        seq[index++] = req[j];
        total_movement += abs(currhead - req[j]);
        currhead = req[j];
    }

    // Move to the end of disk
    if (currhead != disk_size - 1) {
        seq[index++] = disk_size - 1;
        total_movement += abs(currhead - (disk_size - 1));
        currhead = disk_size - 1;
    }

    // Jump to 0 (reset head position)
    seq[index++] = 0;
    total_movement += (disk_size - 1); 
    currhead = 0;  // Reset head to 0 before serving remaining requests

    // Serve remaining requests from the beginning
    for (int j = 0; j < i; j++) {
        seq[index++] = req[j];
        total_movement += abs(currhead - req[j]);
        currhead = req[j];
    }

    display(seq, index, total_movement);
}


void main(){
    int n,currhead,req[50],ch,disk_size;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the current head position\n");
    scanf("%d",&currhead);
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);
    printf("Enter the Requests\n");
    for(int i=0; i<n; i++){
        scanf("%d",&req[i]);
        
    }
    do{
    printf("Enter your choice:\n");
    printf("1-FCFS Disk Scheduling\n");
    printf("2-SCAN Disk Scheduling\n");
    printf("3-CSCAN Disk Scheduling\n");
    printf("4-Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:fcfs(n,req,currhead);
                break;
        case 2:scan(n,req,currhead,disk_size);
                break;
        case 3:cscan(n,req,currhead,disk_size);
                break;
        case 4:printf("Existing...");
                return;
        default:printf("Enter a valid choice\n");
                break;
    }
  }while(ch!=4);

}
/*
Enter the number of Requests
7
Enter the current head position
50
Enter the disk size: 200
Enter the Requests
82
170
43
140
24
16
190
Enter your choice:
1-FCFS Disk Scheduling
2-SCAN Disk Scheduling
3-CSCAN Disk Scheduling
1

Traversed Order: 50 82 170 43 140 24 16
Total Head Movement: 642
Enter your choice:
1-FCFS Disk Scheduling
2-SCAN Disk Scheduling
3-CSCAN Disk Scheduling
2

Traversed Order: 50 82 140 170 190 199 43 24 16
Total Head Movement: 332
Enter your choice:
1-FCFS Disk Scheduling
2-SCAN Disk Scheduling
3-CSCAN Disk Scheduling
3

Traversed Order: 50 82 140 170 190 199 0 16 24 43
Total Head Movement: 391
Enter your choice:
1-FCFS Disk Scheduling
2-SCAN Disk Scheduling
3-CSCAN Disk Scheduling
4
Existing...
*/