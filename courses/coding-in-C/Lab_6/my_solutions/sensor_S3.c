#include <stdio.h>

typedef struct SensorData {
    float time;
    float probability;
} SensorData;

typedef struct Sensor {
    int id;
    double threshold;
    SensorData data[3000];
    int object_detection[3000];
} Sensor;

typedef struct Interval {
    float start_time;
    float end_time;
} Interval;


// ------------------------------------------------------------
// Datei einlesen
// ------------------------------------------------------------
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


// ------------------------------------------------------------
// Threshold-basierte Objekterkennung
// ------------------------------------------------------------
void fillObjectDetection(Sensor* sensor, int count) {
    for (int i = 0; i < count; i++) {
        sensor->object_detection[i] =
            (sensor->data[i].probability > sensor->threshold) ? 1 : 0;
    }
}


// ------------------------------------------------------------
// Sensor aus temporären Daten erzeugen
// ------------------------------------------------------------
Sensor createSensor(int id, double threshold,
                    SensorData temp[], int count) {

    Sensor s;
    s.id = id;
    s.threshold = threshold;

    for (int i = 0; i < count; i++) {
        s.data[i] = temp[i];
    }

    fillObjectDetection(&s, count);

    return s;
}


// ------------------------------------------------------------
// Intervalle finden (Modus 1 = normal, Modus 2 = Überlappung)
// ------------------------------------------------------------
int findIntervals(const Sensor* s1,
                  const Sensor* s2,
                  int count,
                  Interval intervals[],
                  int mode)
{
    int interval_counter = 0;
    int in_interval = 0;
    float start_time = 0;

    for (int i = 0; i < count; i++) {

        int active;

        // Bedingung auswählen
        if (mode == 1) {
            active = (s1->object_detection[i] == 1);
        } else {
            active = (s1->object_detection[i] == 1 &&
                      s2->object_detection[i] == 1);
        }

        // START: 0 → 1
        if (!in_interval && active) {
            in_interval = 1;
            start_time = s1->data[i].time;
        }

        // ENDE: 1 → 0
        if (in_interval && !active) {
            in_interval = 0;

            intervals[interval_counter].start_time = start_time;
            intervals[interval_counter].end_time   = s1->data[i - 1].time;
            interval_counter++;
        }

        // Sonderfall: Datei endet während eines Intervalls
        if (in_interval && i == count - 1) {
            intervals[interval_counter].start_time = start_time;
            intervals[interval_counter].end_time   = s1->data[i].time;
            interval_counter++;
        }
    }

    return interval_counter;
}


// ------------------------------------------------------------
// Intervalle ausgeben
// ------------------------------------------------------------
void printIntervals(const char* title, Interval intervals[], int count) {
    printf("\n%s:\n", title);
    for (int i = 0; i < count; i++) {
        printf("  Intervall %d: %.3f → %.3f\n",
               i + 1,
               intervals[i].start_time,
               intervals[i].end_time);
    }
}


// ------------------------------------------------------------
// main()
// ------------------------------------------------------------
int main() {

    SensorData temp_SensorData1[3000];
    int count1 = readSensorFile("../sensor1.txt", temp_SensorData1);
    printf("Sensor 1: %d Messungen eingelesen.\n", count1);

    SensorData temp_SensorData2[3000];
    int count2 = readSensorFile("../sensor2.txt", temp_SensorData2);
    printf("Sensor 2: %d Messungen eingelesen.\n", count2);

    double threshold1 = 0.8;
    double threshold2 = 0.7;

    Sensor sensor1 = createSensor(1, threshold1, temp_SensorData1, count1);
    Sensor sensor2 = createSensor(2, threshold2, temp_SensorData2, count2);

    // Intervalle bestimmen
    Interval intervals1[3000];
    Interval intervals2[3000];
    Interval overlaps[3000];

    int n1 = findIntervals(&sensor1, NULL, count1, intervals1, 1);
    int n2 = findIntervals(&sensor2, NULL, count2, intervals2, 1);
    int nOverlap = findIntervals(&sensor1, &sensor2, count1, overlaps, 2);

    // Intervalle ausgeben
    printIntervals("Sensor 1 Intervalle", intervals1, n1);
    printIntervals("Sensor 2 Intervalle", intervals2, n2);
    printIntervals("Überlappende Intervalle", overlaps, nOverlap);

    return 0;
}
