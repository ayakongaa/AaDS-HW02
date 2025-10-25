#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001

typedef struct Deque {
    char data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque* dq) {
    dq->front = 0;
    dq->rear = 0;
    dq->size = 0;
}

void pushFront(Deque* dq, char c) {
    if (dq->size < MAX_SIZE) {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
        dq->data[dq->front] = c;
        dq->size++;
    }
}

void pushRear(Deque* dq, char c) {
    if (dq->size < MAX_SIZE) {
        dq->data[dq->rear] = c;
        dq->rear = (dq->rear + 1) % MAX_SIZE;
        dq->size++;
    }
}

char popFront(Deque* dq) {
    if (dq->size == 0) {
        return '\0';
    }
    char c = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX_SIZE;
    dq->size--;
    return c;
}

char popRear(Deque* dq) {
    if (dq->size == 0) {
        return '\0';
    }
    dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    char c = dq->data[dq->rear];
    dq->size--;
    return c;
}

int isPalindrome(const char* s) {
    Deque dq;
    initDeque(&dq);

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        pushRear(&dq, s[i]);
    }
    
    while (dq.size > 1) {
        char first = popFront(&dq);
        char last = popRear(&dq);
        if (first != last) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char test[] = "madam";

    printf("%s\n", isPalindrome(test) ? "YES" : "NO");

    return 0;
}
