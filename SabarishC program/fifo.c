#include<stdio.h>

int main() {
    int reference_page[100], faults = 0, m, n, s, pages, frames;
    printf("Enter total number of pages:\t");
    scanf("%d", &pages);
    printf("Enter the values of the reference page:\n");
    
    for (m = 0; m < pages; m++) {
        printf("Page number [%d]:\t", m + 1);
        scanf("%d", &reference_page[m]);
    }

    printf("Enter number of frames:\n");
    scanf("%d", &frames);
    int temp[frames];
    
    for (m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    int position = 0;
    for (m = 0; m < pages; m++) {
        s = 0;
        
        for (n = 0; n < frames; n++) {
            if (reference_page[m] == temp[n]) {
                s++;
                faults--;
            }
        }
        
        faults++;
        
        if ((faults <= frames) && (s == 0)) {
            temp[position] = reference_page[m];
            position = (position + 1) % frames;
        } else if (s == 0) {
            temp[position] = reference_page[m];
            position = (position + 1) % frames;
        }
        
        printf("\n");
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1) {
                printf("%d\t", temp[n]);
            } else {
                printf("NIL\t");
            }
        }
    }

    printf("\nTotal page faults = %d\n", faults);
    printf("Page fault rate = %.2f%%\n", (float)faults * 100 / pages);
    printf("Hit ratio = %.2f%%\n", ((float)(pages - faults) * 100 / pages));

    return 0;
}

