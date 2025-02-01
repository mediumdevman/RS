#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_checker.h" 


#define MAX_DATA 1000

/**
 * Struct: CurricularData
 * ----------------------
 * @brief Represents a row from the a1-data-curricular.csv file.
 */
typedef struct {
    char roomie[50];           // Maps to the "name" column
    int dishes;       // Maps to the "dishes" column
    int sweep_vacuuming;          // Maps to the "sweep_vacuuming" column
    int towels;   // Maps to the "towels" column
    int garbage;          // Maps to the "garbage" column
    int recycling;          // Maps to the "recycling" column
    int beers;          // Maps to the "beers" column
} RoomieData;

/**
 * Function: read_csv_file
 * -----------------------
 * @brief Reads data from the a1-data-curricular.csv file and populates an array of CurricularData structs.
 *
 * @param filename The name of the CSV file to read.
 * @param data Array of CurricularData where the CSV data will be stored.
 * @return int The number of records successfully read.
 */
int read_file(const char *filename, RoomieData data[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    // Skip the header line
    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    fgets(buffer, sizeof(buffer), file);

    int index = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL && index < 1000) {
        sscanf(buffer, "%49[^,],%d,%d,%d,%d,%d,%d", 
               data[index].roomie, 
               &data[index].dishes, 
               &data[index].sweep_vacuuming, 
               &data[index].towels, 
               &data[index].garbage,
               &data[index].recycling, 
               &data[index].beers);
        index++;
    }

    fclose(file);
    return index;
}

/**
 * Function: print_data
 * --------------------
 * @brief Prints the contents of the array of CurricularData.
 *
 * @param data Array of CurricularData to print.
 * @param size The number of records in the array.
 * * @return int The number of records successfully read.
 */
void print_data(const RoomieData data[], int size) {
    printf("    Roomie |    Dishes     | Sweeping/Vacuuming | Towels     | Gargabe    | Recycling  | Beers Consumed\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%10s | %13d | %18d | %10d | %10d | %10d | %18d\n", 
            data[i].roomie, 
            data[i].dishes, 
            data[i].sweep_vacuuming, 
            data[i].towels, 
            data[i].garbage,
            data[i].recycling, 
            data[i].beers);
    }
}


/**
 * Function: main
 * --------------
 * @brief The main function and entry point of the program.
 *
 * @return int 0: No errors; 1: Errors produced.
 */
int main(int arguments, char *argv[]) {

    //int task = task_checker(arguments, argv); 
    char *filename = "master.csv"; 

    RoomieData data[MAX_DATA];  // Array to hold all rows from the CSV

    int roomie_data_refined = read_file(filename, data); 
    print_data(data, roomie_data_refined);


    //print_data(CSV_data, num_records_csv);

    return 0;
}
