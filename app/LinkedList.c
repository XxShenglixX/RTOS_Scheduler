#include "LinkedList.h"



void initLinkedList(LinkedList *list)
{
  list->head = NULL ;
  list->tail = NULL ;
}

void listElementCreate(ListElement *listElement,uint32_t data)
{
	listElement->data = data ;
	listElement->next = NULL ;
}

void listAddHead(LinkedList *list,ListElement *elementToAdd)
{
  ListElement *temp ;
  
  if(list->head == NULL)
  {  
    list->head = elementToAdd ;
    list->tail = list->head ;
  }
  else 
  {
    temp = list->head;
    list->head = elementToAdd ;
    (list->head)->next = temp ;
  }
}

void listAddTail(LinkedList *list,ListElement *elementToAdd)
{
  if(list->tail == NULL) //head should be NULL
  {
    list->head = elementToAdd ;
    list->tail = elementToAdd ;
  }
  else
  {
    (list->tail->next) = elementToAdd ;
    list->tail = elementToAdd ;
  }
}

ListElement *listRemoveHead(LinkedList *list)
{
  ListElement *nextElement, *returnElement ;
  
  if(list->head == NULL)
    return NULL ;
  else
  {
    if(list->head->next != NULL)
    {
      nextElement = list->head->next ; 
      list->head->next = NULL ;
      returnElement = list->head ;
      list->head = nextElement ;
    }
    else
    {
      returnElement = list->head ;
      list->head = NULL ;
    }
  }
  
  return returnElement ;
}

ListElement *listRemoveTail(LinkedList *list)
{
  ListElement *previousElement,*returnElement ;
  if(list->tail == NULL)
    return NULL ;
  else
  {
    for(previousElement = list->head ; previousElement->next != list->tail ; previousElement = previousElement->next);
    
    returnElement = list->tail ;
    previousElement->next = NULL ;
    list->tail = previousElement;
  }
  
  return returnElement ;
}
