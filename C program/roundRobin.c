#include <stdio.h>

struct process {
    int id, at, bt, wt, tt, ft, rt; 
};

int main() {
    int n, quantum, time = 0, completed = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i;
        printf("Enter Arrival Time of Process P%d: ", i);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time of Process P%d: ", i);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt; 
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    
   
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int queue[2 * n], front = 0, rear = 0, visited[n]; 
    for (int i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = 0; 
    visited[0] = 1;
    
    while (completed < n) {
        int idx = queue[front]; 
        front = (front + 1) % (2 * n);

        if (p[idx].rt > 0) {
            if (time < p[idx].at) {
                time = p[idx].at; 
            }

            if (p[idx].rt > quantum) {
                time += quantum;
                p[idx].rt -= quantum;
            } else {
                time += p[idx].rt;
                p[idx].ft = time; 
                p[idx].tt = p[idx].ft - p[idx].at; 
                p[idx].wt = p[idx].tt - p[idx].bt;
                p[idx].rt = 0;
                completed++;
            }

 
            for (int i = 0; i < n; i++) {
                if (!visited[i] && p[i].at <= time && p[i].rt > 0) {
                    queue[rear] = i;
                    rear = (rear + 1) % (2 * n);
                    visited[i] = 1;
                }
            }

      
            if (p[idx].rt > 0) {
                queue[rear] = idx;
                rear = (rear + 1) % (2 * n);
            }
        }

        if (front == rear) {
            for (int i = 0; i < n; i++) {
                if (p[i].rt > 0) {
                    queue[rear] = i;
                    rear = (rear + 1) % (2 * n);
                    time = p[i].at; 
                    break;
                }
            }
        }
    }


    float avg_tt = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tt += p[i].tt;
        avg_wt += p[i].wt;
    }
    avg_tt /= n;
    avg_wt /= n;

  
    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].tt, p[i].wt);
    }
    
    printf("\nAverage Turnaround Time: %.2f\n", avg_tt);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
/*
OUTPUT
Enter the number of processes: 4
Enter Arrival Time of Process P0: 0
Enter Burst Time of Process P0: 10
Enter Arrival Time of Process P1: 1
Enter Burst Time of Process P1: 9
Enter Arrival Time of Process P2: 2
Enter Burst Time of Process P2: 12
Enter Arrival Time of Process P3: 3
Enter Burst Time of Process P3: 6
Enter Time Quantum: 8

Process Arrival Time    Burst Time      Turnaround Time Waiting Time
P0      0               10              32              22
P1      1               9               32              23
P2      2               12              35              23
P3      3               6               27              21

Average Turnaround Time: 31.50
Average Waiting Time: 22.25
*/