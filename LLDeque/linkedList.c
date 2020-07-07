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
    node->next = 0; 					// initialize next as empty
    list->frontSentinel->next = list->backSentinel; 	// set the node next to front sentinel as the back sentinel
    list->backSentinel = list->frontSentinel; 		// set the back sentinel as the front sentinel
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

Deque* dequeCreate() {
   struct Linkedlist *deque;
   deque = malloc(sizeof(struct LinkedList));
   assert(deque != 0);
   deque->frontSentinel->next = NULL;
   return deque;
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
