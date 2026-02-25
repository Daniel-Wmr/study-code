#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;

    while (1) {
        printf("Type in an integer:\n");

        if (scanf("%d", &N) == 1) {
            break;
        }

        printf("Invalid input! Not an integer.\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    int* ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptr = N;

    printf("You entered %d and it is stored at memory address %p\n", *ptr, ptr);

    free(ptr);

    return 0;
}

