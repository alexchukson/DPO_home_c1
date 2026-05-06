#include <stdio.h>
#include <stdint.h>
#include <string.h>
struct sensor {
    int day;
    int month;
    int year;
    int t;
};

struct sensor_array{
    struct sensor* data;
    uint32_t size;
    int min_t;
    int max_t;
    int avg_t;
};

struct sensor_array read_dataset(const char* fname);
void cgangeIJ(struct sensor* info,int i, int j);
void SortByDate(struct sensor* info, int n);
struct sensor_array monthStatistic(uint8_t month, struct sensor_array dataset);
struct sensor_array yearStatistic(uint8_t year, struct sensor_array month_data);
