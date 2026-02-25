#include <stdio.h>


typedef struct SensorData{
    float time;
    float probability;
} SensorData;

typedef struct Sensor{
    int id;
    double threshold;
    SensorData data[3000];
    int object_detection[3000];
} Sensor;


int main() {

    SensorData temp_SensorData1[3000];
    FILE* pSensor1 = fopen("../sensor1.txt", "r");
    if (!pSensor1) {
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }

    int count = 0;
    while (count < 3000 &&
           fscanf(pSensor1, "%f %f", 
                  &temp_SensorData1[count].time,
                  &temp_SensorData1[count].probability) == 2) 
    {
        count++;
    }

    fclose(pSensor1);
    printf("Es wurden %d Messungen eingelesen.\n", count);

    
    SensorData temp_SensorData2[3000];
    FILE* pSensor2 = fopen("../sensor2.txt", "r");
    if (!pSensor2) {
        printf("Datei konnte nicht geöffnet werden!\n");
        return -1;
    }

    count = 0;
    while (count < 3000 &&
           fscanf(pSensor2, "%f %f", 
                  &temp_SensorData2[count].time,
                  &temp_SensorData2[count].probability) == 2) 
    {
        count++;
    }

    fclose(pSensor2);
    printf("Es wurden %d Messungen eingelesen.\n", count);

}