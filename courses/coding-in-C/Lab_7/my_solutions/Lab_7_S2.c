#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    double value;
    struct Node* pNext;
} Node;

Node* head = NULL;

Node* create_node(double value){
    Node* n = malloc(sizeof(Node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    n->value = value;
    n->pNext = NULL;

    return n;
}


int main(){
    
    
    return 0;
}