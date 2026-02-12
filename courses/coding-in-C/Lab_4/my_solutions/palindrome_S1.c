#include <stdio.h>

int main(void){

    char content[] = "Curly bird catches the worm";
    char* pContent = content;

    printf("content: %s\n", content);
    printf("pContent: %c\n", *pContent);

    *(pContent) = 'E';
    *(pContent + 1) = 'a';
    printf("content_neu: %s\n", content);



}