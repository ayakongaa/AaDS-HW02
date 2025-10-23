#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList(int values[], int n) {
    if (n == 0) 
        return NULL;
    
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = values[i];
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

Node* removeElement(Node* head, int val) {
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    Node* prev = head;
    Node* current = head->next;
    
    while (current != NULL) {
        if (current->data == val) {
            prev->next = current->next;
            current = prev->next;
        } 
        else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int N;
    int values[] = {1, 2, 3, 4, 5};
    int n = 5;

    Node* head = createList(values, n);
    
    removeElement(head, 3);
    printList(head);
    freeList(head);

    return 0;
}
