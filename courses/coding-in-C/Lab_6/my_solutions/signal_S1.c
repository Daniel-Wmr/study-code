#include <stdio.h>

int main() {

    //fgetc
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
    
    //fgets
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
    printf("\n\n");

    //fscanf zeichenweise
    pFile1 = fopen("file1.txt", "r");
    if (pFile1 == NULL) {
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }

    while (fscanf(pFile1, "%c", &c) != EOF) {
        putchar(c);
    }
    fclose(pFile1);
    printf("\n\n");

    //fscanf zeilenweise
    pFile1 = fopen("file1.txt", "r");
    if (pFile1 == NULL) {
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }
 
    while (fscanf(pFile1, "%1023[^\n]", buffer) != EOF) { 
        printf("%s\n", buffer); 
        fgetc(pFile1); // den '\n' verbrauchen 
    }
    fclose(pFile1);
    
    return 0;
}