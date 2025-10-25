#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001

typedef struct Stack {
    char data[MAX_SIZE];
    int size;
} Stack;

void push(Stack* stack, char c) {
    stack->data[stack->size] = c;
    stack->size++;
}

char pop(Stack* stack) {
    if (stack->size == 0) {
        return '\0';
    }
    stack->size--;
    return stack->data[stack->size];
}

int isPalindrome(const char* s) {
    Stack stack;
    stack.size = 0;

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        push(&stack, s[i]);
    }
 
    for (int i = 0; i < len; i++) {
        if (s[i] != pop(&stack)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char test[] = "abba";

    if (isPalindrome(test)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}
