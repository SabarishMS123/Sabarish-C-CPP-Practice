#include <stdio.h>

void indexedAllocation(int files, int fileSizes[], int diskSize, int disk[]) {
    int indexBlock[files], dataBlocks[files][diskSize];
    int i, j, k, flag;

    for (i = 0; i < files; i++) {
        flag = 0;
        for (j = 0; j < diskSize; j++) {
            if (disk[j] == -1) {
                indexBlock[i] = j;
                disk[j] = i;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("Index block for file %d cannot be allocated.\n", i + 1);
            continue;
        }
        k = 0;
        for (j = 0; j < diskSize && k < fileSizes[i]; j++) {
            if (disk[j] == -1) {
                dataBlocks[i][k] = j;
                disk[j] = i;
                k++;
            }
        }
        if (k != fileSizes[i]) {
            printf("File %d cannot be allocated.\n", i + 1);
            disk[indexBlock[i]] = -1;
            for (j = 0; j < k; j++) {
                disk[dataBlocks[i][j]] = -1;
            }
        }
    }

    printf("Indexed Allocation\n");
    printf("File No.\tIndex Block\tData Blocks\n");
    for (i = 0; i < files; i++) {
        if (disk[indexBlock[i]] == i) {
            printf("%d\t\t%d\t\t", i + 1, indexBlock[i]);
            for (j = 0; j < fileSizes[i]; j++) {
                printf("%d ", dataBlocks[i][j]);
            }
            printf("\n");
        } else {
            printf("%d\t\tNot Allocated\n", i + 1);
        }
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

    indexedAllocation(files, fileSizes, diskSize, disk);

    return 0;
}

