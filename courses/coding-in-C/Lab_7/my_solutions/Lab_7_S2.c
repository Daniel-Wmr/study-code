#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void insert_at_position(double value, int position) {
    Node* newNode = create_node(value);

    if (position == 0) {
        newNode->pNext = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->pNext;
    }

    newNode->pNext = current->pNext;
    current->pNext = newNode;
}

void print_list() {
    Node* current = head;
    while (current != NULL) {
        printf("%.2f -> ", current->value);
        current = current->pNext;
    }
    printf("NULL\n\n");
}

void print_array(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void free_list() {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->pNext;
        free(current);
        current = next;
    }
}

int main() {

    for (int i = 0; i < 50; i++) {
        append(i * 1.0);
    }

    print_list();

    srand(time(NULL));
    int array[51];

    for(int i = 0; i < 50; i++){
        int r = rand();
        array[i] = r;
    }
    print_array(array, 50);

    int r_number = rand();
    for(int i = 49; i > 2; i--){
        array[i+1] = array[i];
    }
    array[3] = r_number;
    print_array(array, 51);

    insert_at_position(r_number, 3);
    print_list();

    free_list();

    return 0;
}