#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roomie.h" 
#include "task_checker.h" 

void user_input(char *name, int size) {
    printf("\nName: ");
    fgets(name, size, stdin);  // Safer input handling
    name[strcspn(name, "\n")] = '\0';  // Remove trailing newline
}

int user_exist(char *name, int size, RoomieData data[]) {
    int found = 0; 
    for (int i =0; i < 3; i++) {
        if (strcmp(data[i].roomie, name) == 0) {
            found = 1; 
        }
    }
    return found; 
}

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