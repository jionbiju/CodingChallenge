//SJF CPU Scheduling
#include <stdio.h>
struct fcfs{
    int bt;
    int id;
    int wt;
    int tt;
    int at;
    int status;
};

void main(){
    int n,flag;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    struct fcfs p[n],temp;
    for(int i=0; i<n; i++){
        p[i].id=i+1;
        printf("Enter Arrival Time of Process %d\n",i+1);
        scanf("%d",&p[i].at);
        printf("Enter Burst Time of Process %d\n",i+1);
        scanf("%d",&p[i].bt);
        p[i].status=-1;
    }
    int total_tt=0,total_wt=0,completed=0,curr_time=0;
    while(completed<n){
        int min_bt=9999,idx=-1;
        for(int i=0; i<n; i++){
            if(p[i].status==-1 && p[i].at<=curr_time && p[i].bt<min_bt){
                min_bt=p[i].bt;
                idx=i;
            }
        }
        if(idx==-1){
            curr_time++;
            continue;
        }
        p[idx].status=0;
        p[idx].wt=curr_time-p[idx].at;
        p[idx].tt = p[idx].wt +p[idx].bt;
        total_tt+=p[idx].tt;
        total_wt+=p[idx].wt;
        curr_time+=p[idx].bt;
        completed++;
    }
    printf("Process No\tArrival time\tBurst Time\tWaiting time\tTurnAroundtime\n");
    for (int i = 0; i < n; i++) {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tt);
    }
    
}
/*
OUTPUT
Enter the number of process
5
Enter Arrival Time of Process 1
44
Enter Burst Time of Process 1
55
Enter Arrival Time of Process 2
27
Enter Burst Time of Process 2
26
Enter Arrival Time of Process 3
8552
Enter Burst Time of Process 3
545
Enter Arrival Time of Process 4
21
Enter Burst Time of Process 4
25
Enter Arrival Time of Process 5
25
Enter Burst Time of Process 5
25
Process No      Arrival time    Burst Time      Waiting time    TurnAroundtime
        1               44              55              53              108
        2               27              26              44              70
        3               8552            545             0               545
        4               21              25              0               25
        5               25              25              21              46
*/