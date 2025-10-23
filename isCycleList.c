#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    int N;
    
    scanf("%d", &N);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < N; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Для тестирования
    tail->next = head; // Создает циклический список

    int ans = -1;
    
    
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            ans = 1;
            break;
        }
    }

    printf("%d\n", ans);

    if (ans == -1) {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
