#include <stdio.h>

int myNumbers[5] = {10,20,30,40,50};

int main(void){

    int* pMyNumbers = myNumbers;
    int *second_element = pMyNumbers + 1;
    int *last_element = pMyNumbers + 4;
    printf("%p %p\n", second_element, last_element);
    printf("%d %d", (*second_element), (*last_element));

}