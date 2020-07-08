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
   struct Link *prev;
};

struct LinkedList {
   int size;
   struct Link *frontSentinel;
   struct Link *backSentinel;
};



/* ************************************************************************
	Linked List Functions
************************************************************************ */

LinkedList* linkedListCreate() {
    struct LinkedList *list;
    struct Link *node;
    list = malloc(sizeof(struct LinkedList)); 		// allocate memory into list
    assert(list != NULL);	 			// check if list is NULL
    node = malloc(sizeof(struct Link)); 		// allocate memory into node
    assert(node != NULL); 				// check if node is NULL
    list->frontSentinel = malloc(sizeof(struct LinkedList)); // allocate memory for the front sentinel
    assert(list->frontSentinel != 0); 			// check if the front sentinel is empty
    list->backSentinel = malloc(sizeof(struct LinkedList)); // allocate memory for the back sentinel
    assert(list->backSentinel != 0); 			// check if the back sentinel is empty
    list->frontSentinel->next = list->backSentinel; 	// set the node next to front sentinel as the back sentinel
    list->backSentinel = list->frontSentinel; 		// set the back sentinel as the front sentinel
    node->next = 0; 					// initialize next as empty
    list->size = 0; 					// intialize size as empty
    return list; 					// return list
}
	 
void deletelinkedList(LinkedList* list) {
    assert(list != NULL); 				// check if list is empty
    struct Link *node = list->frontSentinel->next; 	// allocate memory for node
    free(node); 					// free node
}

int sizelinkedList(LinkedList* myList) {
   assert(myList->size != 0); 				// check if size is empty
   return myList->size; 				// return the size of the link list
}
	 
int isEmptyLinkedList(LinkedList* myList) {
   assert(myList->size != 0); 				// check if size is empty
   if (myList->size == 0) { 				// if the size is empty 
      return 1; // true
   }
   else {
      return 0; // false
    }
}

static void addLinkBefore(LinkedList* list, Link* link, TYPE value) {
   assert(list != NULL); 				// check if the list is empty
   struct Link *node = (Link*)malloc(sizeof(struct Link)); // allocate memory for node
   node->value = value; 				// set the value fron node->value as this->value 
   node->next = link; 					// set the next node as link 
   link->next = node; 					// set the net node of link as node
}

static void removeLink(LinkedList* list, Link* link) {
   assert(list != NULL); 				// check if the list is empty
   list->frontSentinel->next = link->next; 		// set the next node of front sentinel as the next node of link
   list->backSentinel->next = link->next; 		// set the next node of back sentinel as the next nodee of link
   free(link); 						// free link
}



void printLinkedList(LinkedList* list) {
   assert(list != NULL); 				// check if the list is empty
   struct Link *node = list->frontSentinel->next; 	// allocate memory for node 
   assert(node != NULL); 				// check if node is empty
   while (list->backSentinel != NULL) { 		// while the back sentinel isn't null
       printf("%d", node->value); 			// print the value of the node
       node = node->next; 				// set node to the next node to keep searching
    }
}


/* ************************************************************************
	Deque Functions
************************************************************************ */

Deque* DequeCreate(){
   struct LinkedList *dq;
   dq->frontSentinel = (struct Link *) malloc(sizeof(struct Link));
   assert(dq->frontSentinel != 0);
   dq->backSentinel = (struct Link *) malloc(sizeof(struct Link));
   assert(dq->backSentinel != 0);
}

void deleteDeque(Deque* myDeque) {
   assert(myDeque != NULL);
   struct Link *deque = myDeque->frontSentinel->next;
   free(deque);
}

int sizeDeque(Deque* myDeque) {
   assert(myDeque->size != 0);
   return myDeque->size;
}

int isEmptyDeque(Deque* myDeque) {
   assert(myDeque->size != 0);
   if (myDeque->size == 0) {
      return 1;
   }
   else {
      return 0;
   }
}

void addFrontDeque(Deque* myDeque, TYPE value) {
   struct Link *deque = malloc(sizeof(struct Link));
   assert(myDeque != 0);
   deque->value = value;
   deque->prev = myDeque->frontSentinel->prev;
   deque->next = myDeque->frontSentinel->next;
   myDeque->size++;
}

void addBackDeque(Deque* myDeque, TYPE value) {
   struct Link *deque = malloc(sizeof(struct Link));
   assert(myDeque != 0);
   deque->value = value;
   deque->prev = myDeque->backSentinel->prev;
   deque->next = myDeque->backSentinel;
   myDeque->size++;
}

/*returns the value of the link at deque's front, Coded by: Samantha Rodarte*/
TYPE frontDeque(Deque* myDeque){
	struct Link *deque = malloc(sizeof(struct Link));
	assert(myDeque != 0);
	return myDeque -> frontSentinel -> value;
}			

/*returns the value of the link at deque's end, Coded by: Samantha Rodarte*/
TYPE backDeque(Deque* myDeque){
	struct Link *deque = malloc(sizeof(struct Link));
	assert(myDeque != 0);
	return myDeque -> backSentinel -> value;
}				

/*removes the link at deque's front, Coded by: Samantha Rodarte*/
void removeFrontDeque(Deque* myDeque){
	struct Link * dlink = myDeque->frontSentinel->next;
	if(dlink!=NULL){ /*the top element exists*/
	myDeque->frontSentinel->next = dlink->next;
	free(dlink);
	}
}			

/*removes the link at deque's end, Coded by: Samantha Rodarte*/
void removeBackDeque(Deque* myDeque){
	assert(myDeque != NULL); 				
   	struct Link *dlink = myDeque->frontSentinel->next;
   	while (dlink->next != NULL)			
       dlink = dlink->next; 	
	free(dlink);
}

/*prints the value of all links in the deque from front to back, Coded by: Samantha Rodarte*/
void printDeque(Deque* myDeque){
   	assert(myDeque!= NULL); 				
   	struct Link *dlink = myDeque->frontSentinel->next;
   	while (dlink != NULL) { 	
       printf("%d", dlink->value); 			
       dlink = dlink->next; 				
	}
}

/* ************************************************************************
	Bag Functions
************************************************************************ */

/*allocates and initializes the bag, Coded by: Samantha Rodarte*/
Bag* bagCreate(){
   struct LinkedList *b;
   b->frontSentinel = (struct Link *) malloc(sizeof(struct Link));
   assert(b->frontSentinel != 0);
}	

/*deallocates and deletes the bag, Coded by: Samantha Rodarte*/
void deleteBag(Bag* myBag){
	assert(myBag != NULL);
   	struct Link *bLink = myBag->frontSentinel->next;
  	 free(bLink);
}			

/*returns the size of bag, Coded by: Samantha Rodarte*/
int sizeBag(Bag* myBag){
	return myBag->size;
}

/*returns 1 if the bag is empty or 0 if it isn't, Coded by: Samantha Rodarte*/
int isBagEmpty(Bag* myBag){
   assert(myBag != NULL);
   if (myBag -> size == 0)
      return 1; // true
   else
      return 0; // false
}

/*adds an element to the bag, Coded by: Samantha Rodarte*/
void addBag(Bag* myBag, TYPE value){
	struct Link * new = (struct Link *) malloc(sizeof(struct Link));
	assert (new != 0);
	new->value = value;
	new->next = myBag->frontSentinel->next;
	myBag->frontSentinel->next = new;
}

/*returns 1 if an element can be found within the bag or 0 if it isn't, Coded by: Samantha Rodarte*/
int containsBag(Bag* myBag, TYPE value){
	struct Link *previous = myBag->frontSentinel;
	struct Link *current = myBag->frontSentinel->next;
	while (current != NULL){
		if (current->value == value) {
		return 1;
		}
	previous = current;
	current = current->next;
	}
	return 0;
}

/*removes an element fromt the bag, Coded by: Samantha Rodarte*/
void removeBag(Bag* myBag, TYPE value){
	struct Link *previous = myBag->frontSentinel;
	struct Link *current = myBag->frontSentinel->next;
	while (current != NULL){
		if (current->value == value) {
		previous->next = current->next;
		free(current);
		return;
		}
	previous = current;
	current = current->next;
	}
}

/*prints the values of the links in the bag from front to back, Coded by: Samantha Rodarte*/
void printBag(Bag* myBag){
	assert(myBag != NULL); 				
   	struct Link *bLink = myBag->frontSentinel->next;
   	while (bLink != NULL) { 	
       printf("%d", bLink->value); 			
       bLink = bLink->next; 				
	}
}
