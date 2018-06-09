#include <stdio.h>
#include <stdlib.h>
#include "dec.h"

struct twoway_list* create_list(){
  struct twoway_list *list = constructor_of_empty_list();
  push_on_position (list, 1, 1);
  push_on_position (list, 2, 2);
  push_on_position (list, 3, 3);
  push_on_position (list, 4, 4);
  push_on_position (list, 5, 5);
  push_on_position (list, 6, 6);
  push_on_position (list, 7, 7);
  push_on_position (list, 8, 8);
  push_on_position (list, 9, 9);
  push_on_position (list, 10, 10);
  return list;
}


void test_push_on_position(){
  struct twoway_list *list = create_list();
  push_on_position (list, 1, 0);
  push_on_position (list, 1, -1);
  push_on_position (list, 1, -2);
  push_on_position (list, 5, 1);
  push_on_position (list, 6, 2);
  push_on_position (list, 13, 11);
  push_on_position (list, 14, 15);
  push_on_position (list, 15, 17);
  push_on_position (list, 16, 19);
  push_on_position (list, 17, 21);
  push_on_position (list, 18, 23);
  push_on_position (list, 100, 50);
  print_from_beginning (list);
  print_from_end (list);
  delete_list (list);
}


void test_push_after_value(){
  struct twoway_list *list = create_list();
  push_after_value (list, 20, -1);
  push_after_value (list, 13, 1);
  push_after_value (list, 14, 13);
  push_after_value (list, 15, 2);
  push_after_value (list, 7, 5);
  push_after_value (list, 0, 6);
  push_after_value (list, 17, 10);
  push_after_value (list, 2, 1);
  push_after_value (list, 30, 20);
  push_after_value (list, 1, -2);
  push_after_value (list, 2, 32);
  push_after_value (list, 40, 1);
  push_after_value (list, 3, 2);
  print_from_beginning (list);
  print_from_end (list);
  delete_list (list);
}


void test_pop_from_position(){
  struct twoway_list *list = create_list();
  pop_from_position (list, -1);
  pop_from_position (list, 0);
  pop_from_position (list, 11);
  pop_from_position (list, 1);
  pop_from_position (list, 1);
  pop_from_position (list, 8);
  pop_from_position (list, 9);
  pop_from_position (list, 9);
  pop_from_position (list, 10);
  pop_from_position (list, 20);
  pop_from_position (list, 3);
  pop_from_position (list, 5);
  print_from_beginning (list);
  print_from_end (list);
  delete_list (list);
}


void test_pop_value(){
  struct twoway_list *list = create_list();
  pop_value (list, 0);
  pop_value (list, -1);
  pop_value (list, -2);
  pop_value (list, 11);
  pop_value (list, 10);
  pop_value (list, 10);
  pop_value (list, 10);
  pop_value (list, 1);
  pop_value (list, 1);
  pop_value (list, 5);
  pop_value (list, 8);
  print_from_beginning (list);
  print_from_end (list);
  delete_list (list);
}


void test_seek_element_in_list(){
  struct twoway_list *list = create_list();
  push_after_value (list, 1, 10);
  push_after_value (list, 2, 10);
  push_after_value (list, 5, 5);
  push_after_value (list, 5, 5);
  int position;
  position = seek_element_in_list (list, 0);
  printf ("%d\n", position);
  position = seek_element_in_list (list, -1);
  printf ("%d\n", position);
  position = seek_element_in_list (list, -2);
  printf ("%d\n", position);
  position = seek_element_in_list (list, 1);
  printf ("%d\n", position);
  position = seek_element_in_list (list, 5);
  printf ("%d\n", position);
  position = seek_element_in_list (list, 5);
  printf ("%d\n", position);
  position = seek_element_in_list (list, 5);
  printf ("%d\n", position);
  position = seek_element_in_list (list, 2);
  printf ("%d\n", position);
  position = seek_element_in_list (list, 10);
  printf ("%d\n", position);
  position = seek_element_in_list (list, 12);
  printf ("%d\n", position);
  delete_list (list);
}


void test_push_and_pop(){
  struct twoway_list *list = create_list();
  push_on_position (list, 12, 5);
  pop_from_position (list, 5);
  push_after_value (list, 13, 4);
  pop_value (list, 13);
  push_on_position (list, 100, 5);
  print_from_beginning (list);
  delete_list (list);
}


int main(){
  printf ("TEST_PUSH_ON_POSITION:\n");
  test_push_on_position();
  printf ("........................................\n\n");
  printf ("TEST_PUSH_AFTER_VALUE:\n");
  test_push_after_value();
  printf ("........................................\n\n");
  printf ("TEST_POP_FROM_POSITION:\n");
  test_pop_from_position();
  printf ("........................................\n\n");
  printf ("TEST_POP_VALUE:\n");
  test_pop_value();
  printf ("........................................\n\n");
  printf ("TEST_SEEK_ELEMENT_IN_LIST:\n");
  test_seek_element_in_list();
  printf ("........................................\n\n");
  printf ("TEST_PUSH_AND_POP:\n");
  test_push_and_pop();
  printf ("........................................\n\n");

  return 0;
}
