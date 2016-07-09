//
//  status.c
//
//
//  Created by Abhijeet Pandey.
//
//
/** System for error handling.
 */

#include "status.h"

/** default error message for unknown errors */
static char* unknownError = "Unknown error";

/** defined error messages */
static char* msg[] = {
	"",
	"File open failed",
	"Access refused",
	"File close failed",
	"Memory allocation failed",
	"Wrong date",
	"Full structure",
	"Empty structure",
	"Value not found",
	"Value already exists",
    "Index out of bounds",

	""
	};

/** get message associated with the given status value
 */
char* message(status s) {
	if (s >= ENDER) return unknownError;
	return msg[s];
}
