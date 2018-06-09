#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


struct el_list* create_new_el (int element){
  struct el_list *new_el = (struct el_list*)malloc(sizeof(struct el_list));
  new_el -> x = element;
  new_el -> left = NULL;
  new_el -> right = NULL;
  return new_el;
}


struct twoway_list* constructor_of_empty_list(){
  struct twoway_list *list = (struct twoway_list*)malloc(sizeof(struct twoway_list));
  list -> begin = NULL;
  list -> end = NULL;
  return list;
}


struct el_list* seek_position (struct twoway_list *list, int position){
  struct el_list *temp = list -> begin;
  if ( position < 1 )  return NULL;
  while ( temp != NULL ) {
    if ( position == 1 )  break;
    temp = temp -> right;
    position--;
  }
  return temp;
}


struct el_list* seek_value (struct twoway_list *list, int value){
  struct el_list* temp = list -> begin;
  while ( temp != NULL ){
    if ( temp->x == value )  break;
    temp = temp -> right;
  }
  return temp;
}


void insert_after ( struct el_list *temp, struct el_list *new_el ){
  new_el -> right = temp -> right;
  new_el -> left = temp;
  new_el -> right -> left = new_el;
  temp -> right = new_el;
}


struct twoway_list* insert_after_last (struct twoway_list* list, struct el_list *temp, struct el_list *new_el){
  temp = list -> end;
  temp -> right = new_el;
  new_el -> left = temp;
  list -> end = new_el;
  return list;
}


struct twoway_list* insert_before_first (struct twoway_list* list, struct el_list *temp, struct el_list *new_el){
  temp = list -> begin;
  new_el -> right = temp;
  temp -> left = new_el;
  list -> begin = new_el;
  return list;
}


struct twoway_list* push_on_position (struct twoway_list *list, int element, int position){
  struct el_list *new_el = create_new_el (element);
  if ( list->begin == NULL ){  //empty list
    list -> begin = new_el;
    list -> end = new_el;
  }
  else{  //non-empty list
    struct el_list *temp = seek_position (list, position);
    if ( temp == NULL )  //insert element on the end
      list = insert_after_last (list, temp, new_el);
    else {
      temp = temp -> left;
      if ( temp == NULL )  //insert element on the beginning
        list = insert_before_first (list, temp, new_el);
      else  //insert element in the middle
        insert_after (temp, new_el);
    }
  }
  return list;
}


struct twoway_list* push_after_value (struct twoway_list *list, int element, int value){
  struct el_list *new_el = create_new_el (element);
  if ( list->begin == NULL ){  //empty list
    list ->begin = new_el;
    list ->end = new_el;
  }
  else{  //non-empty list
    struct el_list *temp = seek_value (list, value);
    if ( temp == NULL || temp == list->end )  //value doesn't exist in list or insert element after last element in list 
      list = insert_after_last (list, temp, new_el);
    else   //value exist in list
      insert_after (temp, new_el);
  }
  return list;
}


struct twoway_list* delete (struct twoway_list *list, struct el_list *temp){
  if ( temp == NULL )  return list;
  else if ( temp ==list->begin && temp == list->end ){  //list with one element
    list -> begin = NULL;
    list -> end = NULL;
  }
  else if ( temp == list->begin ){  //first element to delete
    list -> begin -> right -> left = NULL;
    list -> begin = list -> begin -> right;
  }
  else if ( temp == list->end ){  //last element to delete
    temp -> left -> right = NULL;
    list -> end = temp -> left;
  }
  else{  //middle element to delete
    temp -> left -> right = temp -> right;
    temp -> right -> left = temp -> left;
  }
  free (temp);
  return list;
}


struct twoway_list* pop_from_position (struct twoway_list *list, int position){
  list = delete (list, seek_position (list, position));
  return list;
}


struct twoway_list* pop_value (struct twoway_list *list, int value){
  list = delete (list, seek_value (list, value));
  return list;
}


void print_from_beginning (struct twoway_list *list){
    struct el_list *temp = list -> begin;
    printf ("\nTWOJA LISTA OD POCZATKU:\n");
    while ( temp != NULL ){
      printf ("%d\n", temp->x);
      temp = temp -> right;
    }
}


void print_from_end (struct twoway_list *list){
    struct el_list *temp = list -> end;
    printf ("\nTWOJA LISTA OD KONCA:\n");
    while ( temp != NULL ){
      printf ("%d\n", temp->x);
      temp = temp -> left;
    }
}


int seek_element_in_list (struct twoway_list *list, int value){
  struct el_list* temp = list -> begin;
  int position = 1;

  while ( temp != NULL  ){
    if ( temp->x == value )  break;
    temp = temp -> right;
    position++;
  }

  return temp == NULL ? 0 : position;
}


void delete_list (struct twoway_list *list){
    struct el_list *temp = list -> begin;
    while ( temp != list->end ){
      temp = temp -> right;
      free (temp->left);
    }
    free (list);
    free (temp);
}
