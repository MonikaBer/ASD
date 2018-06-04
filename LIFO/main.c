#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


int main() {
  struct el_LIFO *top_LIFO = NULL;
  int choice, value;

  do {
    printf ( "\n............................................................\n" );
    printf ( "[1]-Tworz nowy stos pusty\n" );
    printf ( "[2]-Poloz element na stos\n" );
    printf ( "[3]-Zdejmij element ze stosu\n" );
    printf ( "[4]-Pokaz wierzcholek stosu\n" );
    printf ( "[5]-Wyswietl stos\n" );
    printf ( "[6]-Koniec programu\n" );
    printf ( "Twoj wybor: " );
    scanf("%d", &choice);
    switch (choice){
      case 1:
        top_LIFO = empty_LIFO ( top_LIFO );
        break;
      case 2:
        printf("Podaj element: ");
        scanf("%d", &value);
        top_LIFO = push ( top_LIFO, value );
        printf("\nDODANO ELEMENT %d\n\n", top_LIFO -> x);
        break;
      case 3:
        if ( top_LIFO != NULL )  printf ( "\nUSUNIETO ELEMENT %d\n", top_LIFO -> x );
        top_LIFO = pop ( top_LIFO );
        break;
      case 4:
        if ( print_top (top_LIFO) )  printf( "STOS NIE JEST PUSTY\n" );
        else  printf( "STOS JEST PUSTY\n" );
        break;
      case 5:
        top_LIFO = print_LIFO ( top_LIFO );
        break;
      case 6:
        top_LIFO = empty_LIFO ( top_LIFO );
        break;
      default:
        printf ("Nieprawidlowy wybor!\n");
        break;
    }
  } while (choice != 6);

  return 0;
}
