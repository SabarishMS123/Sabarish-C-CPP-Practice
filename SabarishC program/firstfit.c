#include <stdio.h>
#include <stdlib.h>

void best_fit() {
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest;
    static int barray[20], parray[20];

    printf("\n\t\t\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block no.%d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the processes:\n");
    for (i = 1; i <= np; i++) {
        printf("Process no.%d: ", i);
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= np; i++) {
        lowest = 9999; // Reset lowest for each process
        for (j = 1; j <= nb; j++) {
            if (barray[j] != 1) { // If block is not already assigned
                temp = b[j] - p[i];
                if (temp >= 0 && temp < lowest) {
                    lowest = temp;
                    parray[i] = j;
                }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n");
    for (i = 1; i <= np; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], parray[i], b[parray[i]], fragment[i]);
    }
}

void worst_fit() {
    int bsize[20], psize[20], all[20];
    int m, n, i, j;

    printf("\n\t\t\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each block:\n");
    for (i = 0; i < m; i++) {
        printf("Block no.%d: ", i + 1);
        scanf("%d", &bsize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process no.%d: ", i + 1);
        scanf("%d", &psize[i]);
        all[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int worstplace = -1;
        for (j = 0; j < m; j++) {
            if (bsize[j] >= psize[i]) {
                if (worstplace == -1 || bsize[worstplace] < bsize[j]) {
                    worstplace = j;
                }
            }
        }

        if (worstplace != -1) {
            all[i] = worstplace;
            bsize[worstplace] -= psize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (all[i] != -1) {
            printf("%d\n", all[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

void first_fit() {
    int bsize[20], psize[20], all[20];
    int m, n, i, j;

    printf("\n\t\t\tMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each block:\n");
    for (i = 0; i < m; i++) {
        printf("Block no.%d: ", i + 1);
        scanf("%d", &bsize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process no.%d: ", i + 1);
        scanf("%d", &psize[i]);
        all[i] = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (bsize[j] >= psize[i]) {
                all[i] = j;
                bsize[j] -= psize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (all[i] != -1) {
            printf("%d\n", all[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int choice, num = 1;

    while (num == 1) {
        printf("\nMENU\n\t1. BEST FIT\n\t2. WORST FIT\n\t3. FIRST FIT\n\t\t\t\tCHOICE::: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                best_fit();
                break;
            case 2:
                worst_fit();
                break;
            case 3:
                first_fit();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\nDo you want to continue? PRESS [1]CONTINUE [0]EXIT: ");
        scanf("%d", &num);
    }

    return 0;
}
