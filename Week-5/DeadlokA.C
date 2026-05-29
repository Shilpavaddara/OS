#include <stdio.h>

int main() {
    int n = 5, m = 3;
    int alloc[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,3},
        {2,1,1},
        {0,0,2}
    };

    int request[5][3] = {
        {0,0,0},
        {2,0,2},
        {0,0,0},
        {1,0,0},
        {0,0,2}
    };

    int avail[3] = {0,0,0};
    int finish[5] = {0};
    int i, j, k, flag;

    while(1) {
        flag = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                for(j = 0; j < m; j++) {
                    if(request[i][j] > avail[j])
                        break;
                }

                if(j == m) {
                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    finish[i] = 1;
                    flag = 1;
                }
            }
        }

        if(flag == 0)
            break;
    }

    flag = 0;
    printf("Deadlocked Processes: ");

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            flag = 1;
        }
    }

    if(flag == 0)
        printf("No Deadlock");

    return 0;
}
