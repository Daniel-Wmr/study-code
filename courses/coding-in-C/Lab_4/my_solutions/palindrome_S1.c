#include <stdio.h>

int main(void){

    char content[] = "Curly bird catches the worm";
    char* pContent = content;

    printf("%s", content);
    printf("%s", pContent);

}