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

Node* mergeTwoLists(Node* list1, Node* list2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    }
    else {
        tail->next = list2;
    }

    return dummy.next;
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
    int values1[] = {3, 6, 8};
    int n1 = 3;
    Node* list1 = createList(values1, n1);

    int values2[] = {4, 7, 9, 11};
    int n2 = 4;
    Node* list2 = createList(values2, n2);

    Node* merged = mergeTwoLists(list1, list2);
    printList(merged);

    freeList(merged);
    return 0;
}
