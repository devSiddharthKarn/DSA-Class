#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX 100

typedef struct LinearQueue {
    int32_t start;
    int32_t end;
    int32_t data[MAX];
} LinearQueue;

LinearQueue createLinearQueue() {
    LinearQueue queue;
    queue.start = 0;
    queue.end = -1;
    return queue;
}

int isEmpty(LinearQueue* queue) {
    return queue->start > queue->end;
}

int isFull(LinearQueue* queue) {
    return queue->end == MAX - 1;
}

void Enqueue(LinearQueue* queue, int32_t data) {
    if (isFull(queue)) {
        printf("Queue Full\n");
        return;
    }

    queue->end++;
    queue->data[queue->end] = data;
}

int32_t Dequeue(LinearQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Empty\n");
        return 0;
    }

    int32_t element = queue->data[queue->start];
    queue->start++;

    return element;
}

void PrintQueue(LinearQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Empty\n");
        return;
    }

    for (int i = queue->start; i <= queue->end; i++) {
        printf("%d ", queue->data[i]);
    }

    printf("\n");
}

int main() {
    LinearQueue queue = createLinearQueue();

    Enqueue(&queue, 10);
    Enqueue(&queue, 20);
    Enqueue(&queue, 30);

    printf("Queue: ");
    PrintQueue(&queue);

    printf("Dequeued: %d\n", Dequeue(&queue));
    printf("Dequeued: %d\n", Dequeue(&queue));

    printf("Queue: ");
    PrintQueue(&queue);

    Enqueue(&queue, 40);
    Enqueue(&queue, 50);

    printf("Queue: ");
    PrintQueue(&queue);

    return 0;
}