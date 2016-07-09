//
//  List.c
//
//
//  Created by Abhijeet Pandey.
//
//

#ifndef __AStar__Map__
#define __AStar__Map__
#define CITYNAME 30

#include <stdio.h>
#include "List.h"

//City structure
typedef struct City {
    char name[CITYNAME + 1];
    List *neighbors;
    int longitude, latitude;
    int g, h;
    struct City *link;
}City ;

//Neighbor structure
typedef struct Neighbor {
    char name[CITYNAME + 1];
    int distance;
    City *cityNode;
}Neighbor;


/** Loads Map from the specified file

 */

List *loadMap(FILE *);

/** Checks to city if string can be equated to a City in the list
 */
int isCity(char*);

/** Prints City when required by displayMap
 */
void prCity (void *);

/** Prints Neighbor node when required by displayNeighbors
 */
void prNeighbor (void *);

/** Prints a list of neighbors from the Neighbor list in City when required by displayMap
*/
void displayNeighbors (List *);

/** Prints the Map. Cities with their coordinates s, list of neighbors, distances, etc.

 */
void displayMap (List *);

/** Heuristic function that calculates the distance between two cities based on their coordinates
 */
int estimateDistance(City *, City *);

/** A* function that performs the main goal of the program

 */
void aStar (City*, City*, List*);

/** Checks to see if a string of characters exists as a City in the map List. Returns the City node

 */City *findCity (List *, char *);

/** Iterates through cities and sorts their list of Neighbors by their distance from the City
 */
void sortNeighbors (List *);

/** Sorts the main Map list
 */
void sortMapByF (List *, City *);

/** Once the main Map list has been compiled, this function iterates through the Neighbor Nodes
 of each City in order to link their City *link pointer back to the corresponding City node
 */
void linkNeighborsToCity (List*);

/** Formats and displays the resulting path list from A*. Uses City->g to print distance travelled.
 */
void displayPath (City*);

#endif /* defined(__AStar__Map__) */
