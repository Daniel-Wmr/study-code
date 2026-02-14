#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    for(int i=0; i<argc; i++){
        int len = strlen(argv[i]);
        printf("Argument %d at adress \"%p\" has content: %s (lenght %d)\n", i, (void*)argv[i], argv[i], len);

    }

    for(int i=0; i<argc; i++){
        int len = strlen(*(argv+i));
        printf("Argument %d at adress \"%p\" has content: %s (lenght %d)\n", i, (void *)(*(argv+i)), *(argv+i), len);
    }     

}