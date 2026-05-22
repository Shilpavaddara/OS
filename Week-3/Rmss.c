#include <stdio.h>

struct Process {
    int pid;
    int burst;
    int deadline;
    int remaining;
    int completion;
};

int main() {

    int n, time, limit = 20;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {

        printf("\nProcess %d\n", i + 1);

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Enter Deadline: ");
        scanf("%d", &p[i].deadline);

        p[i].pid = i + 1;
        p[i].remaining = p[i].burst;
        p[i].completion = 0;
    }

    printf("\nGANTT CHART\n");
    printf("--------------------------------------------------\n");

    for(time = 0; time < limit; time++) {

        int selected = -1;
        int earliest = 9999;

        for(int i = 0; i < n; i++) {

            if(p[i].remaining > 0 && p[i].deadline < earliest) {
                earliest = p[i].deadline;
                selected = i;
            }
        }

        if(selected != -1) {

            printf("| P%d ", p[selected].pid);

            p[selected].remaining--;

            if(p[selected].remaining == 0)
                p[selected].completion = time + 1;

        } else {
            printf("| ID ");
        }
    }

    printf("|\n");
    printf("--------------------------------------------------\n");

    for(time = 0; time <= limit; time++) {
        printf("%-5d", time);
    }

    printf("\n\nPID\tBT\tDEADLINE\tCT\tSTATUS\n");

    for(int i = 0; i < n; i++) {

        printf("P%d\t%d\t%d\t\t%d\t",
               p[i].pid,
               p[i].burst,
               p[i].deadline,
               p[i].completion);

        if(p[i].completion <= p[i].deadline)
            printf("Met\n");
        else
            printf("Missed\n");
    }

    return 0;
}
