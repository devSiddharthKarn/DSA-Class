#include "stdio.h"
#include "stdlib.h"

#define MAX 10

typedef struct CircularQueue {
    int data[MAX];
    int front;
    int back;
} CircularQueue;

CircularQueue createCircularQueue() {
    CircularQueue circularQueue;
    circularQueue.front = -1;
    circularQueue.back = -1;
    return circularQueue;
}

int isFull(CircularQueue* circularQueue) {
    return ((circularQueue->back + 1) % MAX) == circularQueue->front;
}

int isEmpty(CircularQueue* circularQueue) {
    return circularQueue->front == -1;
}

void addToQueue(CircularQueue* circularQueue, int element) {

    if (isFull(circularQueue)) {
        printf("Queue is full\n");
        return;
    }

    // First element
    if (isEmpty(circularQueue)) {
        circularQueue->front = 0;
        circularQueue->back = 0;
    } else {
        circularQueue->back = (circularQueue->back + 1) % MAX;
    }

    circularQueue->data[circularQueue->back] = element;
}

int removeFromQueue(CircularQueue* circularQueue) {

    if (isEmpty(circularQueue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = circularQueue->data[circularQueue->front];

    // Last element removed
    if (circularQueue->front == circularQueue->back) {
        circularQueue->front = -1;
        circularQueue->back = -1;
    } else {
        circularQueue->front = (circularQueue->front + 1) % MAX;
    }

    return value;
}

void printQueue(CircularQueue* circularQueue) {

    if (isEmpty(circularQueue)) {
        printf("Queue is empty\n");
        return;
    }

    int i = circularQueue->front;

    while (1) {
        printf("%d ", circularQueue->data[i]);

        if (i == circularQueue->back)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

    CircularQueue q = createCircularQueue();

    addToQueue(&q, 10);
    addToQueue(&q, 20);
    addToQueue(&q, 30);

    printQueue(&q);

    printf("Removed: %d\n", removeFromQueue(&q));

    printQueue(&q);

    return 0;
}