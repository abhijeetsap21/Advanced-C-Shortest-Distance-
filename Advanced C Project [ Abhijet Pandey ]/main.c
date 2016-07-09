//
//  main.c
//
//
//  Created by Abhijeet Pandey
//
//

#include <stdio.h>
#include "List.h"
#include "Map.h"


int main(int argc, char * argv[]) {
    char *STARTCITY = "Nancy";
    char *ENDCITY = "Bordeaux";
    char *fileName = "Map.txt";

    if (argc > 1) {
        if (argc == 2 || argc > 4) {
            printf("Algorithm Usage:");
            printf("\n [STARTCITY][ENDCITY][FILENAME]");
            printf("\ntakes either 0, 2 or 3 arguments.");
            printf("\n\n\t\t\t- @argument 1: String representing the name of the Starting City");
            printf("\n\n\t\t\t- @argument 2: String representing the name of the Goal City");
            printf("\n\n\t\t\t- @argument 1: String representing a text file map.");
            printf("\n");

            return 0;
        }
        else if (argc >= 3) {
            STARTCITY =  argv[1];
            ENDCITY = argv[2];
            if (argc == 4) {
                fileName = argv[3];
            }
        }
    }

    FILE *franceMap;

    franceMap = fopen(fileName, "rt");

    List *masterList = newList(compString, prString);

    if (franceMap != NULL)
    {
        masterList = loadMap(franceMap);

        if (masterList) {
            City *initCity = (City*)malloc(sizeof(City));
            City *goalCity = (City*)malloc(sizeof(City));

            initCity = findCity(masterList, STARTCITY);
            goalCity = findCity(masterList, ENDCITY);

            if (initCity == 0 || goalCity == 0) {

                printf("\n One or more of the input cities do not exist in the provided list\n");
                printf("\tCould not calculate distance from [%s] to [%s]\n\n", STARTCITY, ENDCITY);

                return 1;
            }

            sortMapByF(masterList, goalCity);

            linkNeighborsToCity(masterList);

            Node *headNode = masterList->head;
            int i;
            for (i = 1; i <= masterList->nelts; i++) {

                City *currentCity = headNode->val;

                sortNeighbors(currentCity->neighbors);

                headNode = headNode -> next;

            }


            printf("\n\n\tA * Algorithm\n\n");


            printf("\n\nCalculating the best distance from [%s] to [%s]\n", initCity->name, goalCity->name);

            aStar(initCity, goalCity, masterList);
        }


        fclose (franceMap);
    }
    else {
        printf("******************************************\n\n\tERROR! File [%s] does not exist or cannot be opened\n", fileName);
        printf("\n******************************************\n");
    }

    return 0;
}
