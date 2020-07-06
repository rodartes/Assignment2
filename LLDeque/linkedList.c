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
	assert(myList->sentinel->next != NULL);
	if (myList->sentinel->next == NULL) {
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

/*returns the value of the link at deque's front, Coded by: Samantha Rodarte*/
TYPE frontDeque(Deque* myDeque){

}			

/*returns the value of the link at deque's end, Coded by: Samantha Rodarte*/
TYPE backDeque(Deque* myDeque){

}				

/*removes the link at deque's front, Coded by: Samantha Rodarte*/
void removeFrontDeque(Deque* myDeque){

}			

/*removes the link at deque's end, Coded by: Samantha Rodarte*/
void removeBackDeque(Deque* myDeque){

}

/*prints the value of all links in the deque from front to back, Coded by: Samantha Rodarte*/
void printDeque(Deque* myDeque){

}

/* ************************************************************************
	Bag Functions
************************************************************************ */

/*allocates and initializes the bag, Coded by: Samantha Rodarte*/
Bag* bagCreate(){

}	

/*deallocates and deletes the bag, Coded by: Samantha Rodarte*/
void deleteBag(Bag* myBag){

}			

/*returns the size of bag, Coded by: Samantha Rodarte*/
int sizeBag(Bag* myBag){

}

/*returns 1 if the bag is empty or 0 if it isn't, Coded by: Samantha Rodarte*/
int isBagEmpty(Bag* myBag){

}

/*adds an element to the bag, Coded by: Samantha Rodarte*/
void addBag(Bag* myBag, TYPE value){

}

/*returns 1 if an element can be found within the bag or 0 if it isn't, Coded by: Samantha Rodarte*/
int containsBag(Bag* myBag, TYPE value){

}

/*removes an element fromt the bag, Coded by: Samantha Rodarte*/
void removeBag(Bag* myBag, TYPE value){
	
}

/*prints the values of the links in the bag from front to back, Coded by: Samantha Rodarte*/
void printBag(Bag* myBag){

}