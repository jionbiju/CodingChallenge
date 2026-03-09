#include <stdio.h>
#define INF 999
void main(){
    int n;
    int cost[20][20],dist[20][20];
    printf("Enter number of nodes:\n");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&cost[i][j]);
            dist[i][j] = cost[i][j];
        }
    }
    for(int k=0; k<n-1; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int v=0; v<n; v++){
                    if(dist[i][v] != INF && cost[v][j] != INF && dist[i][j] > dist[i][v] + cost[v][j]){
                        dist[i][j] = dist[i][v] + cost[v][j];
                    }
                }
            }
        }
    }
    printf("Distance Vector Routing Table:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d  ",dist[i][j]);
        }
        printf("\n");
    }
}
/*
OUTPUT
Enter number of nodes:
4
Enter cost matrix:
0 3 2 5
3 0 8 4
2 8 0 1
5 4 1 0
Distance Vector Routing Table:
0  3  2  3  
3  0  5  4
2  5  0  1
3  4  1  0
*/