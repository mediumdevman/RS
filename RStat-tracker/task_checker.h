#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/**
 * Function: task_checker
 * --------------------
 * @brief Detetects the argument and task type passed through the input.
 *
 * @param argument specific number of arguments passed through main.
 * @param vectors Actual arugment vectors passed through input.
 * @return int The task number to be used.
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
    } else if(strcmp(task, "Add") ==0) {
        return 1; 
    } else if(strcmp(task, "Display") ==0) {
        return 2; 
    } else if(strcmp(task, "BestR") ==0) {
        return 3; 
    } else {
        printf("\nPlease enter a valid task. Enter \"help\" for extra documentation \n");
        return 0; 
    }

    return 0;
}


