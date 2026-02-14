#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int has_one(int* array, int size) {
    for(int i = 0; i < size; i++) {
        if(array[i] == 1)
            return 1;   // es gibt noch mindestens eine 1
    }
    return 0;           // keine 1 mehr vorhanden
}


int main(){

    int array[] = {0,0,0,0,0,0,0,0,0,0};
    array[2] = 1;
    array[4] = 1;
    array[6] = 1;
    array[8] = 1;
    int size = sizeof(array) / sizeof(array[0]);
    int* p = array;

    int temp_array[10];
    int* p_temp = temp_array;

    
    srand(time(NULL));
    int time_counter = 0;
    
    while(has_one(array, size)){
        for(int i=0; i<10; i++) *(p_temp+i)=0;
    
        for(int i=0; i<size; i++){
            if(*(p+i) == 1){
                int zufall = rand()%2;
                int target = i;

                if((zufall == 1) && (i+1 < size)) 
                    target = i+1;
                if((zufall == 0) && (i-1 >= 0)) 
                    target = i-1;
                
                if(*(p_temp + target) == 1){
                    *(p_temp + target) = 0;
                }
                else{
                    *(p_temp + target) = 1;
                }
            }
        }

        for(int i=0; i<size; i++) array[i] = temp_array[i];

        printf("Time %d: ", time_counter);
        for (int i = 0; i < size; i++) printf("%d ", array[i]);
        printf("\n");

        time_counter++;
        Sleep(1000);
    }
}