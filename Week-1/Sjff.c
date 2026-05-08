#include <stdio.h>

int main() {
    int n, bt[20], rem_bt[20], wt[20], tat[20], ct[20], rt[20];
    int i, tq, time = 0, done;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
        rt[i] = -1;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    do {
        done = 1;

        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;

                if(rt[i] == -1)
                    rt[i] = time;

                if(rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    ct[i] = time;
                    rem_bt[i] = 0;
                }
            }
        }

    } while(!done);

    for(i = 0; i < n; i++) {
        tat[i] = ct[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
