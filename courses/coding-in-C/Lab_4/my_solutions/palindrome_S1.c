#include <stdio.h>

char input(char input[]){
    /*char user_input[20];
    scanf("%19s", input);
    printf("Your input: %s", input);
    */
    char* pInput = input;
    *(pInput+1) = 'c';
    printf("input: %s", pInput);

}

int main(void){

    char content[] = "Curly bird catches the worm";
    char* pContent = content;

    printf("content: %s\n", content);
    printf("pContent: %c\n", *pContent);

    *(pContent) = 'E';
    *(pContent + 1) = 'a';
    printf("content_neu: %s\n", content);

    input("AAtions speak louder than words");

}