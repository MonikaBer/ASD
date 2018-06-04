#include <stdio.h>
#include <stdlib.h>
#include "dec.h"

struct el_LIFO *create_new_el_LIFO ( int value );


struct el_LIFO* empty_LIFO ( struct el_LIFO *top_LIFO ){
  while ( top_LIFO != NULL )  top_LIFO = pop ( top_LIFO );
  return top_LIFO;
}

struct el_LIFO *create_new_el_LIFO ( int value ) {
  struct el_LIFO *new_el_LIFO = (struct el_LIFO*)malloc(sizeof(struct el_LIFO));
  new_el_LIFO -> x = value;
  new_el_LIFO -> next = NULL;
  return new_el_LIFO;
}

struct el_LIFO* push ( struct el_LIFO *top_LIFO, int value ){
  struct el_LIFO *new_el_LIFO = create_new_el_LIFO ( value );
  new_el_LIFO -> next = top_LIFO;
  top_LIFO = new_el_LIFO;
  return top_LIFO;
}

struct el_LIFO* pop ( struct el_LIFO *top_LIFO ){
  if ( top_LIFO == NULL )  return NULL;

  struct el_LIFO *temp = top_LIFO;
  top_LIFO = top_LIFO -> next;
  free (temp);
  return top_LIFO;
}

int print_top ( struct el_LIFO *top_LIFO ){
//wynikiem funkcji jest wartość 0, gdy stos jest pusty i 1 w przeciwnym wypadku
    if ( top_LIFO == NULL )  return 0;
    printf ( "\nWIERZCHOLKIEM STOSU JEST %d\n", top_LIFO -> x );
    return 1;
}

struct el_LIFO* print_LIFO ( struct el_LIFO *top_LIFO ){
    struct el_LIFO *new_top = NULL;

    printf ( "\nTWOJ STOS:\n\n" );
    if ( top_LIFO == NULL )  return top_LIFO;

    do {
      printf ( "%d\n", top_LIFO -> x );
      new_top = push ( new_top, top_LIFO->x );
      top_LIFO = pop ( top_LIFO );
    }
    while ( top_LIFO != NULL );

    do {
      top_LIFO = push ( top_LIFO, new_top->x );
      new_top = pop ( new_top );
    }
    while ( new_top != NULL );

    return top_LIFO;
}
