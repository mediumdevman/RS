#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roomie.h" 
#include "task_checker.h" 

/**
 * Function: user_input
 * -----------------------
 * @brief Called upon in stat_tracker.c file. inherits task_checker.h and roomie.h  
 * allows for prompting and inout handiling of username for specific roomie.
 *
 * @param name The name of roomie given by user when inputed into console
 * @param size size of character name, decided globally in stat_tracker.c
 */
void user_input(char *name, int size) {
    printf("\nName: ");
    fgets(name, size, stdin);  // Safer input handling
    name[strcspn(name, "\n")] = '\0';  // Remove trailing newline
}


/**
* Function: user_exist
 * -----------------------
 * @brief Checks if user that was inputed into cosole exsits in current state of master.csv
 *
 * @param name The name of roomie given by user when inputed into console
 * @param size size of character name, decided globally in stat_tracker.c
 * @param data array of Roomie strcuts that represents the roomies listed in apartment
 * 
 * @return int (0 or 1) 0 for roomie is not in apartment, 1 for roomie is in apartment
 */
int user_exist(char *name, int size, RoomieData data[]) {
    int found = 0; 
    for (int i =0; i < 3; i++) {
        if (strcmp(data[i].roomie, name) == 0) {
            found = 1; 
        }
    }
    return found; 
}

/**
* Function: user_exist
 * -----------------------
 * @brief Checks if user that was inputed into cosole exsits in current state of master.csv
 *
 * @param task The task inputed into console by user
 * @param size size of character name, decided globally in stat_tracker.c
 * @param name name of roomie, just used for presentation and clairt
 * 
 * @return int (0 or 1) 0 invalid task, 1 valid task
 */
int task_asker(char *task, int size, char *name) { 
    int valid = 0;
    printf("\nWelcome home %s, what can I do for you today? \n", name);
    while (!valid) {
        printf("\nInput: ");
        fgets(task, size, stdin);  // Safer input handling
        task[strcspn(task, "\n")] = '\0';  // Remove trailing newline
        valid = task_checker(task, name, size);
    }

    return valid; 

}

int duty_define(char *duty, int size, char *name) { 
        int valid_duty = 0; 
        printf("\nWhat did you do to today, %s? \n", name);
        while (!valid_duty) {
            printf("\nInput: ");
            fgets(duty, 50, stdin);  // Safer input handling
            duty[strcspn(duty, "\n")] = '\0';  // Remove trailing newline
            valid_duty = duty_checker(duty, name, size);
    }

    return valid_duty;
}

int times_complete(char *name) {
    int valid_amount = 0; 
    char input[50]; 
    int success = 0; 
    printf("\nHow many times did you do that today? \n");
    while (!success) {
        printf("\nInput: ");
        fgets(input, 50, stdin);  // Safer input handling
        if (sscanf(input, "%d", &valid_amount) == 1) {
            success = 1; 
        }
    }

    return valid_amount;

}

int times_checker(int num, char *name) {
    int success = 0; 
    char statement[50]; 
        printf("\nYou would like to report that you did that duty %d times (Y or N)\n", num);
        while (!success) {
            printf("\nInput: ");
            fgets(statement, 50, stdin);  // Safer input handling
            statement[strcspn(statement, "\n")] = '\0';  // Remove trailing newline
            if (strcmp(statement, "Y") == 0 ) { 
                success = num; 
            } else {
                printf("\nPlease input the correct value: \n");
                success = times_complete(name); 
            }
            
        } 
    return success;

}