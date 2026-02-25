#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;

    printf("Type in an integer:\n");

    // Eingabe prüfen
    if (scanf("%d", &N) != 1) {
        printf("Invalid input! Not an integer.\n");

        // Eingabepuffer leeren
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        return 1;   // Fehlercode
    }

    // Speicher reservieren
    int* ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Wert speichern
    *ptr = N;

    printf("You entered %d and it is stored at memory address %p\n", *ptr, ptr);

    // Speicher freigeben
    free(ptr);

    return 0;
}
