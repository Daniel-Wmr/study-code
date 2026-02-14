#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int array[] = {0,0,0,0,0,0,0,0,0,0};
    array[2] = 1;
    array[4] = 1;
    array[6] = 1;
    int size = sizeof(array) / sizeof(array[0]);
    int* p = array;

    int temp_array[10];
    int* p_temp = temp_array;

    for(int i=0; i<10; i++) *(p_temp+i)=0;
    
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp_array[i]);
    }
    printf("\n");



    //printf("%d\n", array[6]);

}