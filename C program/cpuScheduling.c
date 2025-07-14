#include <stdio.h>

struct process {
    int id;
    int at;    
    int bt;
    int wt;   
    int tt;   
    int ft;   
    int rt;    
    int priority;
    int status;
};

// Function prototypes
void fcfs_scheduling(struct process p[], int n);
void sjf_scheduling(struct process p[], int n);
void round_robin_scheduling(struct process p[], int n);
void priority_scheduling(struct process p[], int n);
void display_results(struct process p[], int n);
void reset_process_data(struct process p[], int n);

int main() {
    int n, choice;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct process p[n];
    

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time of Process P%d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time of Process P%d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].status = -1;
    }
    
    do {
        printf("\n=== CPU Scheduling Algorithms ===\n");
        printf("1. First Come First Serve (FCFS)\n");
        printf("2. Shortest Job First (SJF)\n");
        printf("3. Round Robin (RR)\n");
        printf("4. Priority Scheduling\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                reset_process_data(p, n);
                fcfs_scheduling(p, n);
                break;
            case 2:
                reset_process_data(p, n);
                sjf_scheduling(p, n);
                break;
            case 3:
                reset_process_data(p, n);
                round_robin_scheduling(p, n);
                break;
            case 4:
                reset_process_data(p, n);

                for (int i = 0; i < n; i++) {
                    printf("Enter Priority of Process P%d: ", i + 1);
                    scanf("%d", &p[i].priority);
                }
                priority_scheduling(p, n);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void reset_process_data(struct process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].rt = p[i].bt;
        p[i].status = -1;
        p[i].wt = 0;
        p[i].tt = 0;
        p[i].ft = 0;
    }
}

void fcfs_scheduling(struct process p[], int n) {
    printf("\n=== FCFS Scheduling ===\n");
    

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    

    p[0].wt = 0;
    p[0].tt = p[0].bt;
    p[0].ft = p[0].at + p[0].bt;
    
    int current_time = p[0].ft;
    
    for (int i = 1; i < n; i++) {
        if (current_time < p[i].at) {
            current_time = p[i].at;
        }
        p[i].wt = current_time - p[i].at;
        p[i].tt = p[i].bt + p[i].wt;
        p[i].ft = current_time + p[i].bt;
        current_time = p[i].ft;
    }
    
    display_results(p, n);
}

void sjf_scheduling(struct process p[], int n) {
    printf("\n=== SJF Scheduling ===\n");
    
    int total_tt = 0, total_wt = 0, completed = 0, curr_time = 0;
    
    while (completed < n) {
        int min_bt = 9999, idx = -1;
        

        for (int i = 0; i < n; i++) {
            if (p[i].status == -1 && p[i].at <= curr_time && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                idx = i;
            }
        }
        
        if (idx == -1) {
            curr_time++;
            continue;
        }
        
        p[idx].status = 0;
        p[idx].wt = curr_time - p[idx].at;
        p[idx].tt = p[idx].wt + p[idx].bt;
        p[idx].ft = curr_time + p[idx].bt;
        total_tt += p[idx].tt;
        total_wt += p[idx].wt;
        curr_time += p[idx].bt;
        completed++;
    }
    
    display_results(p, n);
}

void round_robin_scheduling(struct process p[], int n) {
    printf("\n=== Round Robin Scheduling ===\n");
    
    int quantum;
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
    
    int time = 0, completed = 0;
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
    
    display_results(p, n);
}

void priority_scheduling(struct process p[], int n) {
    printf("\n=== Priority Scheduling ===\n");
    
    int total_tt = 0, total_wt = 0, completed = 0, curr_time = 0;
    
    while (completed < n) {
        int min_priority = 9999, idx = -1;
     
        for (int i = 0; i < n; i++) {
            if (p[i].status == -1 && p[i].at <= curr_time && p[i].priority < min_priority) {
                min_priority = p[i].priority;
                idx = i;
            }
        }
        
        if (idx == -1) {
            curr_time++;
            continue;
        }
        
        p[idx].status = 0;
        p[idx].wt = curr_time - p[idx].at;
        p[idx].tt = p[idx].wt + p[idx].bt;
        p[idx].ft = curr_time + p[idx].bt;
        total_tt += p[idx].tt;
        total_wt += p[idx].wt;
        curr_time += p[idx].bt;
        completed++;
    }
    
    display_results(p, n);
}

void display_results(struct process p[], int n) {
    float avg_tt = 0, avg_wt = 0;
    
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-------\t------------\t----------\t------------\t---------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tt);
        avg_tt += p[i].tt;
        avg_wt += p[i].wt;
    }
    
    avg_tt /= n;
    avg_wt /= n;
    
    printf("\nAverage Turnaround Time: %.2f\n", avg_tt);
    printf("Average Waiting Time: %.2f\n", avg_wt);
}

/*
OUTPUT
Enter the number of processes: 4
Enter Arrival Time of Process P1: 0
Enter Burst Time of Process P1: 10
Enter Arrival Time of Process P2: 1
Enter Burst Time of Process P2: 9
Enter Arrival Time of Process P3: 2
Enter Burst Time of Process P3: 12
Enter Arrival Time of Process P4: 3
Enter Burst Time of Process P4: 6

=== CPU Scheduling Algorithms ===
1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)
3. Round Robin (RR)
4. Priority Scheduling
5. Exit
Enter your choice: 1

=== FCFS Scheduling ===

Process Arrival Time    Burst Time      Waiting Time    Turnaround Time
------- ------------    ----------      ------------    ---------------
P1      0               10              0               10
P2      1               9               9               18
P3      2               12              17              29
P4      3               6               28              34

Average Turnaround Time: 22.75
Average Waiting Time: 13.50

=== CPU Scheduling Algorithms ===
1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)
3. Round Robin (RR)
4. Priority Scheduling
5. Exit
Enter your choice: 2

=== SJF Scheduling ===

Process Arrival Time    Burst Time      Waiting Time    Turnaround Time
------- ------------    ----------      ------------    ---------------
P1      0               10              0               10
P2      1               9               15              24
P3      2               12              23              35
P4      3               6               7               13

Average Turnaround Time: 20.50
Average Waiting Time: 11.25

=== CPU Scheduling Algorithms ===
1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)
3. Round Robin (RR)
4. Priority Scheduling
5. Exit
Enter your choice: 3

=== Round Robin Scheduling ===
Enter Time Quantum: 8

Process Arrival Time    Burst Time      Waiting Time    Turnaround Time
------- ------------    ----------      ------------    ---------------
P1      0               10              22              32
P2      1               9               23              32
P3      2               12              23              35
P4      3               6               21              27

Average Turnaround Time: 31.50
Average Waiting Time: 22.25

=== CPU Scheduling Algorithms ===
1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)
3. Round Robin (RR)
4. Priority Scheduling
5. Exit
Enter your choice: 4
Enter Priority of Process P1: 2
Enter Priority of Process P2: 1
Enter Priority of Process P3: 3
Enter Priority of Process P4: 4

=== Priority Scheduling ===

Process Arrival Time    Burst Time      Waiting Time    Turnaround Time
------- ------------    ----------      ------------    ---------------
P1      0               10              0               10
P2      1               9               9               18
P3      2               12              17              29
P4      3               6               28              34

Average Turnaround Time: 22.75
Average Waiting Time: 13.50

=== CPU Scheduling Algorithms ===
1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)
3. Round Robin (RR)
4. Priority Scheduling
5. Exit
Enter your choice: 5
Exiting...
*/