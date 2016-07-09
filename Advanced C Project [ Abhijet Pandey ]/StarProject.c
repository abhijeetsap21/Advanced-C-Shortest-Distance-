//
//  StarProject.c
//
//
//  Created by Abhijeet Pandey.
//
//

#include <stdio.h>
#include <string.h>

/**Function to compare two elements (strings) */
static int compString (void * s1, void * s2) {
    return strcmp((char*)s1, (char*)s2);
}
