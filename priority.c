#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of processes:\n");
    scanf("%d", &n);
    char pid[n][10];
    int at[n], bt[n], pr[n];
    int ct[n], wt[n], tat[n];
    int completed[n];
    for(int i = 0; i < n; i++)
        completed[i] = 0;
    printf("Enter PID AT BT PR for each process:\n");
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d %d", pid[i], &at[i], &bt[i], &pr[i]);
    }
    int time = 0, done = 0;
    while(done < n) {
        int idx = -1;
        int max_pr = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0) {
                if(pr[i] > max_pr) {
                    max_pr = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed[idx] = 1;
            done++;
        } 
        else {
            time++;
        }
    }
    float total_wt = 0, total_tat = 0;
    printf("\nWaiting Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], wt[i]);
        total_wt += wt[i];
    }
    printf("\nTurnaround Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], tat[i]);
        total_tat += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wt/n);
    printf("Average Turnaround Time: %.2f\n", total_tat/n);
    return 0;
}
