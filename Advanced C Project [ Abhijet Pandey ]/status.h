//
//  status.h
//
//
//  Created by Abhijeet Pandey.
//
//
/** Minimal system for error handling.
 */

#ifndef __STATUS_H
#define __STATUS_H

typedef enum {
	OK,
	ERROPEN,
	ERRACCESS,
	ERRCLOSE,
	ERRALLOC,
	ERRDATE,
	ERRFULL,
	ERREMPTY,
	ERRABSENT,
	ERREXIST,
    INDER,

	UNKNOWN,
	ENDER
	} status;

/** get message associated with the given status value
 */
extern char* message(status s);


#endif
