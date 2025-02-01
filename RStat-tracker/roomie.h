#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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