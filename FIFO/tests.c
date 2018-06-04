#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dec.h"


void test() {
  struct FIFO *queue = create_empty_FIFO ();

  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
  queue = push_back ( queue, 1 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 1 );
  queue = push_back ( queue, 2 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 2 );
  queue = push_back ( queue, 3 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 3 );
  queue = push_back ( queue, 4 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 4 );
  queue = push_back ( queue, 5 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 5 );

  queue = pop_front ( queue );
  assert ( queue->begin->x == 2 );
  assert ( queue->end->x == 5 );
  queue = pop_front ( queue );
  assert ( queue->begin->x == 3 );
  assert ( queue->end->x == 5 );
  queue = pop_front ( queue );
  assert ( queue->begin->x == 4 );
  assert ( queue->end->x == 5 );
  queue = pop_front ( queue );
  assert ( queue->begin->x == 5 );
  assert ( queue->end->x == 5 );
  queue = pop_front ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
  queue = pop_front ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
  queue = pop_front ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );


  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
  queue = push_back ( queue, 1 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 1 );
  queue = push_back ( queue, 2 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 2 );
  queue = push_back ( queue, 3 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 3 );
  queue = push_back ( queue, 4 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 4 );
  queue = push_back ( queue, 5 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 5 );

  queue = pop_front ( queue );
  assert ( queue->begin->x == 2 );
  assert ( queue->end->x == 5 );
  queue = pop_front ( queue );
  assert ( queue->begin->x == 3 );
  assert ( queue->end->x == 5 );
  queue = pop_front ( queue );
  assert ( queue->begin->x == 4 );
  assert ( queue->end->x == 5 );
  queue = pop_front ( queue );
  assert ( queue->begin->x == 5 );
  assert ( queue->end->x == 5 );

  queue = push_back ( queue, 6 );
  assert ( queue->begin->x == 5 );
  assert ( queue->end->x == 6 );
  queue = push_back ( queue, 7 );
  assert ( queue->begin->x == 5 );
  assert ( queue->end->x == 7 );
  queue = push_back ( queue, 8 );
  assert ( queue->begin->x == 5 );
  assert ( queue->end->x == 8 );

  queue = pop_front ( queue );
  assert ( queue->begin->x == 6 );
  assert ( queue->end->x == 8 );

  queue = push_back ( queue, 9 );
  assert ( queue->begin->x == 6 );
  assert ( queue->end->x == 9 );
  queue = push_back ( queue, 10 );
  assert ( queue->begin->x == 6 );
  assert ( queue->end->x == 10 );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );

  queue = push_back ( queue, 1 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 1 );
  queue = push_back ( queue, 2 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 2 );
  queue = push_back ( queue, 3 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 3 );
  queue = pop_front ( queue );
  assert ( queue->begin->x == 2 );
  assert ( queue->end->x == 3 );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );

  queue = push_back ( queue, 1 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 1 );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );

  queue = push_back ( queue, 1 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 1 );
  queue = push_back ( queue, 2 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 2 );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );

  queue = push_back ( queue, 1 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 1 );
  queue = push_back ( queue, 2 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 2 );
  queue = push_back ( queue, 3 );
  assert ( queue->begin->x == 1 );
  assert ( queue->end->x == 3 );
  queue = pop_front ( queue );
  assert ( queue->begin->x == 2 );
  assert ( queue->end->x == 3 );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );
  queue = delete_FIFO ( queue );
  assert ( queue->begin == NULL );
  assert ( queue->end == NULL );

  free (queue);
}


int main(){
  printf ( "\nTEST\n\n" );
  test();

  return 0;
}
