//
//  List.c
//
//
//  Created by Abhijeet Pandey.
//
//

#include <stdio.h>
#include "List.h"
#include "ListTest.c"
#include "status.h"

/** Empty List Creation

 */
List*	newList	(compFun comp,prFun pr) {

    List *s;

    s = malloc(sizeof(List));

    if (s) {

        s->nelts = 0;
        s->head = 0;
        s->comp = comp;
        s->pr = pr;

        return s;
    }

    return 0;
}

/** destroy the list  */
void 	delList	(List*s) {
    free(s);
}

/** get the Nth element of the list */
status 	nthInList	(List*s,int n,void**e) {
    if (s->nelts <= n) {

        Node *k = s->head;
        int i;
        for (i = 0; i <= n; i++) {
            *e = k->val;
            k = k->next;
        }

        return OK;
    }

    return INDER;
}

/** Insert element at a given position in the list */
status 	addListAt	(List*s,int n,void*e) {
    if (s->nelts <= n) {

        Node *newNode = (Node*)malloc(sizeof(Node));

        if (newNode) {
            newNode->val = e;
            newNode->next = NULL;
        }

        else {
            return ERRALLOC;
        }

        if (s->head == NULL) {
            //if list is empty insert Node as new Head.

            s->head = newNode;

            //Node successfully inserted in empty list
            s->nelts++;
            return OK;
        }
        else if (n == 0) {

            //if position to be inserted into is 0
            newNode->next = s->head;
            s->head = newNode;

            //Node succesfully inserted at initial position
            s->nelts++;

            return OK;
        }
        else {

            //Else
            int atPosition;

            Node *tmp = s->head;

            for (atPosition = 1; atPosition < n; atPosition++) {
                tmp = tmp->next;
            }

            newNode->next = tmp->next;
            tmp->next = newNode;

            //Node succesfully inserted at position n
            s->nelts++;



            return OK;



        }

    }

    return INDER;
}

/** remove the element located at a given position in list
 */
status 	remFromListAt	(List*s,int n,void**e) {

    if (s->nelts <= n) {
        Node *delNode = (Node*)malloc(sizeof(Node));

        delNode = s->head;

        Node *tmp = NULL;
        int i;
        for(i = 0; i < n; i++)
        {

            tmp = delNode;
            delNode = delNode->next;

        }

        if(n != 0) {
            tmp->next = delNode->next;
        }
        else {
            s->head = s->head->next;
        }

        *e = delNode->val;
        free(delNode);

        //Node successfully deleted from position n
        s->nelts--;
        return OK;
    }

    return INDER;

}

/** remove given element from given list
 */
status 	remFromList	(List*s,void*e) {

    Node *findNode = (Node*)malloc(sizeof(Node));
    Node *tmp = (Node*)malloc(sizeof(Node));

    findNode = s->head;
    tmp = NULL;

    if (findNode->val == e) {
        s->head = findNode->next;

        //Successfully removed element with value e at position 0
        free(findNode);
        s->nelts--;

        return OK;
    }
    else {
            int i;
        for (i= 1; i < s->nelts; i++) {
            tmp = findNode;
            findNode = findNode->next;

            if (findNode == e) {
                tmp->next = findNode->next;

                //Successfully removed element with value e
                free(findNode);
                s->nelts--;

                return OK;

            }
        }
    }

    return ERRABSENT;

}

/** display list elements as "[ e1 ... eN ]".
 */
void 	displayList	(List*s) {
    Node *listNode = (Node*)malloc(sizeof(Node));
    listNode = s->head;

    printf("LIST: [ ");
    int i;
    for (i = 1; i <= s->nelts; i++) {
        //Print function implemented from ListTest.c

        prString(listNode->val);
        if (i < s->nelts) {
            printf(", ");
        }

        listNode = listNode->next;
    }

    printf(" ]");

}

/** call given function with each element of given list
 */
void	forEach		(List*s,void(*f)(void*)) {

    Node *forEachNode= (Node*)malloc(sizeof(Node));
    forEachNode = s->head;
    int i;
    for (i = 1; i <= s->nelts; i++) {
        f(forEachNode->val);

        forEachNode = forEachNode->next;
    }

}


/** compute and return the number of elements in given list */
int	lengthList	(List*s) {
    return s->nelts;
}

/** add given element to given list according to compFun function */
status	addList	(List*s,void*e) {
    Node* currentNode = (Node *)malloc(sizeof(Node));

    Node* newNode = (Node *)malloc(sizeof(Node));

    if (newNode) {
        newNode->val = e;
        newNode->next = NULL;
    }

    if (s->head == NULL || s->head->val >= newNode->val)
    {
        newNode->next = s->head;
        s->head = newNode;

        s->nelts++;

        return OK;
    }

    else
    {

        currentNode = s->head;

        while (currentNode->next != NULL && currentNode->next->val < newNode->val)
        {
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;

        s->nelts++;

        return OK;
    }
    return ERRALLOC;
}

/** tests whether the list contains given element **/
Node*	isInList	(List*s,void*e) {
    Node *findNode = (Node*)malloc(sizeof(Node));

    findNode = s->head;

    if (findNode) {

        if (compString(findNode->val, e) == 0) {

            return findNode;
        }
        else {
                int i;
            for (i = 1; i <= s->nelts; i++) {

                if (compString(findNode->val, e) == 0) {

                    return findNode;

                }

                findNode = findNode->next;

            }
        }
    }

    return 0;
}
