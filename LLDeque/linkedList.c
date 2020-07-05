/***********************************************************
* Author: 
* Email: 
* Date Created: 
* Filename: linkedList.c
*
* Overview:
*	This program is a linked list implementation of the deque and bag ADTs. 
*	Note that both implementations utilize a linked list with
*	both a front and back sentinel and double links (links with
*	next and prev pointers).
************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

#ifndef FORMAT_SPECIFIER
#define FORMAT_SPECIFIER "%d"
#endif


/* ************************************************************************
	Structs Link and LinkedList
************************************************************************ */
struct Link {
    TYPE value;
    struct Link *next;
 };

 struct LinkedList {
    struct Link *sentinel;
 ;


/* ************************************************************************
	Linked List Functions
************************************************************************ */

LinkedList* linkedListCreate() {
	struct LinkedList *list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	assert(list != NULL);
	list->sentinel->next = NULL;
	list->sentinel->value = 0;
	return list;
}
	 
void deletelinkedList(LinkedList* list) {
	assert(list != NULL);
	free(list);
}

int sizelinkedList(LinkedList* myList) {
	assert(myList->sentinel->value != 0);
	return myList->sentinel->value;
}
	 
int isEmptyLinkedList(LinkedList* myList) {
	assert(myList->sentinel->value != 0);
	if (myList->sentinel->value == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void printLinkedList(LinkedList* list) {
	assert(list != NULL); 
	struct Link *node = list->sentinel->next; 
	assert(node != NULL);   
	while (node->next != NULL) { 
		printf("%d", node->value);
		node = node->next;     
	}
}


/* ************************************************************************
	Deque Functions
************************************************************************ */


/* ************************************************************************
	Bag Functions
************************************************************************ */
