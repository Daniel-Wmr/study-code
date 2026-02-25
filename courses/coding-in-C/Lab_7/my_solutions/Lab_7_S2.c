#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node* pNext;
} Node;

Node* head = NULL;

Node* create_node(double value) {
    Node* n = malloc(sizeof(Node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    n->value = value;
    n->pNext = NULL;
    return n;
}

void append(double value) {
    Node* newNode = create_node(value);

    // Fall 1: Liste ist leer → neuer Node wird head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Fall 2: Liste ist nicht leer → ans Ende laufen
    Node* current = head;
    while (current->pNext != NULL) {
        current = current->pNext;
    }

    current->pNext = newNode;
}

void print_list() {
    Node* current = head;
    while (current != NULL) {
        printf("%.2f -> ", current->value);
        current = current->pNext;
    }
    printf("NULL\n");
}

int main() {

    for (int i = 0; i < 50; i++) {
        append(i * 1.0);
    }

    print_list();

    return 0;
}