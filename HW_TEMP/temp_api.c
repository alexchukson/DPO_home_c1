#include "temp_api.h"
#include <stdlib.h>
#include <unistd.h>

int month_entries[12];
int year_entries[2048];

#define BUFFER_SIZE 256
struct sensor_array read_dataset(const char* fname){
    char ch = 0;
    int lines = 0;
    char line[BUFFER_SIZE] = "";
    int line_scanned = 0;
    struct sensor* temp;
    int hours = 0, minutes = 0;
    struct sensor_array result = {0, 0, 0, 0, 0};
    FILE* f = fopen(fname, "r");
    if (f){
        while ((ch = fgetc(f)) != EOF)
            if (ch == '\n') lines++;
        fclose(f);
    }

    memset(month_entries, 0, sizeof(month_entries));
    memset(year_entries, 0, sizeof(year_entries));
    struct sensor* ptrDataset = (struct sensor*)malloc(sizeof(struct sensor)*lines);
    temp = ptrDataset;
    f = fopen(fname, "r");
    if (f != NULL){
        while( fgets(line, sizeof(line), f))
        {
            int count = sscanf(line, "%d;%d;%d;%d;%d;%d;",
                &temp->year, &temp->month, &temp->day, &hours, &minutes, &temp->t);
            if (count == 6){
//                printf("%d;%d;%d;%d;%d;%d;\n",
//                   temp->year, temp->month, temp->day, hours, minutes, temp->t);
                temp->month -= 1; //from 0 to 11
                if (temp->month >= 0 && temp->month < 12) month_entries[temp->month]++;
                if (temp->year >= 0 && temp->year < 2048) year_entries[temp->year]++;
                temp++;
            }
            else printf("string %d is in wrong format. skipped \n", line_scanned);
            line_scanned++;
        }
        result.data = ptrDataset;
        result.size = line_scanned;
        fclose(f);
    }
    return result;
}

void print_usage(const char *program_name) {
    printf("Usage: %s -f <filename>\n", program_name);
    printf("  -f <filename>  Input file containing lines with 6 integers\n");
    printf("  -m <month_number>  month number from 1 to 12\n");
    printf("  -y <year_number>  year number from 0 to 2048\n");
    printf("  -h             Display this help message\n");
    printf("\nExample: %s -f data.txt\n", program_name);
}

struct sensor_array filter_by_month(struct sensor_array dataset, int m){
    struct sensor_array result = {0, 0, 0, 0, 0};
    if (month_entries[m] == 0) return result;
    struct sensor* ptrDataset = (struct sensor*)malloc(sizeof(struct sensor)*month_entries[m]);
    struct sensor* tmp = ptrDataset;
    float sum_temp = 0;
    int min_temp = 1e6;
    int max_temp = -1e6;
    for (unsigned int i = 0; i < dataset.size; i++){
//        printf("dataset.data[i].month %d \n", dataset.data[i].month);
        if (dataset.data[i].month == m){
            tmp = &dataset.data[i];
            if (tmp->t < min_temp) min_temp = tmp->t;
            if (tmp->t > max_temp) max_temp = tmp->t;
            sum_temp += tmp->t;
            tmp++;
        }
    }
    result.data = ptrDataset;
    result.size = month_entries[m];
    result.min_t = min_temp;
    result.max_t = max_temp;
    result.avg_t = sum_temp/month_entries[m];
    return result;
}

struct sensor_array filter_by_year(struct sensor_array dataset, int y){
    struct sensor_array result = {0, 0, 0, 0, 0};
    if (year_entries[y] == 0) return result;
    struct sensor* ptrDataset = (struct sensor*)malloc(sizeof(struct sensor)*year_entries[y]);
    struct sensor* tmp = ptrDataset;
    float sum_temp = 0;
    int min_temp = 1e6;
    int max_temp = -1e6;
    for (unsigned int i = 0; i < dataset.size; i++){
//        printf("dataset.data[i].month %d \n", dataset.data[i].month);
        if (dataset.data[i].year == y){
            tmp = &dataset.data[i];
            if (tmp->t < min_temp) min_temp = tmp->t;
            if (tmp->t > max_temp) max_temp = tmp->t;
            sum_temp += tmp->t;
            tmp++;
        }
    }
    result.data = ptrDataset;
    result.size = year_entries[y];
    result.min_t = min_temp;
    result.max_t = max_temp;
    result.avg_t = sum_temp/year_entries[y];
    return result;
}

void print_dataset(struct sensor_array dataset){
//    struct sensor temp;
    for (unsigned int i = 0; i < dataset.size; i++){
        struct sensor* temp = &dataset.data[i];
        printf("%d;%d;%d;%d;\n",
           temp->year, temp->month, temp->day, temp->t);
    }
}

int main(int argc, char* argv[]){
    // const char dataset_name[] = "HW_TEMP\\india_2000_2024_daily_weather.txt";
    char* dataset_name = "./temperature_bigS.csv";
    int opt = 0;
    int user_month = -1;
    int user_year = -1;
    struct sensor_array dataset;
    if (argc == 1){
        print_usage(argv[0]);
        return 2;
    }
    while((opt = getopt(argc, argv, "f:m:y:h")) != -1){
        switch(opt){
        case 'f':
            dataset_name = optarg;
            break;
        case 'm':
            user_month = atoi(optarg);
            break;
        case 'y':
            user_year = atoi(optarg);
            break;
        case 'h':
            print_usage(argv[0]);
            return 0;
        default:
            print_usage(argv[0]);
            return 1;
        }
    }

    dataset = read_dataset(dataset_name);
//    print_dataset(dataset);
    if (user_month >= 1 && user_month <= 12){
        printf("month\t min_t\t max_t\t avg_t\n");
        struct sensor_array cur_month_dataset = filter_by_month(dataset, user_month - 1);
        printf("%d\t %d\t %d\t %d\n", user_month, cur_month_dataset.min_t, cur_month_dataset.max_t, cur_month_dataset.avg_t);
    }else if (user_year >0 && user_year < 2048){
        printf("year\t min_t\t max_t\t avg_t\n");
        struct sensor_array cur_year_dataset = filter_by_year(dataset, user_year);
        printf("%d\t %d\t %d\t %d\n", user_year, cur_year_dataset.min_t, cur_year_dataset.max_t, cur_year_dataset.avg_t);
    }else{
        printf("month\t min_t\t max_t\t avg_t\n");
        for (int m = 0; m < 12; m++){
            struct sensor_array cur_month_dataset = filter_by_month(dataset, m);
    //        print_dataset(cur_month_dataset);
            printf("%d\t %d\t %d\t %d\n", m+1, cur_month_dataset.min_t, cur_month_dataset.max_t, cur_month_dataset.avg_t);
        }
    }
    return 0;
}
