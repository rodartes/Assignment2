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
   list = malloc(sizeof(struct LinkedList));
   assert(list != NULL);
   node = malloc(sizeof(struct Link));
   assert(node != NULL);
   list->frontSentinel = malloc(sizeof(struct LinkedList));
   assert(list->frontSentinel != 0);
   list->backSentinel = malloc(sizeof(struct LinkedList));

   assert(list->backSentinel != 0);
   node->next = 0;
   list->frontSentinel->next = list->backSentinel;
   list->backSentinel->prev = list->frontSentinel;
   list->size = 0;
   return list;
}

int sizelinkedList(LinkedList* myList) {
   assert(myList->size != 0);
   return myList->size;
}

int isEmptyLinkedList(LinkedList* myList) {
   return myList->size == 0;
} 
  
static void addLinkBefore(LinkedList* list, Link* link, TYPE value) {
   struct Link *node = malloc(sizeof(struct Link));
   assert(list != 0);
   node->value = value;
   node->prev = link->prev;
   node->next = link;
   link->prev->next = node;
   link->prev = node;
   list->size++;
}

static void removeLink(LinkedList* list, Link* link) {
   assert(list != NULL);
   list->frontSentinel->next = link->next;
   list->backSentinel->next = link->next;
   free(link);
   list->size--;
}

void deletelinkedList(LinkedList* list) {
   assert(list != NULL);
   removeLink(list, list->frontSentinel->next);
   removeLink(list, list->backSentinel->prev);
   free(list->frontSentinel);
   free(list->backSentinel);
   free(list);
}


void printLinkedList(LinkedList* list) {  
   assert(list != NULL);
   struct Link *node = list->frontSentinel->next;
   assert(node != NULL);
   while (node != list->backSentinel) {
      printf("%d", node->value);
      node = node->next;
   }
}

Deque* dequeCreate() {
   struct LinkedList *deque;
   deque = malloc(sizeof(struct LinkedList));
   assert(deque != NULL);
   deque->frontSentinel = malloc(sizeof(struct LinkedList));
   assert(deque->frontSentinel != 0);
   deque->backSentinel = malloc(sizeof(struct LinkedList));
   assert(deque->backSentinel != 0);
   deque->frontSentinel->next = deque->backSentinel;
   deque->backSentinel->prev = deque->frontSentinel;
   deque->size = 0;
   return deque;
}

void deleteDeque(Deque* myDeque) {
   assert(myDeque != NULL);
   removeLink(myDeque, myDeque->frontSentinel->next);
   removeLink(myDeque, myDeque->backSentinel->prev);
   free(myDeque->frontSentinel);
   free(myDeque->backSentinel);
   free(myDeque);
}

int sizeDeque(Deque* myDeque) {
   return myDeque->size == 0;
}

int isEmptyDeque(Deque* myDeque) {
   return myDeque->size == 0;
}

void addFrontDeque(Deque* myDeque, TYPE value) {
   addLinkBefore(myDeque, myDeque->frontSentinel->next, value);
}

void addBackDeque(Deque* myDeque, TYPE value) {
   addLinkBefore(myDeque, myDeque->backSentinel, value);
}


/* *************************************************************************/
TYPE frontDeque(Deque* myDeque){
   assert(myDeque != NULL) ;
   return myDeque->frontSentinel->next->value;

}			

/*returns the value of the link at deque's end, Coded by: Samantha Rodarte*/
TYPE backDeque(Deque* myDeque){
   assert(myDeque != NULL) ; 
   return myDeque->backSentinel->prev->value;
}				

/*removes the link at deque's front, Coded by: Samantha Rodarte*/
void removeFrontDeque(Deque* myDeque){
   assert(myDeque != NULL);
   removeLink(myDeque, myDeque->frontSentinel->next);
}			

/*removes the link at deque's end, Coded by: Samantha Rodarte*/
void removeBackDeque(Deque* myDeque){
   assert(myDeque != NULL);
   removeLink(myDeque, myDeque->backSentinel->prev);
}

/*prints the value of all links in the deque from front to back, Coded by: Samantha Rodarte*/
void printDeque(Deque* myDeque){
   	assert(myDeque!= NULL); 				
   	struct Link *dlink = myDeque->frontSentinel->next;
	while (dlink != myDeque->backSentinel) {
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
   b = malloc(sizeof(struct LinkedList));
   assert(b != 0);
   b->frontSentinel = malloc(sizeof(struct LinkedList));
   assert(b->frontSentinel != 0);
   b->backSentinel = malloc(sizeof(struct LinkedList));
   assert(b->backSentinel != 0);
   b->frontSentinel->next = b->backSentinel;
   b->backSentinel->prev = b->frontSentinel;
   b->size = 0;
   return b;
}	

/*deallocates and deletes the bag, Coded by: Samantha Rodarte*/
void deleteBag(Bag* myBag){
	assert(myBag != NULL);
	removeLink(myBag, myBag->frontSentinel->next);
        free(myBag->frontSentinel);
        free(myBag->backSentinel);
        free(myBag);
}			

/*returns the size of bag, Coded by: Samantha Rodarte*/
int sizeBag(Bag* myBag){
	return myBag->size;
}

/*returns 1 if the bag is empty or 0 if it isn't, Coded by: Samantha Rodarte*/
int isBagEmpty(Bag* myBag){
   return myBag->size == 0;
}

/*adds an element to the bag, Coded by: Samantha Rodarte*/
void addBag(Bag* myBag, TYPE value){
	 addLinkBefore(myBag, myBag->frontSentinel->next, value);
}

/*returns 1 if an element can be found within the bag or 0 if it isn't, Coded by: Samantha Rodarte*/
int containsBag(Bag* myBag, TYPE value){
	struct Link *current = myBag->frontSentinel->next;
	while (current != myBag->backSentinel){
		if (current->value == value) {
		return 1;
		}
	current = current->next;
	}
	return 0;
}

/*removes an element fromt the bag, Coded by: Samantha Rodarte*/
void removeBag(Bag* myBag, TYPE value){
	struct Link *current = myBag->frontSentinel->next;
	while (current != myBag->backSentinel){
		if (current->value == value) {
		   removeLink(myBag, current);
		}
	current = current->next;
	}
}

/*prints the values of the links in the bag from front to back, Coded by: Samantha Rodarte*/
void printBag(Bag* myBag){
	assert(myBag != NULL); 				
   	struct Link *bLink = myBag->frontSentinel->next;
	while (bLink != myBag->backSentinel) {
	   printf("%d", bLink->value);
	   bLink = bLink->next;
        }
}
