#include <stdio.h>

struct Process {
    int pid;
    int share;
};

int main() {

    int n, total = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {

        p[i].pid = i + 1;

        printf("Enter CPU share for P%d: ", i + 1);
        scanf("%d", &p[i].share);

        total += p[i].share;
    }

    printf("\nProcess\tCPU Share(%%)\n");

    for(int i = 0; i < n; i++) {

        float percent =
            ((float)p[i].share / total) * 100;

        printf("P%d\t%.2f%%\n",
               p[i].pid,
               percent);
    }

    return 0;
}
