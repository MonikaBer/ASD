#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dec.h"

struct el_LIFO* add_elements ( struct el_LIFO* top_LIFO, int first_added_element, int quantity_of_callings ){
  int i = first_added_element;
  quantity_of_callings += i;
  while ( i < quantity_of_callings ){
    top_LIFO = push ( top_LIFO, i );
    assert ( top_LIFO->x == i );
    i++;
  }
  return top_LIFO;
}

struct el_LIFO* delete_elements ( struct el_LIFO* top_LIFO, int quantity_of_callings ){
  int i = 0, value;
  while ( i < quantity_of_callings ){
    if ( top_LIFO != NULL )  value = top_LIFO->x;
    top_LIFO = pop ( top_LIFO );
    if ( top_LIFO != NULL )   assert ( top_LIFO->x == value-1 );
    i++;
  }
  return top_LIFO;
}


void test1() {
  struct el_LIFO *top_LIFO = NULL;
  top_LIFO = add_elements ( top_LIFO, 1, 7 );
  top_LIFO = delete_elements ( top_LIFO, 6 );
  top_LIFO = add_elements ( top_LIFO, 2, 1 );
  top_LIFO = delete_elements ( top_LIFO, 1 );
  top_LIFO = add_elements ( top_LIFO, 2, 3 );
  top_LIFO = delete_elements ( top_LIFO, 1 );
  top_LIFO = add_elements ( top_LIFO, 4, 1 );
  top_LIFO = empty_LIFO ( top_LIFO );
  assert ( top_LIFO == NULL );

  top_LIFO = add_elements ( top_LIFO, 1, 7 );
  top_LIFO = delete_elements ( top_LIFO, 7 );
  assert ( top_LIFO == NULL );
  top_LIFO = delete_elements ( top_LIFO, 3 );
  assert ( top_LIFO == NULL );

  top_LIFO = add_elements ( top_LIFO, 1, 1 );
  assert ( top_LIFO->x == 1 );

  top_LIFO = empty_LIFO ( top_LIFO );
  assert ( top_LIFO == NULL );
}

void test2(){
  struct el_LIFO *top_LIFO = NULL;
  top_LIFO = empty_LIFO ( top_LIFO );
  assert ( top_LIFO == NULL );

  top_LIFO = add_elements ( top_LIFO, 1, 7 );
  top_LIFO = delete_elements ( top_LIFO, 6 );
  top_LIFO = add_elements ( top_LIFO, 2, 1 );
  top_LIFO = delete_elements ( top_LIFO, 1 );
  top_LIFO = add_elements ( top_LIFO, 2, 3 );
  top_LIFO = delete_elements ( top_LIFO, 1 );
  top_LIFO = add_elements ( top_LIFO, 4, 1 );

  top_LIFO = empty_LIFO ( top_LIFO );
  assert ( top_LIFO == NULL );
}


int main(){
  printf ( "\nTEST_1\n\n" );
  test1();
  printf ( "\nTEST_2\n\n" );
  test2();

  return 0;
}
