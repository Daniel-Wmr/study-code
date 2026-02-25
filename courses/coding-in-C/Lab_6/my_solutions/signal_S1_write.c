 #include <stdio.h>
 

 int main(){
    // fputc – zeichenweises Schreiben
    FILE* pFile2 = fopen("file2.txt", "w");
    if (pFile2 == NULL) {
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }

    const char* text1 = "Hallo Welt!\nDies ist ein Test für fputc.\n\n";

    for (int i = 0; text1[i] != '\0'; i++) {
        fputc(text1[i], pFile2);
    }
    printf("fputc wurde ausgeführt.\n\n");

    // fputs – zeilenweises Schreiben
    fputs("Zeile 1: Hallo von fputs!\n", pFile2);
    fputs("Zeile 2: Noch eine Zeile.\n", pFile2);
    fputs("Zeile 3: fputs schreibt Strings am Stück.\n\n", pFile2);

    printf("fputs wurde ausgeführt.\n\n");

    // fprintf – formatiertes Schreiben
    int number = 42;
    const char* word = "Beispiel";

    fprintf(pFile2, "Formatiertes Schreiben:\n");
    fprintf(pFile2, "Zahl: %d\n", number);
    fprintf(pFile2, "Wort: %s\n", word);
    fprintf(pFile2, "Gemischt: Zahl=%d, Wort=%s\n", number, word);

    fclose(pFile2);
    printf("fprintf wurde ausgeführt.\n\n");

 
    return 0;
}