#include <stdio.h>

typedef struct Car{
    char model[50];
    float fuel_level;
    float max_fuel_level;
} Car;

void refuel(Car* car, float fuel_amount){
    if(car == NULL) {
        printf("Objekt nicht gefunden - Pointer fehlerhaft!");
        return;
    }

    float new_level = car->fuel_level + fuel_amount;
    if(new_level > car->max_fuel_level){
        car->fuel_level = car->max_fuel_level;
    } else{
        car->fuel_level = new_level;
    }
}


int main() {

    Car myCar = {"BMW M3", 5.0f, 60.0f};

    printf("Vor dem Tanken: %.2f / %.2f Liter\n",
           myCar.fuel_level, myCar.max_fuel_level);

    refuel(&myCar, 30.25f);

    printf("Nach dem Tanken: %.2f / %.2f Liter\n",
           myCar.fuel_level, myCar.max_fuel_level);

    return 0;
}
