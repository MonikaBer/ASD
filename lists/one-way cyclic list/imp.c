#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


struct el_list* create_new_el (int element){
  struct el_list *new_el = (struct el_list*)malloc(sizeof(struct el_list));
  new_el -> x = element;
  new_el -> next = new_el;
  return new_el;
}


//function returns NULL when position < 1 or list is empty or position doesn't exist
//otherwise it returns a pointer on element on wanted position
struct el_list* seek_position (struct el_list *list, int position){
  if ( list == NULL || position < 1 )  return NULL;
  if ( position == 1 )  return list;
  struct el_list *temp = list -> next;
  position--;
  while ( temp != list ) {
    if ( position == 1 )  return temp;
    temp = temp -> next;
    position--;
  }
  return NULL;
}


//function returns NULL when list is empty or wanted value doesn't exist in list
//otherwise returns a pointer on element
struct el_list* seek_value (struct el_list *list, int value){
  if ( list == NULL )  return NULL;
  if ( list->x == value )  return list;
  struct el_list* temp = list -> next;
  while ( temp != list ){
    if ( temp->x == value )  return temp;
    temp = temp -> next;
  }
  return NULL;
}


void insert_after ( struct el_list *temp, struct el_list *new_el ){
  new_el -> next = temp -> next;
  temp -> next = new_el;
}


struct el_list* find_pointer_on_previous_element (struct el_list *list, struct el_list *temp){
  struct el_list* tmp = list;
  while ( tmp->next != temp )  tmp = tmp -> next;
  return tmp;
}


void print_first_element (struct el_list *list){
  if ( list == NULL )  printf ("LISTA JEST PUSTA!\n");
  else  printf ("POCZATKIEM LISTY JEST ELEMENT: %d\n", list->x);
}


struct el_list* push_on_position (struct el_list *list, int element, int position){
  struct el_list *new_el = create_new_el (element);
  if ( list == NULL )  //empty list
    list = new_el;
  else {  //non-empty list
    struct el_list *temp = seek_position (list, position);
    if ( temp == NULL ) {  //insert element before first element
      struct el_list *tmp = find_pointer_on_previous_element (list, list);
      insert_after (tmp, new_el);
    }
    else if ( temp == list ) {  //insert element on the beginning
      struct el_list *tmp = find_pointer_on_previous_element(list, list);
      insert_after(tmp, new_el);
      list = new_el;
    }
    else {  //insert element in the middle
      struct el_list *tmp = find_pointer_on_previous_element(list, temp);
      insert_after(tmp, new_el);
    }
  }
  return list;
}


struct el_list* push_after_value (struct el_list *list, int element, int value){
  struct el_list *new_el = create_new_el (element);
  if ( list == NULL )  //empty list
    list = new_el;
  else {  //non-empty list
    struct el_list *temp = seek_value (list, value);
    if ( temp == NULL ) {
      struct el_list *tmp = find_pointer_on_previous_element (list, list);
      insert_after (tmp, new_el);
    }
    else  insert_after (temp, new_el);
  }
  return list;
}


struct el_list* delete (struct el_list *list, struct el_list *temp){
  if ( temp == NULL )  return list;
  else if ( list == list->next )  //list with one element
    list = NULL;
  else if ( temp == list ){  //delete first element
    struct el_list *tmp = find_pointer_on_previous_element (list, list);
    list = temp -> next;
    tmp -> next = list;
  }
  else {  //delete element in the middle
    struct el_list *tmp = find_pointer_on_previous_element (list, temp);
    tmp -> next = temp -> next;
  }
  free (temp);
  return list;
}


struct el_list* pop_from_position (struct el_list *list, int position){
  return delete (list, seek_position (list, position));
}


struct el_list* pop_value (struct el_list *list, int value){
  return delete (list, seek_value (list, value));
}


void print_from_beginning (struct el_list *list){
    printf ("\nTWOJA LISTA OD POCZATKU:\n");
    if (list == NULL  )  return;
    printf ("%d\n", list->x);
    struct el_list *temp = list -> next;
    while ( temp != list ){
      printf ("%d\n", temp->x);
      temp = temp -> next;
    }
}


int seek_element_in_list (struct el_list *list, int value){
  if ( list == NULL )  return 0;
  if ( list->x == value )  return 1;
  struct el_list* temp = list->next;
  int position = 2;
  while ( temp != list  ){
    if ( temp->x == value )  break;
    temp = temp -> next;
    position++;
  }

  return temp == list ? 0 : position;
}


void delete_list (struct el_list *list){
    if ( list == NULL )  return;
    struct el_list *helper_list = list -> next;
    struct el_list *temp = list->next;
    while ( helper_list != list ){
      helper_list = helper_list -> next;
      free (temp);
      temp = helper_list;
    }
    free (list);
}
