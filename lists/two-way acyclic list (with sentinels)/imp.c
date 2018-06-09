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

  list -> begin = create_new_el(0);

  list -> end = create_new_el(0);
  list-> end -> left = list -> begin;
  list -> begin -> right = list -> end;

  return list;
}


struct el_list* seek_position (struct twoway_list *list, int position){
  struct el_list *temp = list -> begin;

  if ( position < 1 )  return list->end;

  while ( temp != list->end ) {
    if ( position == 0 )  break;
    temp = temp -> right;
    position--;
  }
  return temp;
}


struct el_list* seek_value (struct twoway_list *list, int value){
  struct el_list* temp = list -> begin -> right;

  while ( temp != list->end ){
    if ( temp->x == value )  break;
    temp = temp -> right;
  }

  return temp;
}


void insert_after ( struct twoway_list* list, struct el_list *temp, struct el_list *new_el ){
  new_el -> right = temp -> right;
  new_el -> left = temp;
  new_el -> right -> left = new_el;
  temp -> right = new_el;
}


void push_on_position (struct twoway_list *list, int element, int position){
  struct el_list *new_el = create_new_el (element);
  struct el_list *temp = seek_position (list, position);
  temp = temp -> left;
  insert_after (list, temp, new_el);
}


void push_after_value (struct twoway_list *list, int element, int value){
  struct el_list *new_el = create_new_el (element);
  struct el_list *temp = seek_value (list, value);
  if (temp == list->end)  temp = temp -> left;
  insert_after (list, temp, new_el);
}


void delete (struct twoway_list *list, struct el_list* temp){
  if ( temp == list -> end )  return;
  temp -> left -> right = temp -> right;
  temp -> right -> left = temp -> left;
  free (temp);
}


void pop_from_position (struct twoway_list *list, int position){
  delete (list, seek_position (list, position));
}


void pop_value (struct twoway_list *list, int value){
  delete (list, seek_value (list, value));
}


void print_from_beginning (struct twoway_list *list){
    struct el_list *temp = list -> begin -> right;
    printf ("\nTwoja lista od poczatku:\n");
    while ( temp != list->end ){
      printf ("%d\n", temp -> x);
      temp = temp -> right;
    }
}


void print_from_end (struct twoway_list *list){
    struct el_list *temp = list -> end -> left;
    printf ("\nTwoja lista od konca:\n");
    while ( temp != list->begin ){
      printf ("%d\n", temp -> x);
      temp = temp -> left;
    }
}


int seek_element_in_list (struct twoway_list *list, int value){
  struct el_list* temp = list -> begin -> right;
  int position = 1;

  while ( temp != list -> end  ){
    if ( temp->x == value )  break;
    temp = temp -> right;
    position++;
  }

  return temp == list->end ? 0 : position;
}


void delete_list (struct twoway_list *list){
    struct el_list* temp = list -> begin;
    while ( temp != list->end ){
      temp = temp -> right;
      free (temp->left);
    }
    free (temp);
    free (list);
}
