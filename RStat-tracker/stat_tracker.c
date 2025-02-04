#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h" 

#define MAX_DATA 3


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


void file_modifier(int task_num, char *name) {
   
    /*
    Below are the varaibles that the program keeps in mind while reassigning data
    */
    
    int num = 0; 
    int times_comp = 0; 
    char duty[50];

    /* 
    Below is all the task handiling for what needs to be changed in the 
    .csv file. 
    */

    if (task_num == 1) { 
        num = duty_define(duty, sizeof(duty), name); 
        times_comp = times_complete(name); 
        times_comp = times_checker(times_comp, name); 
        printf("\n<-- RECAP -->\n\nRoomie: %s \nTask Amount: %d \n\n<-- RECAP -->\n\n", name, times_comp); 
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

    char *filename = "master.csv"; // master data file. cannot be changed by user
    RoomieData data[MAX_DATA];  // array of data for use by sorter
     
    int roomie_data_refined = read_file(filename, data); 
    //print_data(data, roomie_data_refined);

    char name[50];
    user_input(name, sizeof(name));  // Pass the array
    user_exist(name, MAX_DATA, data);

    int task_num = 0; 

    if (user_exist(name, sizeof(name), data) == 1) {
        char task[50];
        task_num = task_asker(task, sizeof(task), name);
    } else {
        printf("\nSorry %s does not live here \n", name); 
    }

    file_modifier(task_num, name); 

    return 0;
}
