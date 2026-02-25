#include <stdio.h>

int main() {

    FILE* pFile1 = fopen("file1.txt", "r");
    if (pFile1 == NULL) {
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }

    int c;
    while ((c = fgetc(pFile1)) != EOF) {
        putchar(c);   // gibt das Zeichen exakt so aus, wie es ist
    }
    fclose(pFile1);
    printf("\n\n");
    
    pFile1 = fopen("file1.txt", "r");
    if (pFile1 == NULL) {
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), pFile1) != NULL) { 
        printf("%s", buffer);
    } 
    fclose(pFile1);
    
    return 0;
}