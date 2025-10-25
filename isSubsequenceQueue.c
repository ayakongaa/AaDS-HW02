#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    char* a;
    int size;
    int start;
    int end;
} Queue;

void enqueue(Queue* queue, const char b) {
    queue->a[queue->end] = b;
    queue->end = (queue->end + 1);
    queue->size++;
}

void dequeue(Queue* queue) {
    if (queue->size == 0) {
        return;
    }
    char b = queue->a[queue->start];
    queue->start = (queue->start + 1);
    queue->size--;
}

char peek(Queue* queue) {
    if (queue->size == 0) {
        return '\0';
    }
    return queue->a[queue->start];
}

int main() {
    char a[] = "abd";
    char b[] = "uabqd";

    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_a > len_b) {
        fprintf(stdout, "NO\n");
        return 0;
    }

    Queue queue;
    queue.a = (char*)malloc(len_a * sizeof(char));
    queue.size = 0;
    queue.start = 0;
    queue.end = 0;
    

    for (int i = 0; i < len_a; i++) {
        enqueue(&queue, a[i]);
    }
    
    for (int i = 0; i < len_b; i++) {
        if (queue.size > 0 && peek(&queue) == b[i]) {
            dequeue(&queue);
        }
    }

    if (queue.size == 0) {
        fprintf(stdout, "YES\n");
    }
    else {
        fprintf(stdout, "NO\n");
    }

    free(queue.a);
    return 0;
}
