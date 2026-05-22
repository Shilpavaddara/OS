#include <stdio.h>
#include <string.h>

struct Process
{
    int pid, at, bt;
    int ct, tat, wt, rt;
    char type[10];
};

void fcfs(struct Process p[], int n, int *time)
{
    for (int i = 0; i < n; i++)
    {
        if (*time < p[i].at)
            *time = p[i].at;

        p[i].rt = *time - p[i].at;
        p[i].wt = *time - p[i].at;

        *time += p[i].bt;

        p[i].ct = *time;
        p[i].tat = p[i].ct - p[i].at;
    }

    printf("\nPID\tType\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].type,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt,
               p[i].rt);
    }
}

int main()
{
    struct Process systemQ[] = {
        {1, 0, 5, 0, 0, 0, 0, "System"},
        {3, 2, 8, 0, 0, 0, 0, "System"}
    };

    struct Process userQ[] = {
        {2, 1, 3, 0, 0, 0, 0, "User"},
        {4, 3, 6, 0, 0, 0, 0, "User"}
    };

    int sysCount = 2;
    int userCount = 2;

    int time = 0;

    printf("\n===== SYSTEM PROCESS QUEUE =====\n");
    fcfs(systemQ, sysCount, &time);

    printf("\n===== USER PROCESS QUEUE =====\n");
    fcfs(userQ, userCount, &time);

    return 0;
}
