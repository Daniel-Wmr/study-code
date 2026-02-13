#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n');
}


int main(void){

    char user_input[102];
    printf("Is your word a palindrome?\nType in your word (max. 100 characters):\n");
    fgets(user_input, sizeof(user_input), stdin);

    int str_len = strlen(user_input);
    if (user_input[str_len - 1] != '\n') {
        clear_stdin();
    } else {
        user_input[str_len - 1] = '\0';
        str_len--;                
    }
    
    char user_input_lc[102];
    for (int i = 0; user_input[i] != '\0'; i++)
        user_input_lc[i] = tolower((unsigned char) user_input[i]);
    user_input_lc[str_len] = '\0';

    char user_input_inverted[102];
    for(int i=0; i<str_len; i++) user_input_inverted[i] = user_input_lc[(str_len-1)-i];
    user_input_inverted[str_len] = '\0';

    if(strcmp(user_input_lc, user_input_inverted) == 0){
        printf("\nYour provided word \"%s\" is a palindrome.", user_input);
    }
    else{
        printf("\nYour provided word \"%s\" is not a palindrome.", user_input);
    }

}