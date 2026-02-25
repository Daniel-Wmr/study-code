#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;

    // Eingabeschleife
    while (1) {
        printf("Type in an integer:\n");

        if (scanf("%d", &N) == 1) {
            break;
        }

        printf("Invalid input! Not an integer.\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    // Speicher für EINEN Integer
    int* ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptr = N;

    printf("You entered %d and it is stored at memory address %p\n",
           *ptr, (void*)ptr);

    free(ptr);
    ptr = NULL;

    // Speicher für N Integers
    ptr = calloc(N, sizeof(int));
    if (ptr == NULL) {
        printf("Calloc failed!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        *(ptr + i) = i * i;
    }

    // Speicher auf 2*N Integers erweitern
    int* temp = realloc(ptr, 2 * N * sizeof(int));
    if (temp == NULL) {
        printf("Realloc failed!\n");
        free(ptr);   // alter Speicher ist noch gültig
        return 1;
    }
    ptr = temp;

    for (int i = N; i < 2 * N; i++) {
        *(ptr + i) = i * i;
    }

    return 0;
}