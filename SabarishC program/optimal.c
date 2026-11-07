#include <stdio.h>

int findOptimal(int pages[], int temp[], int n, int index) {
    int i, j, pos = -1, farthest = index;
    
    for (i = 0; i < n; ++i) {
        for (j = index; j < 30; ++j) {
            if (temp[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == 30) {
            return i;
        }
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], faults = 0, hits = 0;
    int flag1, flag2, i, j, pos;

    printf("Enter number of control strings: ");
    scanf("%d", &no_of_pages);

    printf("Enter control strings: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                hits++;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    flag2 = 1;
                    faults++;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            pos = findOptimal(pages, frames, no_of_frames, i + 1);
            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1) {
                printf("%d\t", frames[j]);
            } else {
                printf("-\t");
            }
        }
    }

    float page_fault_ratio = (float)faults / no_of_pages * 100;
    float hit_ratio = (float)hits / no_of_pages * 100;

    printf("\n\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    printf("Page Fault Ratio = %.2f%%\n", page_fault_ratio);
    printf("Hit Ratio = %.2f%%\n", hit_ratio);

    return 0;
}

