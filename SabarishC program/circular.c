#include <stdio.h>
#include <stdlib.h>

#define N 5
int queue[N], rear = -1, front = -1, val, i;

void out() {
    printf("\n\n-_-_-_-_-_-_-_Displaying List_-_-_-_-_-_-_-\n\n");
    if (front == -1) {
        printf("\n_______________\nQueue is EMPTY\n_______________\n");
    } else {
        printf("\nThe list is:: ");
        for (i = front; i != rear; i = (i + 1) % N) {
            printf(" %d ", queue[i]);
        }
        printf(" %d ", queue[i]); // Print the last element
    }
}

void enqueue() {
    printf("\n\n-_-_-_-_-_-_-_INSERTION_-_-_-_-_-_-_-\n\n");
    printf("Enter the value of data: ");
    scanf("%d", &val);
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("\n____________________\nQueue FULL. [overflow]\n____________________\n");
    } else if (rear == -1 && front == -1) {
        front = rear = 0;
        queue[rear] = val;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = val;
    }
    out();
}

void dequeue() {
    printf("\n\n-_-_-_-_-_-_-_DELETION_-_-_-_-_-_-_-\n\n");
    if (front == -1 && rear == -1) {
        printf("\n____________________\nQueue is EMPTY [Underflow]\n______________________\n");
    } else {
        printf("\nThe deleted item is: %d", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % N;
        }
    }
    out();
}

void peek() {
    printf("\n\n-_-_-_-_-_-_-_PEEK ELEMENT_-_-_-_-_-_-_-\n\n");
    if (front != -1) {
        printf("\nThe TOPMOST element is:: %d", queue[front]);
    } else {
        printf("\nQueue is EMPTY");
    }
}

void isfull() {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("\n__________________\nQueue >> FULL.\n__________________\n");
    } else {
        printf("\n____________________\nQueue is NOT FULL\n____________________\n");
    }
}

void isempty() {
    if (front == -1 && rear == -1) {
        printf("\n____________________\nQueue >> EMPTY\n____________________\n");
    } else {
        printf("\nQueue is NOT EMPTY");
    }
}

int main() {
    int ch;
    printf("\n\n.................._Circular Queue using Array_..................\n\n");
    while (1) {
        printf("\n\n# MENU::" );
        printf("\n1.INSERTION\n2.DELETION\n3.Display List\n4.Queue FULL?\n5.Queue EMPTY?\n6.Peek item");
        printf("\nEnter your choice:  ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                out();
                break;
            case 4:
                isfull();
                break;
            case 5:
                isempty();
                break;
            case 6:
                peek();
                break;
            default:
                printf("\nWRONG Choice!!!");
                printf("\n\n");
                for (i = 0; i < 30; i++)
                    printf(" * ");
                printf("\n");
        }
    }
    return 0;
}

