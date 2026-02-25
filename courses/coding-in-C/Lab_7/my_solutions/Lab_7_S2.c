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

void print_list() {
    Node* current = head;
    while (current != NULL) {
        printf("%.2f -> ", current->value);
        current = current->pNext;
    }
    printf("NULL\n");
}

void print_array(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main() {

    for (int i = 0; i < 50; i++) {
        append(i * 1.0);
    }

    print_list();
    printf("\n\n");

    srand(time(NULL));
    int array[51];

    for(int i = 0; i < 50; i++){
        int r = rand();
        array[i] = r;
    }
    print_array(array, 50);
    printf("\n\n");

    int r_number = rand();
    for(int i = 49; i > 2; i--){
        array[i+1] = array[i];
    }
    array[3] = r_number;
    print_array(array, 51);
    printf("\n\n");

    return 0;
}