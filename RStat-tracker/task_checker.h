#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Function: task_checker
 * --------------------
 * @brief Detetects the argument and task type passed through the input.
 *
 * @param argument specific number of arguments passed through main.
 * @param vectors Actual arugment vectors passed through input.
 * @return int The task number to be used.
 */
int task_checker(int argument, char *vectors[]) { 

    int valid_task = 0; // boolean for if task can be passed to the compiler
    int task_num = 0; // pointer for the number of task but as a char because it is passed as a char

 
    for (int i = 1; i < argument; i++ ) { // make sure that the argument task was passed
        if (sscanf(vectors[1], "--TASK=%d", &task_num) == 1) {
            valid_task = 1; 
            break; 
        }
    }

    if (!valid_task || (task_num <= 0 || task_num > 6)) { // if task is not in valid range
        printf("\ninvalid argument/task \n");  // ask for better paramaters
        return 0; 
    } else { 
        printf("\nTask %d initiated\n", task_num); // if task is in range return task initaned and task number to pass 
        return task_num; 
    }

}

