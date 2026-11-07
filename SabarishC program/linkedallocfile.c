#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int block;
    struct Node *next;
} Node;

void linkedAllocation(int files, int fileSizes[], int diskSize, int disk[]) {
    Node *start[files], *end[files], *temp;
    int i, j, k, flag;

    for (i = 0; i < files; i++) {
        start[i] = end[i] = NULL;
        flag = 0;
        k = 0;
        for (j = 0; j < diskSize && k < fileSizes[i]; j++) {
            if (disk[j] == -1) {
                temp = (Node *)malloc(sizeof(Node));
                temp->block = j;
                temp->next = NULL;
                disk[j] = i;
                if (start[i] == NULL) {
                    start[i] = end[i] = temp;
                } else {
                    end[i]->next = temp;
                    end[i] = temp;
                }
                k++;
                flag = 1;
            }
        }
        if (k != fileSizes[i]) {
            printf("File %d cannot be allocated.\n", i + 1);
            temp = start[i];
            while (temp != NULL) {
                disk[temp->block] = -1;
                temp = temp->next;
            }
        }
    }

    printf("Linked Allocation\n");
    printf("File No.\tBlocks\n");
    for (i = 0; i < files; i++) {
        if (start[i] != NULL) {
            printf("%d\t\t", i + 1);
            temp = start[i];
            while (temp != NULL) {
                printf("%d -> ", temp->block);
                temp = temp->next;
            }
            printf("NULL\n");
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

    linkedAllocation(files, fileSizes, diskSize, disk);

    return 0;
}

