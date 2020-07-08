/***********************************************************
* Author:  Benjamin Cha, Tieying Chu, Samantha Rodarte
* Email: 
* Date Created: 7/5/20
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
   list = malloc(sizeof(struct LinkedList)); // allocate memory for list
   assert(list != NULL);  // check if list is empty 
   node = malloc(sizeof(struct Link)); // allocate memory for node
   assert(node != NULL); // check if node is empty
   list->frontSentinel = malloc(sizeof(struct LinkedList)); // allocate memory for front sentinel
   assert(list->frontSentinel != 0); // check if the front sentinel is empty
   list->backSentinel = malloc(sizeof(struct LinkedList)); // allocate memory for back sentinel
   assert(list->backSentinel != 0); // check if the back sentinel is empty
   node->next = 0; // set the next node empty
   list->frontSentinel->next = list->backSentinel; // set the next node front sentinel as the back sentinel
   list->backSentinel->prev = list->frontSentinel; // set the previous node of back sentinel as front sentinel
   list->size = 0; // set size as empty
   return list; // return list
}

int sizelinkedList(LinkedList* myList) {
   assert(myList->size != 0); // check if the size is empty
   return myList->size; // return the list size
}

int isEmptyLinkedList(LinkedList* myList) {
   return myList->size == 0; // return the list size as empty
} 
  
static void addLinkBefore(LinkedList* list, Link* link, TYPE value) {
   struct Link *node = malloc(sizeof(struct Link)); // allocate memory for 
   assert(list != 0); // check if the list is empty
   node->value = value; // set the value in the node as this value
   node->prev = link->prev; // set the previous node to the link's previous
   node->next = link; // set the next node as link
   link->prev->next = node; // set the previous and next node as node
   link->prev = node; // set the previous node as node
   list->size++; // increment the size
}

static void removeLink(LinkedList* list, Link* link) {
   assert(list != NULL); // check if the list is empty
   list->frontSentinel->next = link->next; // set the node next to the front sentinel as the next node in link
   list->backSentinel->next = link->next; // set the node previous to the back sentinel as the next node in link
   free(link); // frees memory from link
   list->size--; // decrement size
} 

void deletelinkedList(LinkedList* list) {
   assert(list != NULL); // checks if the list is empty
   removeLink(list, list->frontSentinel->next); // call removeLink function to remove front sentinel
   removeLink(list, list->backSentinel->prev); // call the removeLink function to remove the back sentinel
   free(list->frontSentinel); // free the front sentinel
   free(list->backSentinel); // free the back sentinel
   free(list); // free the list
}


void printLinkedList(LinkedList* list) {  
   assert(list != NULL); // checks if the list is empty 
   struct Link *node = list->frontSentinel->next; // allocate memory for node
   assert(node != NULL); // checks if node is empty
   while (node != list->backSentinel) { // while node isn't equl to the back sentinel
      printf("%d", node->value); // print the value of node
      node = node->next; // move onto the next node
   }
}

Deque* DequeCreate() {
   struct LinkedList *deque;
   deque = malloc(sizeof(struct LinkedList)); // allocate memory for deque
   assert(deque != NULL); // check if deque is empty
   deque->frontSentinel = malloc(sizeof(struct LinkedList)); // allocate memory for the front sentinel
   assert(deque->frontSentinel != 0); // check if the deque is empty
   deque->backSentinel = malloc(sizeof(struct LinkedList)); // allocate memory for the back sentinel
   assert(deque->backSentinel != 0); // check if the back sentinel is empty
   deque->frontSentinel->next = deque->backSentinel; // set the node next to the front sentinel as the back sentinel
   deque->backSentinel->prev = deque->frontSentinel; // set the node prev to the back sentinel as the front sentinel
   deque->size = 0; // set the size to 0
   return deque;  // return deque
}

void deleteDeque(Deque* myDeque) {
   assert(myDeque != NULL); // checks if myDeque is empty
   removeLink(myDeque, myDeque->frontSentinel->next); // call the removeLink function for the front sentinel
   removeLink(myDeque, myDeque->backSentinel->prev); // call the removeLink function for the back sentinel
   free(myDeque->frontSentinel); // free the front sentinel
   free(myDeque->backSentinel); // free the back sentinel
   free(myDeque); // free myDeque
}

int sizeDeque(Deque* myDeque) {
   return myDeque->size; // return the size of myDeque 
}

int isEmptyDeque(Deque* myDeque) {
   return myDeque->size == 0; // return the size of myDeque as 0  
}

void addFrontDeque(Deque* myDeque, TYPE value) {
   addLinkBefore(myDeque, myDeque->frontSentinel->next, value); // call addLinkbefore to add node next to the front sentinel
}

void addBackDeque(Deque* myDeque, TYPE value) {
   addLinkBefore(myDeque, myDeque->backSentinel, value); // call the addLinkBefore to add node at the back sentinel
}


/*returns the value of the link at deque's front, Coded by: Samantha Rodarte*/
TYPE frontDeque(Deque* myDeque){
   assert(myDeque != NULL);	//check that deque exists
   return myDeque->frontSentinel->next->value;	//return the value pointed to by the front sentinel

}			

/*returns the value of the link at deque's end, Coded by: Samantha Rodarte*/
TYPE backDeque(Deque* myDeque){
   assert(myDeque != NULL);	//check that the deque exists
   return myDeque->backSentinel->prev->value;	//return the value pointed to by the back sentinel
}				

/*removes the link at deque's front, Coded by: Samantha Rodarte*/
void removeFrontDeque(Deque* myDeque){
   assert(myDeque != NULL);	//check that the deque exists
   removeLink(myDeque, myDeque->frontSentinel->next); //remove link at front of deque
}			

/*removes the link at deque's end, Coded by: Samantha Rodarte*/
void removeBackDeque(Deque* myDeque){
   assert(myDeque != NULL);	//check that the deque exists
   removeLink(myDeque, myDeque->backSentinel->prev); //remove link at back of deque
}

/*prints the value of all links in the deque from front to back, Coded by: Samantha Rodarte*/
void printDeque(Deque* myDeque){
   	assert(myDeque!= NULL); //check that the deque exists				
   	struct Link *dlink = myDeque->frontSentinel->next; //create new link for what front sentinel points to
	while (dlink != myDeque->backSentinel) {	//as long as the link does not point to the back sentinel
	   printf("%d", dlink->value);	//print the value within each new link
	   dlink = dlink->next;	//move to next value
    }
}

/* ************************************************************************
	Bag Functions
************************************************************************ */

/*allocates and initializes the bag, Coded by: Samantha Rodarte*/
Bag* bagCreate(){
   struct LinkedList *b;	//create a linked list b, our bag
   b = malloc(sizeof(struct LinkedList));	//allocate memory to b
   assert(b != NULL);	//check that b now exists
   b->frontSentinel = malloc(sizeof(struct LinkedList)); //allocate memory to b's front sentinel
   assert(b->frontSentinel != NULL); //check that the front sentinel is not pointing to  NULL
   b->backSentinel = malloc(sizeof(struct LinkedList)); //allocate memory to b's back sentinel
   assert(b->backSentinel != NULL); //check that the back sentinel is not pointing to  NULL
   b->frontSentinel->next = b->backSentinel; 
   b->backSentinel->prev = b->frontSentinel; //close the list
   b->size = 0; //set size equal to 0
   return b; //return b, the bag created
}	

/*deallocates and deletes the bag, Coded by: Samantha Rodarte*/
void deleteBag(Bag* myBag){
	assert(myBag != NULL); //check that the bag exists
	removeLink(myBag, myBag->frontSentinel->next);
   	removeLink(myBag, myBag->backSentinel->prev);
    free(myBag->frontSentinel);
    free(myBag->backSentinel);
    free(myBag);	//free all dynamic memory associated with bag
}			

/*returns the size of bag, Coded by: Samantha Rodarte*/
int sizeBag(Bag* myBag){
	assert(myBag != NULL); //check that the bag exists
	return myBag->size;	//returns size of bag
}

/*returns 1 if the bag is empty or 0 if it isn't, Coded by: Samantha Rodarte*/
int isBagEmpty(Bag* myBag){
	assert(myBag != NULL); //check that the bag exists
    return myBag->size == 0; //returns a true/false integer depending on the size
}

/*adds an element to the bag, Coded by: Samantha Rodarte*/
void addBag(Bag* myBag, TYPE value){
	struct Link * new = (struct Link *) malloc(sizeof(struct Link)); //dynamically allocates memory to the link new
	assert (new != NULL);	//checks that new is not pointing to NULL
	new->value = value; //sets the value to our given value in the parameters
	new->next = myBag->frontSentinel->next;  //tells new to point to what front sentinel is pointing to
	myBag->frontSentinel->next = new; //tells front sentinel to point to new
}

/*returns 1 if an element can be found within the bag or 0 if it isn't, Coded by: Samantha Rodarte*/
int containsBag(Bag* myBag, TYPE value){
	struct Link *current = myBag->frontSentinel->next; //dynamically allocates memory to link, current
	while (current != myBag->backSentinel){	//checks if the end of bag is reached
		if (current->value == value) {	//checks if current's value is equal to the value given in the parameters
		return 1;	//returns 1 if found
		}
	current = current->next;	//increments current
	}
	return 0;	//returns 0 if not found
}

/*removes an element fromt the bag, Coded by: Samantha Rodarte*/
void removeBag(Bag* myBag, TYPE value){
	struct Link *previous = myBag->frontSentinel;	//dynamically allocates memory to link, previous
	struct Link *current = myBag->frontSentinel->next;	//dynamically allocates memory to link, current
	while (current != NULL){	//checks that current is not pointing to NULL
		if (current->value == value) {	//checks if current's value is equal to value given in the parameters
			previous->next = current->next;	//increments previous to current's position
			free(current);	//frees memory in current
			return; //ends function
		}
		previous = current;
		current = current->next; //increments current position
	}
}

/*prints the values of the links in the bag from front to back, Coded by: Samantha Rodarte*/
void printBag(Bag* myBag){
	printLinkedList(myBag);	//print function for elements in a linked list
}
