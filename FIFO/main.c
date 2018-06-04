#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


int main() {
  struct FIFO *queue = create_empty_FIFO ();
  int choice, value;
  do {
    printf ( "\n...........................................................\n" );
    printf ( "[1]-Stworzenie pustej kolejki\n" );
    printf ( "[2]-Dolaczenie elementu do kolejki\n" );
    printf ( "[3]-Usuniecie elementu z kolejki\n" );
    printf ( "[4]-Wydruk kolejki\n" );
    printf ( "[5]-Koniec programu\n" );
    printf ( "Twoj wybor: " );
    scanf ( "%d", &choice );
    switch ( choice ){
      case 1:
        queue = delete_FIFO ( queue );
        break;
      case 2:
        printf ( "Podaj element: ");
        scanf ( "%d", &value );
        queue = push_back ( queue, value );
        printf ( "\nDODANO ELEMENT %d DO KOLEJKI\n\n", queue -> end -> x );
        break;
      case 3:
        if ( queue->begin != NULL )
          printf ( "\nUSUNIETO ELEMENT %d Z KOLEJKI\n\n", queue -> begin -> x );
        queue = pop_front ( queue );
        break;
      case 4:
        queue = print_FIFO ( queue );
        break;
      case 5:
        queue = delete_FIFO ( queue );
        free (queue);
        break;
      default:
        printf ( "\nNieprawidlowy wybor!\n" );
        break;
    }
  }
  while ( choice != 5 );

  return 0;
}
