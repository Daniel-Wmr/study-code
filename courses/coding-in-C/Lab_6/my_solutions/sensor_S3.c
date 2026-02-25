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


int readSensorFile(const char* filepath, SensorData temp[]) {

    FILE* file = fopen(filepath, "r");
    if (!file) {
        printf("Datei %s konnte nicht geöffnet werden!\n", filepath);
        return -1;
    }

    int count = 0;
    while (count < 3000 &&
           fscanf(file, "%f %f",
                  &temp[count].time,
                  &temp[count].probability) == 2)
    {
        count++;
    }

    fclose(file);
    return count;
}

int main() {

    SensorData temp_SensorData1[3000];
    int count1 = readSensorFile("../sensor1.txt", temp_SensorData1);
    printf("Sensor 1: %d Messungen eingelesen.\n", count1);

    SensorData temp_SensorData2[3000];
    int count2 = readSensorFile("../sensor2.txt", temp_SensorData2);
    printf("Sensor 2: %d Messungen eingelesen.\n", count2);

    return 0;
}
