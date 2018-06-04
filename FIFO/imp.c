#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


struct FIFO* create_empty_FIFO (){
  struct FIFO *queue = (struct FIFO*)malloc(sizeof(struct FIFO));
  queue -> begin = NULL;
  queue -> end = NULL;
  return queue;
}

struct el_FIFO* create_new_el_FIFO ( int value ){
  struct el_FIFO *new_el_FIFO = (struct el_FIFO*)malloc(sizeof(struct el_FIFO));
  new_el_FIFO -> x = value;
  new_el_FIFO -> next = NULL;
  return new_el_FIFO;
}

struct FIFO* push_back ( struct FIFO *queue, int value ){
  struct el_FIFO *new_el_FIFO = create_new_el_FIFO ( value );

  if ( queue -> begin == NULL ){
    queue -> begin = new_el_FIFO;
    queue -> end = new_el_FIFO;
  }
  else {
    queue -> end -> next = new_el_FIFO;
    queue -> end = new_el_FIFO;
  }
  return queue;
}

struct FIFO* pop_front ( struct FIFO *queue ){
  if ( queue -> begin ==  NULL )  return queue;

  struct el_FIFO *temp = queue -> begin;
  queue -> begin = queue -> begin -> next;
  if ( queue -> begin == NULL )  queue -> end = NULL;
  free (temp);
  return queue;
}

struct FIFO* delete_FIFO ( struct FIFO *queue ){
  while ( queue -> begin != NULL )  queue = pop_front ( queue );
  return queue;
}

struct FIFO* print_FIFO ( struct FIFO *queue ){
    printf ( "\n\nTWOJA KOLEJKA:\n" );
    if ( queue->begin == NULL )  return queue;

    struct FIFO *helper_queue = create_empty_FIFO ();
    do {
        printf ( "%d\n", queue -> begin -> x );
        helper_queue = push_back ( helper_queue, queue->begin->x );
        queue = pop_front ( queue );
    } while ( queue->begin != NULL );
    queue -> begin = helper_queue -> begin;
    queue -> end = helper_queue -> end;
    free (helper_queue);
    return queue;
}
