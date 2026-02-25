#include <stdio.h>


int main(){

    FILE* pFile1 = fopen("file1.txt", "r");
    if(pFile1 == NULL){
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }

    int c;
    while((c=fgetc(pFile1)) != EOF){
        printf("Gelesen: %c\n", c);
    }

    fclose(pFile1);
    return 0;
}