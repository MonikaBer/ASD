#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


struct el_list* create_new_el (int element){
  struct el_list *new_el = (struct el_list*)malloc(sizeof(struct el_list));
  new_el -> x = element;
  new_el -> next = NULL;
  return new_el;
}


struct oneway_list* constructor_of_empty_list(){
  struct oneway_list *list = (struct oneway_list*)malloc(sizeof(struct oneway_list));
  list -> begin = NULL;
  list -> end = NULL;
  return list;
}


struct el_list* seek_position (struct oneway_list *list, int position){
  if ( position < 1 )  return NULL;
  struct el_list *temp = list -> begin;
  while ( temp != NULL ) {
    if ( position == 1 )  break;
    temp = temp -> next;
    position--;
  }
  return temp;
}


struct el_list* seek_value (struct oneway_list *list, int value){
  struct el_list* temp = list -> begin;
  while ( temp != NULL ){
    if ( temp->x == value )  break;
    temp = temp -> next;
  }
  return temp;
}


void insert_after ( struct el_list *temp, struct el_list *new_el ){
  new_el -> next = temp -> next;
  temp -> next = new_el;
}


struct oneway_list* insert_after_last (struct oneway_list *list, struct el_list *temp, struct el_list *new_el){
  temp = list -> end;
  temp -> next = new_el;
  list -> end = new_el;
  return list;
}


struct oneway_list* insert_before_first (struct oneway_list *list, struct el_list *temp, struct el_list *new_el){
  temp = list -> begin;
  new_el -> next = temp;
  list -> begin = new_el;
  return list;
}


struct el_list* find_pointer_on_previous_element (struct oneway_list *list, struct el_list *temp){
  struct el_list* tmp = list -> begin;
  while ( tmp->next != temp )  tmp = tmp -> next;
  return tmp;
}


struct oneway_list* push_on_position (struct oneway_list *list, int element, int position){
  struct el_list *new_el = create_new_el (element);
  if ( list->begin == NULL ){  //empty list
    list -> begin = new_el;
    list -> end = new_el;
  }
  else {  //non-empty list
    struct el_list *temp = seek_position (list, position);
    if ( temp == NULL )  //insert element on the end
      list = insert_after_last (list, temp, new_el);
    else if ( temp == list->begin )  //insert element on the beginning
      list = insert_before_first (list, temp, new_el);
    else { //insert element in the middle
      struct el_list *tmp = find_pointer_on_previous_element (list, temp);
      insert_after (tmp, new_el);
    }
  }
  return list;
}


struct oneway_list* push_after_value (struct oneway_list *list, int element, int value){
  struct el_list *new_el = create_new_el (element);
  if ( list->begin == NULL ){  //empty list
    list ->begin = new_el;
    list ->end = new_el;
  }
  else {  //non-empty list
    struct el_list *temp = seek_value (list, value);
    if ( temp == NULL || temp == list->end )
      list = insert_after_last (list, temp, new_el);
    else  insert_after (temp, new_el);
  }
  return list;
}


struct oneway_list* delete (struct oneway_list *list, struct el_list *temp){
  if ( temp == NULL )  return list;
  else if ( list->begin == list->end ){  //list with one element
    list -> begin = NULL;
    list -> end = NULL;
  }
  else if ( temp == list->begin )  //delete first element
    list -> begin = temp -> next;
  else if ( temp == list->end ){  //delete last element
    struct el_list *tmp = find_pointer_on_previous_element (list, temp);
    list -> end = tmp;
    tmp -> next = NULL;
  }
  else {  //delete element in the middle
    struct el_list *tmp = find_pointer_on_previous_element (list, temp);
    tmp -> next = temp -> next;
  }
  free (temp);
  return list;
}


struct oneway_list* pop_from_position (struct oneway_list *list, int position){
  return delete (list, seek_position (list, position));
}


struct oneway_list* pop_value (struct oneway_list *list, int value){
  return delete (list, seek_value (list, value));
}


void print_from_beginning (struct oneway_list *list){
    struct el_list *temp = list -> begin;
    printf ("\nTWOJA LISTA OD POCZATKU:\n");
    while ( temp != NULL ){
      printf ("%d\n", temp->x);
      temp = temp -> next;
    }
}


int seek_element_in_list (struct oneway_list *list, int value){
  struct el_list* temp = list -> begin;
  int position = 1;

  while ( temp != NULL  ){
    if ( temp->x == value )  break;
    temp = temp -> next;
    position++;
  }

  return temp == NULL ? 0 : position;
}


void delete_list (struct oneway_list *list){
    struct el_list *temp = list -> begin;
    while ( temp != list->end ){
      list -> begin = list -> begin -> next;
      free (temp);
      temp = list -> begin;
    }
    free (list);
    if ( temp != NULL)  free (temp);
}
