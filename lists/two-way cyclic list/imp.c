#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


struct el_list* create_new_el (int element){
  struct el_list *new_el = (struct el_list*)malloc(sizeof(struct el_list));
  new_el -> x = element;
  new_el -> left = new_el;
  new_el -> right = new_el;
  return new_el;
}


//function returns NULL when position < 1 or position doesn't exist or list is empty
//otherwise function returns an pointer on element on wanted position
struct el_list* seek_position (struct el_list *list, int position){
  if ( position < 1 || list == NULL)  return NULL;
  if ( position == 1 )  return list;
  struct el_list *temp = list->right;
  position--;
  while ( temp != list ) {
    if ( position == 1 )  return temp;
    temp = temp -> right;
    position--;
  }
  return NULL;
}


//function returns NULL when list is empty or value doesn't exist in list
//otherwise function returns an pointer on element
struct el_list* seek_value (struct el_list *list, int value){
  if ( list == NULL )  return NULL;
  if ( value == list->x )  return list;
  struct el_list* temp = list -> right;
  while ( temp != list ){
    if ( temp->x == value )  return temp;
    temp = temp -> right;
  }
  return NULL;
}


//function inserts new element after element indicated by *temp
void insert_after ( struct el_list *temp, struct el_list *new_el ){
  new_el -> right = temp -> right;
  new_el -> left = temp;
  new_el -> right -> left = new_el;
  temp -> right = new_el;
}


//function inserts new element before element indicated by *list
void insert_before_first (struct el_list *list, struct el_list *new_el){
  new_el -> left = list -> left;
  new_el -> right = list;
  list -> left -> right = new_el;
  list -> left = new_el;
}


void print_first_element (struct el_list* list){
  if ( list  == NULL )
    printf ("LISTA JEST PUSTA!\n");
  else
    printf ("POCZATKIEM LISTY JEST ELEMENT: %d\n", list->x);
}


struct el_list* push_on_position (struct el_list *list, int element, int position){
  struct el_list *new_el = create_new_el (element);
  if ( list == NULL )  //empty list
    list = new_el;
  else {  //non-empty list
    struct el_list *temp = seek_position (list, position);
    if ( temp == NULL ) {
      insert_before_first (list, new_el);
      if ( temp == list )  list = new_el;
    }
    else {
      if ( temp == list )  list = new_el;
      temp = temp -> left;
      insert_after (temp, new_el);
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
    if ( temp == NULL )  insert_before_first (list, new_el);
    else  insert_after (temp, new_el);
  }
  return list;
}


struct el_list* delete (struct el_list *list, struct el_list *temp){
  if ( temp == NULL )  return list;
  if ( list->right == list )  list = NULL;
  if ( temp == list )  list = list -> right;
  temp -> left -> right = temp -> right;
  temp -> right -> left = temp -> left;
  free (temp);
  return list;
}


struct el_list* pop_from_position (struct el_list *list, int position){
  return delete (list, seek_position (list, position));
}


struct el_list* pop_value (struct el_list *list, int value){
  return delete (list, seek_value (list, value));
}


//first element is printed as first
void print_from_beginning (struct el_list *list){
    printf ("\nTWOJA LISTA OD POCZATKU:\n");
    if ( list != NULL ){
      struct el_list *temp = list;
      printf ("%d\n", temp->x);
      temp = temp -> right;
      while ( temp != list ){
        printf ("%d\n", temp->x);
        temp = temp -> right;
      }
    }
}


//first element is printed as last, last element (element before first element) is printed as first
void print_from_end (struct el_list *list){
    printf ("\nTWOJA LISTA OD KONCA:\n");
    if ( list != NULL ) {
      struct el_list *temp = list -> left;
      while ( temp != list ){
        printf ("%d\n", temp->x);
        temp = temp -> left;
      }
      printf ("%d\n", temp->x);
    }
}


//function return position of wanted element or 0 when element doesn't exist
int seek_element_in_list (struct el_list *list, int value){
  if ( list == NULL )  return 0;
  if ( list->x == value )  return 1;
  struct el_list* temp = list -> right;
  int position = 2;
  while ( temp != list  ){
    if ( temp->x == value )  break;
    temp = temp -> right;
    position++;
  }
  return temp == list ? 0 : position;
}


void delete_list (struct el_list *list){
    if ( list == NULL )  return;
    struct el_list *temp = list->right;
    while ( temp != list ){
      temp = temp -> right;
      free (temp->left);
    }
    free (temp);
}
