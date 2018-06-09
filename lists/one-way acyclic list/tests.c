#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dec.h"

struct oneway_list* create_list(){
  struct oneway_list *list = constructor_of_empty_list();
  list = push_on_position (list, 1, 1);
  list = push_on_position (list, 2, 2);
  list = push_on_position (list, 3, 3);
  list = push_on_position (list, 4, 4);
  list = push_on_position (list, 5, 5);
  list = push_on_position (list, 6, 6);
  list = push_on_position (list, 7, 7);
  list = push_on_position (list, 8, 8);
  list = push_on_position (list, 9, 9);
  list = push_on_position (list, 10, 10);
  return list;
}


void test_push_on_position(){
  struct oneway_list *list = create_list();
  list = push_on_position (list, 1, 0);
  list = push_on_position (list, 1, -1);
  list = push_on_position (list, 1, -2);
  list = push_on_position (list, 5, 1);
  list = push_on_position (list, 6, 2);
  list = push_on_position (list, 13, 11);
  list = push_on_position (list, 14, 15);
  list = push_on_position (list, 15, 17);
  list = push_on_position (list, 16, 19);
  list = push_on_position (list, 17, 21);
  list = push_on_position (list, 18, 23);
  list = push_on_position (list, 100, 50);
  print_from_beginning (list);
  delete_list (list);
  list = constructor_of_empty_list();
  print_from_beginning (list);
  delete_list (list);
}


void test_push_after_value(){
  struct oneway_list *list = create_list();
  list = push_after_value (list, 20, -1);
  list = push_after_value (list, 13, 1);
  list = push_after_value (list, 14, 13);
  list = push_after_value (list, 15, 2);
  list = push_after_value (list, 7, 5);
  list = push_after_value (list, 0, 6);
  list = push_after_value (list, 17, 10);
  list = push_after_value (list, 2, 1);
  list = push_after_value (list, 30, 20);
  list = push_after_value (list, 1, -2);
  list = push_after_value (list, 2, 32);
  list = push_after_value (list, 40, 1);
  list = push_after_value (list, 3, 2);
  print_from_beginning (list);
  delete_list (list);
}


void test_pop_from_position(){
  struct oneway_list *list = create_list();
  list = pop_from_position (list, -1);
  list = pop_from_position (list, 0);
  list = pop_from_position (list, 11);
  list = pop_from_position (list, 1);
  list = pop_from_position (list, 1);
  list = pop_from_position (list, 8);
  list = pop_from_position (list, 9);
  list = pop_from_position (list, 9);
  list = pop_from_position (list, 10);
  list = pop_from_position (list, 20);
  list = pop_from_position (list, 3);
  list = pop_from_position (list, 5);
  print_from_beginning (list);
  delete_list (list);
}


void test_pop_value(){
  struct oneway_list *list = create_list();
  list = pop_value (list, 0);
  list = pop_value (list, -1);
  list = pop_value (list, -2);
  list = pop_value (list, 11);
  list = pop_value (list, 10);
  list = pop_value (list, 10);
  list = pop_value (list, 10);
  list = pop_value (list, 1);
  list = pop_value (list, 1);
  list = pop_value (list, 5);
  list = pop_value (list, 8);
  print_from_beginning (list);
  delete_list (list);
}


void test_seek_element_in_list(){
  struct oneway_list *list = create_list();
  list = push_after_value (list, 1, 10);
  list = push_after_value (list, 2, 10);
  list = push_after_value (list, 5, 5);
  list = push_after_value (list, 5, 5);
  list = push_on_position (list, 20, 15);
  int position;
  position = seek_element_in_list (list, 0);
  assert ( position == 0 );
  position = seek_element_in_list (list, -1);
  assert ( position == 0 );
  position = seek_element_in_list (list, -2);
  assert ( position == 0 );
  position = seek_element_in_list (list, 1);
  assert ( position == 1 );
  position = seek_element_in_list (list, 5);
  assert ( position == 5 );
  position = seek_element_in_list (list, 5);
  assert ( position == 5 );
  position = seek_element_in_list (list, 5);
  assert ( position == 5 );
  position = seek_element_in_list (list, 2);
  assert ( position == 2 );
  position = seek_element_in_list (list, 10);
  assert ( position == 12 );
  position = seek_element_in_list (list, 12);
  assert ( position == 0 );
  position = seek_element_in_list (list, 20);
  assert ( position == 15 );
  print_from_beginning (list);
  delete_list (list);
}


void test_push_and_pop(){
  struct oneway_list *list = create_list();
  list = push_on_position (list, 12, 5);
  list = pop_from_position (list, 5);
  list = push_after_value (list, 13, 4);
  list = pop_value (list, 13);
  list = push_on_position (list, 100, 5);
  list = push_after_value (list, 2, 2);
  list = push_after_value (list, 2, 2);
  list = pop_value (list, 2);
  list = pop_from_position (list, 4);
  list = push_on_position (list, 50, 0);
  list = push_after_value (list, 70, 50);
  print_from_beginning (list);
  delete_list (list);
}


void another_tests(){
  struct oneway_list *list = constructor_of_empty_list();
  list = push_on_position (list, 1, 0);
  print_from_beginning (list);
  list = pop_from_position (list, 1);
  print_from_beginning (list);
  list = pop_from_position (list, 1);
  list = pop_value (list, 1);
  list = pop_value (list, 2);
  list = pop_from_position (list, 1);
  list = pop_from_position (list, 2);
  list = push_on_position (list, 1, 2);
  print_from_beginning (list);
  list = pop_value (list, 2);
  list = pop_value (list, 1);
  list = pop_value (list, 1);
  list = pop_value (list, 1);
  print_from_beginning (list);
  delete_list (list);
  list = constructor_of_empty_list();
  print_from_beginning (list);
  list = push_on_position (list, 1, 0);
  list = push_on_position (list, 2, 2);
  list = push_on_position (list, 3, 3);
  print_from_beginning (list);
  list = pop_value (list, 2);
  print_from_beginning (list);
  list = pop_value (list, 3);
  print_from_beginning (list);
  list = push_on_position (list, 2, 5);
  list = push_on_position (list, 3, 8);
  print_from_beginning (list);
  list = pop_value (list, 1);
  assert (list->begin->x == 2);
  list = pop_value (list, 2);
  assert (list->begin->x == 3);
  list = pop_value (list, 3);
  assert (list->begin == NULL && list->end == NULL);
  print_from_beginning (list);
  delete_list (list);
  list = constructor_of_empty_list();
  delete_list (list);
  list = constructor_of_empty_list();
  print_from_beginning (list);
  list = push_on_position (list, 2, 5);
  list = push_on_position (list, 3, 8);
  print_from_beginning (list);
  assert (list->begin->x == 2);
  list = pop_value (list, 2);
  assert (list->begin->x == 3);
  list = pop_value (list, 3);
  assert (list->begin == NULL && list->end == NULL);
  print_from_beginning (list);
  list = push_on_position (list, 2, 5);
  list = push_on_position (list, 3, 8);
  print_from_beginning (list);
  delete_list (list);
  list = constructor_of_empty_list();
  print_from_beginning (list);
  list = push_on_position (list, 1, 5);
  list = push_on_position (list, 2, 5);
  list = push_on_position (list, 3, 8);
  print_from_beginning (list);
  list = pop_value (list, 2);
  list = pop_value (list, 3);
  print_from_beginning (list);
  list = push_on_position (list, 2, 1);
  list = push_on_position (list, 3, 1);
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
  printf ("TEST_ANOTHER_TESTS:\n");
  another_tests();
  printf ("........................................\n\n");

  return 0;
}
