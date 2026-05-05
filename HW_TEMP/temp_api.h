#include <stdio.h>
#include <stdint.h>
#include <string.h>
struct sensor {
    uint8_t day;
    uint8_t month;
    uint16_t year;
    int8_t t;
};

struct sensor_array{
    struct sensor* data;
    uint32_t size;
};

struct sensor_array read_dataset(const char* fname);
void cgangeIJ(struct sensor* info,int i, int j);
void SortByDate(struct sensor* info, int n);
struct sensor_array monthStatistic(uint8_t month, struct sensor_array dataset);
struct sensor_array yearStatistic(uint8_t year, struct sensor_array month_data);