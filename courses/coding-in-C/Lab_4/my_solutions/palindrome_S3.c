#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n');
}

int testing(char input[], int lenght){
    char input_lc[101];
    for (int i = 0; input[i] != '\0'; i++)
        input_lc[i] = tolower((unsigned char) input[i]);
    input_lc[lenght] = '\0';

    char input_inverted[101];
    for(int i=0; i<lenght; i++) input_inverted[i] = input_lc[(lenght-1)-i];
    input_inverted[lenght] = '\0';

    return strcmp(input_lc, input_inverted);

}


int main(void){

    char user_input[101];
    printf("Is your word a palindrome?\nType in your word (max. 100 characters):\n");
    fgets(user_input, sizeof(user_input), stdin);

    int str_len = strlen(user_input);
    if (user_input[str_len - 1] != '\n') {
        clear_stdin();
    } else {
        user_input[str_len - 1] = '\0';
        str_len--;                
    }
    
    if(testing(user_input, str_len) == 0){
        printf("\nYour provided word \"%s\" is a palindrome.", user_input);
    }
    else{
        printf("\nYour provided word \"%s\" is not a palindrome.", user_input);
    }

}