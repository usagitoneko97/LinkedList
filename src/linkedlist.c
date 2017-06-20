#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

void ListInit(LinkedList *list){
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;

}

void ListAddEmptyLinkedList (LinkedList *list, Item *item){
  list->head = item;
  list->tail = item;
  list->len = 1;
  item->next = NULL;

}

void ListAddLinkedList(LinkedList *list, Item *item){
  if(list->head==NULL){
    //empty list
    list->head = item;
    list->tail = item;
    list->len = 1;
    item->next = NULL;
  }
  else{
    list->tail->next = item;
    item->next = NULL;
    list->tail = item;
    list->len++;

  }
}

Item* ListRemoveFirst(LinkedList *list){
  if(list->head == NULL){
    return NULL;
  }
  else{
    list->head = list->head->next;
  }
}
Item* ListRemoveLinkedListByName(char* name, LinkedList *list){
  //preserve the head
  Item* tempHead = list->head;
  Item* deleteHead = NULL;
  Item *prevL = NULL;
  if(list->head == NULL){
    return NULL;
  }
  else{
    while(strcmp(((Student*)list->head->data)->name, name) != 0 || prevL == NULL){
      // prevL = currL;
      // currL = currL->next;
      prevL = list->head;
      list->head = list->head->next;  //move to next item to search
    }
      //succesfully found the name
      //----------------------------
      if(list->tail == list->head){
      //if data to be deleted is at the tail
        list->tail = prevL;
        deleteHead = list->head;
        list->head = prevL;

        list->head->next = deleteHead->next;  //deleting the data
        list->head = tempHead;//restore the head
        list->len--;
      }
      else if (tempHead == list->head){
        //if item to be deleted is head
        tempHead = tempHead->next;  //move the head to the next 1
        list->head = tempHead;  //restore the head
        list->len --;
      }
      else if (list->len == 1){
        //if there is only 1 data
         ListInit(list);
      }
      
      else{
      deleteHead = list->head;
      list->head = prevL;

      list->head->next = deleteHead->next;  //deleting the data
      list->head = tempHead;//restore the head
      list->len--;
      }

  }
}
