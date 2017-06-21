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
  Item *prevL = NULL;
  Item *currL = list->head;
  if(list->head == NULL){
    return NULL;
  }
    while(strcmp(((Student*)currL->data)->name, name) != 0 || currL == NULL){
      // prevL = currL;
      // currL = currL->next;
      prevL = list->head;
      currL = currL->next;  //move to next item to search
    }
      //succesfully found the name
      //----------------------------
      //currL = data to be deleted
      if(prevL == NULL){
        //data to be deleted is head
        if(list->head == list->tail){
          //only 1 data
          list->head = NULL;
          list->tail = NULL;
          list->len = 0;
        }
        else{
          //more than 1 data
          currL = currL->next;
          list->len --;
        }
      }
      else if(currL == list->tail){
        //data to be deletd is tail
        prevL->next = currL->next;  //currL->next = NULL
        list->tail = prevL;
        list->len--;
      }
      currL = list->head;
      list->head = currL;



}
