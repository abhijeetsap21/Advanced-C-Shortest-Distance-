//
//  ListTest.c
//
//
//  Created by Abhijeet Pandey.
//
//
/**
 Sample test program for generic Lists
 */

static char rcsId[] = "@(#) $Id: ListTest.c 1957 2014-06-12 06:21:22Z phil $";

#include <stdio.h>
#include <string.h>
#include "List.h"


/*
 Function to compare two elements (strings) */


static int compString (void * s1, void * s2) {
    if (s1 == NULL || s2 == NULL) {
        return 1;
    }

    return strcmp((char*)s1, (char*)s2);
}

/**
 Function to display an element of the list
 */
static void prString(void * s) {
  printf("%s",(char*)s);
}

/**
 another display function, just to test "forEach"
 **/
static void prString2 (void * s) {
  printf("%s\n",(char*)s);
}
