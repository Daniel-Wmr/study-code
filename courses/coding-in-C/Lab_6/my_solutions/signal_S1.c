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
    printf("\n\n");
    
    // fscanf formatiertes Einlesen (z.B. Zahl + Wort)
    pFile1 = fopen("file1.txt", "r");
    if (pFile1 == NULL) {
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }

    int number;
    char word[100];

    /* 
       fscanf liest formatierte Daten.
       %d  → liest eine ganze Zahl (überspringt Whitespaces)
       %s  → liest ein Wort bis zum nächsten Whitespace
       Wichtig: fscanf liest NICHT die ganze Datei, sondern nur das,
       was dem Format entspricht.
    */
    if (fscanf(pFile1, "%d %99s", &number, word) == 2) {
        printf("Gelesene Zahl: %d\n", number);
        printf("Gelesenes Wort: %s\n", word);
    } else {
        printf("Datei enthält nicht das erwartete Format!\n");
    }

    fclose(pFile1);
    printf("\n\n");

    return 0;
}