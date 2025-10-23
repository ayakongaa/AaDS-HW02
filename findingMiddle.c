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
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    printf("%d", slow->data);
    
    freeList(head);

    return 0;
}
