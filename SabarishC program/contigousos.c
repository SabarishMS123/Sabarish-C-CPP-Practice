#include <stdio.h>

void contiguousAllocation(int files, int fileSizes[], int diskSize, int disk[]) {
    int startBlock[files], endBlock[files];
    int i, j, k, flag;

    for (i = 0; i < files; i++) {
        flag = 0;
        for (j = 0; j < diskSize - fileSizes[i]; j++) {
            flag = 1;
            for (k = j; k < j + fileSizes[i]; k++) {
                if (disk[k] != -1) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                startBlock[i] = j;
                endBlock[i] = j + fileSizes[i] - 1;
                for (k = startBlock[i]; k <= endBlock[i]; k++) {
                    disk[k] = i;
                }
                break;
            }
        }
        if (flag == 0) {
            printf("File %d cannot be allocated.\n", i + 1);
        }
    }

    printf("Contiguous Allocation\n");
    printf("File No.\tStart Block\tEnd Block\n");
    for (i = 0; i < files; i++) {
        if (disk[startBlock[i]] == i)
            printf("%d\t\t%d\t\t%d\n", i + 1, startBlock[i], endBlock[i]);
        else
            printf("%d\t\tNot Allocated\n", i + 1);
    }
}

int main() {
    int diskSize;
    printf("Enter the size of the disk: ");
    scanf("%d", &diskSize);

    int disk[diskSize];
    int i; 

    for (i = 0; i < diskSize; i++) {
        disk[i] = -1;
    }

    int files;
    printf("Enter the number of files: ");
    scanf("%d", &files);

    int fileSizes[files];
    printf("Enter the sizes of the files:\n");
    for (i = 0; i < files; i++) {
        printf("File %d size: ", i + 1);
        scanf("%d", &fileSizes[i]);
    }

    contiguousAllocation(files, fileSizes, diskSize, disk);

    return 0;
}

