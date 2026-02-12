#include <stdio.h>
#include <string.h>

void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n');
}


int main(void){

    char user_input[102];
    printf("Is your word a palindrome?\nType in your word (max. 100 characters):\n");
    fgets(user_input, sizeof(user_input), stdin);
    int str_len = strlen(user_input);
    if(user_input[str_len-1] != '\n'){
        clear_stdin();
    } 
    if (str_len > 0 && user_input[str_len - 1] == '\n') user_input[str_len - 1] = '\0';

    char user_input_inverted[101];
    for(int i=0; i<(str_len-1); i++) user_input_inverted[i] = user_input[(str_len-2)-i];
    printf("%s, %s", user_input, user_input_inverted);

}