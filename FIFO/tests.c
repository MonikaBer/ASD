#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dec.h"

struct FIFO* add_elements ( struct FIFO* queue, int first_added_element, int first_element_in_queue, int quantity_of_callings ){
  int i = first_added_element;
  quantity_of_callings += i;
  while ( i < quantity_of_callings ){
    queue = push_back ( queue, i );
    assert ( queue->begin->x == first_element_in_queue );
    assert ( queue->end->x == i );
    i++;
  }
  return queue;
}

struct FIFO* delete_elements ( struct FIFO* queue, int first_element_in_queue, int last_element_in_queue, int quantity_of_callings ){
  int i = 0;
  while ( i < quantity_of_callings ){
    queue = pop_front ( queue );
    if ( queue->begin == NULL )  assert ( queue->end == NULL );
    else {
      first_element_in_queue++;
      assert ( queue->begin->x == first_element_in_queue );
      assert ( queue->end->x == last_element_in_queue );
    }
    i++;
  }
  return queue;
}

void if_empty ( struct FIFO* queue ){
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
}

struct FIFO* delete_FIFO_and_check_if_empty ( struct FIFO *queue ) {
  queue = delete_FIFO ( queue );
  if_empty ( queue );
  return queue;
}


void test1(){
  struct FIFO *queue = create_empty_FIFO();
  if_empty ( queue );

  queue = add_elements ( queue, 1, 1, 5 );
  queue = delete_elements ( queue, 1, 5, 7 );
  if_empty ( queue );

  queue = add_elements ( queue, 1, 1, 5 );
  queue = delete_elements ( queue, 1, 5, 4 );
  queue = add_elements ( queue, 6, 5, 3 );
  queue = delete_elements ( queue, 5, 8, 1 );
  queue = add_elements ( queue, 9, 6, 2 );
  queue = delete_FIFO_and_check_if_empty ( queue );
  queue = delete_FIFO_and_check_if_empty ( queue );
  queue = delete_FIFO_and_check_if_empty ( queue );

  queue = add_elements ( queue, 1, 1, 3 );
  queue = delete_elements ( queue, 1, 3, 1 );
  queue = delete_FIFO_and_check_if_empty ( queue );

  queue = add_elements ( queue, 1, 1, 1 );
  queue = delete_FIFO_and_check_if_empty ( queue );

  queue = add_elements ( queue, 1, 1, 2 );
  queue = delete_FIFO_and_check_if_empty ( queue );

  queue = add_elements ( queue, 1, 1, 3 );
  queue = delete_elements ( queue, 1, 3, 1 );
  queue = delete_FIFO_and_check_if_empty ( queue );
  queue = delete_FIFO_and_check_if_empty ( queue );

  free (queue);
}

void test2(){
  struct FIFO *queue = create_empty_FIFO();
  queue = delete_FIFO_and_check_if_empty ( queue );

  queue = add_elements ( queue, 1, 1, 5 );
  queue = delete_elements ( queue, 1, 5, 7 );
  if_empty ( queue );

  queue = add_elements ( queue, 1, 1, 5 );
  queue = delete_elements ( queue, 1, 5, 4 );
  queue = add_elements ( queue, 6, 5, 3 );
  queue = delete_elements ( queue, 5, 8, 1 );
  queue = add_elements ( queue, 9, 6, 2 );
  queue = delete_FIFO_and_check_if_empty ( queue );
  queue = delete_FIFO_and_check_if_empty ( queue );

  free (queue);
}


int main(){
  printf ( "\nTEST_1\n\n" );
  test1 ();
  printf ( "\nTEST_2\n\n" );
  test2 ();

  return 0;
}
