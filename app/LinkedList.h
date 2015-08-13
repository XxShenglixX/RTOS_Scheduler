#ifndef LinkedList_H
#define LinkedList_H

typedef struct LinkedList LinkedList;
typedef struct ListElement ListElement;

#include <stdint.h>
#include <malloc.h>

struct LinkedList 
{
	ListElement *head ;
  ListElement *tail ;
};

struct ListElement
{
  uint32_t data ;
  ListElement *next;
};

void initLinkedList(LinkedList *list);
void listElementCreate(ListElement *listElement,uint32_t data);

void listAddHead(LinkedList *list,ListElement *elementToAdd);
void listAddTail(LinkedList *list,ListElement *elementToAdd);

ListElement *listRemoveHead(LinkedList *list);
ListElement *listRemoveTail(LinkedList *list);

#endif // LinkedList_H
