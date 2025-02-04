#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/**
 * Function: task_checker
 * --------------------
 * @brief Checks if user that was inputed into cosole exsits in current state of master.csv
 *
 * @param task The task inputed into console by user
 * @param size size of character name, decided globally in stat_tracker.c
 * @param name name of roomie, just used for presentation and clairt
 * 
 * @return int (0 to 3) each value represents a different executable except for 0 which means invalid task
 */
int task_checker(char *task, char*name, int size) { 

    if(strcmp(task, "help") ==0){
        printf("\nHelp !!! \n");
        printf("--------\n");
        printf("Input: \"Argument\"\n\n"); 
        printf("List of Arugments \n----------------\n");
        printf("Add -- [add entry to activity table]\nDisplay -- [Prints current actvity table data]\n");
        printf("BestR -- [Returns Roomie with most activitiy entries (-beers consumed)]\n");
        return 0; 
    } else if(strcmp(task, "add") ==0) {
        return 1; 
    } else if(strcmp(task, "display") ==0) {
        return 2; 
    } else if(strcmp(task, "bestr") ==0) {
        return 3; 
    } else {
        printf("\nPlease enter a valid task. Enter \"help\" for extra documentation \n");
        return 0; 
    }

    return 0;
}


int duty_checker(char *duty, char *name, int size) { 
    if (strcmp(duty, "dishes") == 0) { 
        return 1; 
    } else if (strcmp(duty, "dishes") == 0) { 
        return 2;
    } else if (strcmp(duty, "sweeping") == 0 || strcmp(duty, "vacuuming") == 0) { 
        return 3; 
    } else if (strcmp(duty, "towels") == 0) { 
        return 4; 
    } else if (strcmp(duty, "recylcing") == 0) { 
        return 5; 
    } else if (strcmp(duty, "beers") == 0) { 
        return 6; 
    } else {
        printf("\nPlease select from valid list of duties:\n \ndishes | sweeping/vacuuming | towels | recycling | beers \n");
        return 0; 
    }
}


