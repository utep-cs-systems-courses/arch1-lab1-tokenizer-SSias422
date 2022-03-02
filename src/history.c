#include <stdio.h>
#include <stdlib.h>
#include "history.h"


List* init_history(){
  List *history = malloc(sizeof(List));

  Item *item = malloc(sizeof(Item));
  
  history->root = item;
  item->id = 0;
  item->str = NULL;
  item->next = NULL;
  

  return history;
}

void add_history(List *list, char *str){
  Item *newItem = malloc(sizeof(Item));
  Item *head = list->root;

  while(head->next != NULL)
    head = head->next;

  newItem->id = (head->id)+1;
  newItem->str = str;
  newItem->next = NULL;

  head->next = newItem;
  
}

char *get_history(List *list, int id){
  Item *head = list->root;
  head = head->next;
  while(head->next != NULL && head->id != id){
    head = head->next;
    printf("%d\n",head->id);
    }
  return head->str;
}

void print_history(List *list){
  char *navigator;
  Item *head = list->root->next;
  while(head != NULL){
    printf("%d> ",head->id);
    navigator = head->str;
    while(*navigator != '\0'){
      printf("%c",*navigator);
      navigator++;
    }
    head = head->next;
    printf("\n");
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  free(list);
}
