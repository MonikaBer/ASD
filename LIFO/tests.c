#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dec.h"


struct el_LIFO* create_LIFO ( struct el_LIFO *top_LIFO ) {
  printf ( "\n\nDODAWANE ELEMENTY: 1,2,3,4,5,6,7\n" );
  top_LIFO = push ( top_LIFO, 1 );
  assert ( top_LIFO->x == 1 );
  top_LIFO = push ( top_LIFO, 2 );
  assert ( top_LIFO->x == 2 );
  top_LIFO = push ( top_LIFO, 3 );
  assert ( top_LIFO->x == 3 );
  top_LIFO = push ( top_LIFO, 4 );
  assert ( top_LIFO->x == 4 );
  top_LIFO = push ( top_LIFO, 5 );
  assert ( top_LIFO->x == 5 );
  top_LIFO = push ( top_LIFO, 6 );
  assert ( top_LIFO->x == 6 );
  top_LIFO = push ( top_LIFO, 7 );
  assert ( top_LIFO->x == 7 );

  return top_LIFO;
}


void test() {
  struct el_LIFO *top_LIFO = NULL;
  top_LIFO = create_LIFO ( top_LIFO );
  top_LIFO = print_LIFO ( top_LIFO );
  top_LIFO = print_LIFO ( top_LIFO );
  top_LIFO = print_LIFO ( top_LIFO );

  printf ( "\n\n" );
  int i = 0;
  while ( i < 6 ) {
      top_LIFO = pop ( top_LIFO );
      i++;
  }

  top_LIFO = print_LIFO ( top_LIFO );
  assert ( top_LIFO->x == 1 );
  top_LIFO = push ( top_LIFO, 1 );
  assert ( top_LIFO->x == 1 );
  top_LIFO = pop ( top_LIFO );
  assert ( top_LIFO->x == 1 );
  top_LIFO = push ( top_LIFO, 2 );
  assert ( top_LIFO->x == 2 );
  top_LIFO = push ( top_LIFO, 5 );
  assert ( top_LIFO->x == 5 );
  top_LIFO = push ( top_LIFO, 4 );
  assert ( top_LIFO->x == 4 );
  top_LIFO = pop ( top_LIFO );
  assert ( top_LIFO->x == 5 );
  top_LIFO = push ( top_LIFO, 8 );
  assert ( top_LIFO->x == 8 );
  top_LIFO = print_LIFO ( top_LIFO );
  top_LIFO = print_LIFO ( top_LIFO );
  top_LIFO = print_LIFO ( top_LIFO );

  top_LIFO = empty_LIFO ( top_LIFO );
  top_LIFO = print_LIFO ( top_LIFO );
  top_LIFO = print_LIFO ( top_LIFO );

  top_LIFO = push ( top_LIFO, 1 );
  assert ( top_LIFO->x == 1 );
  top_LIFO = push ( top_LIFO, 2 );
  assert ( top_LIFO->x == 2 );
  top_LIFO = push ( top_LIFO, 3 );
  assert ( top_LIFO->x == 3 );
  top_LIFO = push ( top_LIFO, 4 );
  assert ( top_LIFO->x == 4 );
  top_LIFO = push ( top_LIFO, 5 );
  assert ( top_LIFO->x == 5 );
  top_LIFO = push ( top_LIFO, 6 );
  assert ( top_LIFO->x == 6 );
  top_LIFO = push ( top_LIFO, 7 );
  assert ( top_LIFO->x == 7 );

  i = 0;
  while ( i < 7 ) {
      top_LIFO = pop ( top_LIFO );
      i++;
  }
  assert ( top_LIFO == NULL );
  top_LIFO = pop ( top_LIFO );
  top_LIFO = pop ( top_LIFO );
  top_LIFO = pop ( top_LIFO );
  assert ( top_LIFO == NULL );
  top_LIFO = push ( top_LIFO, 5 );
  assert ( top_LIFO->x == 5 );

  top_LIFO = empty_LIFO ( top_LIFO );
}


int main(){
  printf ( "\nTEST\n\n" );
  test();

  return 0;
}
