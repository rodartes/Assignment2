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
    list->backSentinel = list->frontSentinel;
    list->size = 0;
    return list;
}
	 
void deletelinkedList(LinkedList* list) {
    assert(list != NULL);
    struct Link *node = list->frontSentinel->next;
    free(node);
}

int sizelinkedList(LinkedList* myList) {
   assert(myList->size != 0);
   return myList->size;
}
	 
int isEmptyLinkedList(LinkedList* myList) {
   assert(myList->size != 0);
   if (myList->size == 0) {
      return 1;
   }
   else {
      return 0;
    }
}

static void addLinkBefore(LinkedList* list, Link* link, TYPE value) {
   assert(list != NULL);
   struct Link *node = (Link*)malloc(sizeof(struct Link));
   node->value = value;
   node->next = link;
   link->next = node;
}

static void removeLink(LinkedList* list, Link* link) {
   assert(list != NULL);
   list->frontSentinel->next = link->next;
   list->backSentinel->next = link->next;
   free(link);
}



void printLinkedList(LinkedList* list) {
   assert(list != NULL);
   struct Link *node = list->frontSentinel->next;
   assert(node != NULL);
   while (list->backSentinel != NULL) {
       printf("%d", node->value);
       node = node->next;
    }
}


/* ************************************************************************
	Deque Functions
************************************************************************ */

Deque* dequeCreate() {
   struct LinkedList *deque;
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
