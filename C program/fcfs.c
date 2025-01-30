//Witing time and turnaround time of each process using FCFS
#include <stdio.h>
struct fcfs{
    int bt;
    int id;
    int wt;
    int tt;
    int at;
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
    }
    for(int i=0; i<n-1; i++){
        flag=0;
        for(int j=0; j<n-i-1; j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                flag=1;
            }
        }
        if(flag == 0){
            break;
        }
    }
    p[0].wt=0;
    p[0].tt = p[0].bt;
    int current_time=p[0].bt+p[0].at;
    for(int i=1; i<n; i++){
        if(current_time < p[i].at){
            current_time=p[i].at;
        }
        p[i].wt=current_time-p[i].at;
        p[i].tt=p[i].bt+p[i].wt;
        current_time=current_time+p[i].bt;
    }
    printf("Process No\tArrival time\tBurst Time\tWaiting time\tTurnAroundtime\n");
    for (int i = 0; i < n; i++) {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tt);
    }
}
/*
OUPUT
Enter the number of process
5
Enter Arrival Time of Process 1
2
Enter Burst Time of Process 1
6
Enter Arrival Time of Process 2
5
Enter Burst Time of Process 2
2
Enter Arrival Time of Process 3
1
Enter Burst Time of Process 3
8
Enter Arrival Time of Process 4
0
Enter Burst Time of Process 4
3
Enter Arrival Time of Process 5
4
Enter Burst Time of Process 5
4
Process No      Arrival time    Burst Time      Waiting time    TurnAroundtime
        4               0               3               0               3
        3               1               8               3               11
        1               2               6               11              17
        5               4               4               17              21
        2               5               2               21              23
*/