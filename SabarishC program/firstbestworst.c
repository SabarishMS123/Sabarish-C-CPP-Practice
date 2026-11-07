#include <stdio.h>

void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    int allocated[blocks];
    int i, j; // Declare variables outside of the for loop

    // Initialize allocation and allocated arrays
    for (i = 0; i < processes; i++) {
        allocation[i] = -1;
    }
    for (i = 0; i < blocks; i++) {
        allocated[i] = 0; // 0 means block is free
    }

    for (i = 0; i < processes; i++) {
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i] && allocated[j] == 0) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                allocated[j] = 1; // Mark block as allocated
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    int allocated[blocks];
    int i, j; // Declare variables outside of the for loop

    // Initialize allocation and allocated arrays
    for (i = 0; i < processes; i++) {
        allocation[i] = -1;
    }
    for (i = 0; i < blocks; i++) {
        allocated[i] = 0; // 0 means block is free
    }

    for (i = 0; i < processes; i++) {
        int bestIdx = -1;
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i] && allocated[j] == 0) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
            allocated[bestIdx] = 1; // Mark block as allocated
        }
    }

    printf("\nBest Fit Allocation\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    int allocated[blocks];
    int i, j; // Declare variables outside of the for loop

    // Initialize allocation and allocated arrays
    for (i = 0; i < processes; i++) {
        allocation[i] = -1;
    }
    for (i = 0; i < blocks; i++) {
        allocated[i] = 0; // 0 means block is free
    }

    for (i = 0; i < processes; i++) {
        int worstIdx = -1;
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i] && allocated[j] == 0) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
            allocated[worstIdx] = 1; // Mark block as allocated
        }
    }

    printf("\nWorst Fit Allocation\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blocks, processes, i,num=1,choice;
    printf("Enter number of blocks: ");
    scanf("%d", &blocks);
    int blockSize[blocks];
    printf("Enter block sizes:\n");
    for (i = 0; i < blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processes);
    int processSize[processes];
    printf("Enter process sizes:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    
    printf("Choose the allocation algorithm:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
   // printf("Enter your choice: ");
    //scanf("%d", &choice);

    // Reinitialize blockSize for each fit method since it gets modified
    int blockSize1[blocks], blockSize2[blocks], blockSize3[blocks];
    for (i = 0; i < blocks; i++) {
        blockSize1[i] = blockSize[i];
        blockSize2[i] = blockSize[i];
        blockSize3[i] = blockSize[i];
    }
   while(num!=0){
   	 printf("Enter your choice: ");
     scanf("%d", &choice);
   	
   
    switch (choice) {
        case 1:
            firstFit(blockSize1, blocks, processSize, processes);
            break;
        case 2:
            bestFit(blockSize2, blocks, processSize, processes);
            break;
        case 3:
            worstFit(blockSize3, blocks, processSize, processes);
            break;
        default:
            printf("Invalid choice!\n");
    }
    printf("\n Do you want to continue ?\n");
    scanf("%d",&num);
}

    return 0;
}

