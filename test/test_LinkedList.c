#include "unity.h"
#include <stdint.h>
#include <malloc.h>
#include "LinkedList.h"


void setUp(void)
{
}

void tearDown(void)
{
}

/*--------initLinkedList---------*/

void test_initLinkedList_should_set_head_and_tail_to_NULL()
{
  LinkedList list ;
  
  initLinkedList(&list);
  
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
}


/*--------listElementCreate---------*/

void test_listElementCreate_given_0x100_should_create_element_with_0x100_stored()
{
  ListElement listElement ;
  
  listElementCreate(&listElement,0x100);
  
  TEST_ASSERT_EQUAL(0x100,listElement.data);
  TEST_ASSERT_NULL(listElement.next);
}

/*--------listAddHead---------*/

void test_listAddHead_given_emptyList()
{
  LinkedList list ;
  ListElement listElement ;
  
  initLinkedList(&list);
  
  listElementCreate(&listElement,0x100);
  
  listAddHead(&list,&listElement);
  
  TEST_ASSERT_EQUAL(&listElement,list.head);
  TEST_ASSERT_EQUAL(&listElement,list.tail);
  TEST_ASSERT_EQUAL(0x100,list.head->data);
  TEST_ASSERT_EQUAL(NULL,list.head->next);
    TEST_ASSERT_EQUAL(0x100,list.tail->data);
  TEST_ASSERT_EQUAL(NULL,list.tail->next);
  
}

void test_listAddHead_0x200_given_head_contain_0x100()
{
  LinkedList list ;
  ListElement listElement1 ;
  ListElement listElement2;
  
  initLinkedList(&list);
  
  listElementCreate(&listElement1,0x100);
  listElementCreate(&listElement2,0x200);
  
  listAddHead(&list,&listElement1);
  listAddHead(&list,&listElement2);
  
  TEST_ASSERT_EQUAL(&listElement2,list.head);
  TEST_ASSERT_EQUAL(&listElement1,list.tail);
  TEST_ASSERT_EQUAL(0x200,list.head->data);
  TEST_ASSERT_EQUAL(&listElement1,list.head->next);
}

/*--------listAddTail---------*/

void test_listAddTail_given_emptyList()
{
  LinkedList list ;
  ListElement listElement ;
  
  initLinkedList(&list);
  
  listElementCreate(&listElement,0x100);
  
  listAddTail(&list,&listElement);
  
  TEST_ASSERT_EQUAL(&listElement,list.head);
  TEST_ASSERT_EQUAL(&listElement,list.tail);
  TEST_ASSERT_EQUAL(0x100,list.head->data);
  TEST_ASSERT_EQUAL(NULL,list.head->next);
  TEST_ASSERT_EQUAL(0x100,list.tail->data);
  TEST_ASSERT_EQUAL(NULL,list.tail->next);
}

void test_listAddTail_0x500_given_list_contains_0x100_0x200_0x300()
{
  LinkedList list ;
  ListElement listElement1 ;
  ListElement listElement2;
  ListElement listElement3;
  ListElement listElement4;
  
  initLinkedList(&list);
  
  listElementCreate(&listElement1,0x100);
  listElementCreate(&listElement2,0x200);
  listElementCreate(&listElement3,0x300);
  listElementCreate(&listElement4,0x500);
  
  listAddHead(&list,&listElement3);
  listAddHead(&list,&listElement2);
  listAddHead(&list,&listElement1);
  
  TEST_ASSERT_EQUAL(&listElement1,list.head);
  TEST_ASSERT_EQUAL(&listElement3,list.tail);
  TEST_ASSERT_EQUAL(0x100,list.head->data);
  TEST_ASSERT_EQUAL(0x200,(list.head)->next->data);
  TEST_ASSERT_EQUAL(0x300,(list.head)->next->next->data);
  
  listAddTail(&list,&listElement4);
  
  TEST_ASSERT_EQUAL(&listElement4,list.tail);
  TEST_ASSERT_EQUAL(0x500,list.tail->data);
  TEST_ASSERT_EQUAL(NULL,list.tail->next);
}

/*--------listRemoveHead---------*/
void_test_listRemoveHead_given_emptyList_should_return_NULL()
{
  LinkedList list ;
  ListElement *listElement ;
  initLinkedList(&list);
  
  listElement = listRemoveHead(&list);
  TEST_ASSERT_NULL(listElement);
}

void test_listRemoveHead_given_list_of_0x100_0x200_0x300_should_return_0x100()
{
  LinkedList list ;
  ListElement listElement1 ;
  ListElement listElement2;
  ListElement listElement3;
  ListElement *returnElement;
  
  initLinkedList(&list);
  
  listElementCreate(&listElement1,0x100);
  listElementCreate(&listElement2,0x200);
  listElementCreate(&listElement3,0x300);
  
  listAddTail(&list,&listElement1);
  listAddTail(&list,&listElement2);
  listAddTail(&list,&listElement3);

  
  returnElement = listRemoveHead(&list);

  TEST_ASSERT_EQUAL(&listElement1,returnElement);
  TEST_ASSERT_EQUAL(0x100,returnElement->data);
  TEST_ASSERT_EQUAL(NULL,returnElement->next);
  
  TEST_ASSERT_EQUAL(&listElement2,list.head);
  TEST_ASSERT_EQUAL(&listElement3,list.tail);
}

/*--------listRemoveTail---------*/
void_test_listRemoveTail_given_emptyList_should_return_NULL()
{
  LinkedList list ;
  ListElement *listElement ;
  initLinkedList(&list);
  
  listElement = listRemoveTail(&list);
  TEST_ASSERT_NULL(listElement);
}

void test_listRemoveTail_given_list_of_0x100_0x200_0x300_should_return_0x300()
{
  LinkedList list ;
  ListElement listElement1 ;
  ListElement listElement2;
  ListElement listElement3;
  ListElement *returnElement;
  
  initLinkedList(&list);
  
  listElementCreate(&listElement1,0x100);
  listElementCreate(&listElement2,0x200);
  listElementCreate(&listElement3,0x300);
  
  listAddTail(&list,&listElement1);
  listAddTail(&list,&listElement2);
  listAddTail(&list,&listElement3);

  
  returnElement = listRemoveTail(&list);

  TEST_ASSERT_EQUAL(&listElement3,returnElement);
  TEST_ASSERT_EQUAL(0x300,returnElement->data);
  TEST_ASSERT_EQUAL(NULL,returnElement->next);
  
  TEST_ASSERT_EQUAL(&listElement1,list.head);
  TEST_ASSERT_EQUAL(&listElement2,list.tail);
}