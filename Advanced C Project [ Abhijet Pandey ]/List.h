//
//  List.h
//
//
//  Created by Abhijeet Pandey.
//
//

#ifndef __List_H
#define __List_H

#include <stdlib.h>
#include "status.h"

/**  link structure */
typedef struct Node {
  void		*val;
  struct Node	*next;
} Node;

/** Comparison function for list elements. */
typedef int (*compFun)   (void* e1, void* e2);

/** Display function for list elements */
typedef void(*prFun)   (void*);

/** The list embeds a counter for its size and the two function pointers */
typedef struct List {
  int nelts;
  Node * head;
  compFun comp;
  prFun pr;
} List;


/** Empty List creation by dynamic memory allocation
 */
void 	delList	(List*);

/** get the Nth element of the list
 */
status 	nthInList	(List*,int,void**);

/** Insert element at a given position in the list
 */
status 	addListAt	(List*,int,void*);

/** remove the element located at a given position in list
 */
status 	remFromListAt	(List*,int,void**);

/** remove given element from given list
 */
status 	remFromList	(List*,void*);

/** display list elements
 */
void 	displayList	(List*);

/** call given function with each element of given list
 */
void	forEach		(List*,void(*)(void*));

/** compute and return the number of elements in given list
 */
int	lengthList	(List*);

/** add given element to given list according to compFun function
 */
status	addList	(List*,void*);

/** tests whether the list contains given element
 */
Node*	isInList	(List*,void*);

#endif
