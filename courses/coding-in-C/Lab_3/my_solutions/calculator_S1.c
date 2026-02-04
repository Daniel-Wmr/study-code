#include <stdio.h>

int main(){

    printf("Type in the two numbers you want to offset:\n");
    float first_number;
    scanf("%f", &first_number);
    float second_number;
    scanf("%f", &second_number);
    printf("Your two numbers: %f, %f\n\n", first_number, second_number);

    float result;
    int calculating = 1;
    while(calculating == 1){
        printf("Enter the arithmetic operation (+, -, *, /)\n");
        char a_operation;
        scanf(" %c", &a_operation);
        printf("Your arithmetic operation is: %c\n\n", a_operation);
        if(a_operation == '+'){
            result = first_number + second_number;
            printf("Result: %f\n", result);
            calculating = 0;
        }
        else if(a_operation == '-'){
            result = first_number + second_number;
            printf("Result: %f\n", result);
            calculating = 0;
        }
        else if(a_operation == '*'){
            result = first_number * second_number;
            printf("Result: %f\n", result);
            calculating = 0;
        }
        else if(a_operation == '/'){
            result = first_number / second_number;
            printf("Result: %f\n}", result);
            calculating = 0;
        }
        else{
            printf("Prompt is invalid - try again!\n\n");
        }
    }

    return 0;
}