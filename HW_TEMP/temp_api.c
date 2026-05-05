#include "temp_api.h"
#include <stdio.h>
struct sensor_array read_dataset(const char* fname){
    char ch = 0;
    int lines = 0;
    struct sensor* temp;
    int hours = 0, minutes = 0;
    struct sensor_array result = {0, 0};
    FILE* f = fopen(fname, "r");
    while ((ch = fgetc(f)) != EOF)
        if (ch == '\n') lines++;

    struct sensor* ptrDataset = (struct sensor*)malloc(sizeof(struct sensor)*lines);
    if (f != NULL){
        while(! feof(f)){
            temp = ptrDataset;
            fscanf(f, "%d;%d;%d;%d;%d;%d\n", 
                &temp->year, &temp->month, &temp->day, &hours, &minutes, &temp->t);
            temp++;
        }
        result.data = ptrDataset;
        result.size = lines;
        fclose(f);
    }
    return result;
}

int main(){
    // const char dataset_name[] = "HW_TEMP\\india_2000_2024_daily_weather.txt";
    const char dataset_name[] = "\\HW_TEMP\\temperature_small.csv";
    read_dataset(dataset_name);
    return 0;
}