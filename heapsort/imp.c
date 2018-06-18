#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


int get_size_array(){
    int size_array;
    do {
        printf ("Podaj ilosc elementow: ");
        scanf ("%d", &size_array);
        if ( size_array < 1 )
            printf ("Podales niedodatnia liczbe elementow!\n");
    } while ( size_array < 1 );
    return size_array;
}

void get_data ( int *array, int size_array ){
    printf ("\n\nPodaj te elementy:\n\n");
    int nr;
    for ( nr = 0; nr < size_array; nr++ ) {
        printf ("Podaj %d element: ", nr + 1);
        scanf ( "%d", &array[nr] );
    }
}

void print_array ( int *array, int size_array ){
    printf ("\n\nPosortowane niemalejaco elementy:\n");
    int nr;
    for ( nr = 0; nr < size_array; nr++ )  printf ("%d\n", array[nr]);
    printf ("\n\n\n");
}

void swap ( int *a, int *b ){
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify ( int *array, int size_heap, int nr ){
    int nr_left = 2 * nr + 1;
    int nr_right = 2 * nr + 2;
    int largest = array[nr];

    if ( nr_left <= size_heap-1 ) {
        if (nr_right <= size_heap - 1) {
            if (array[nr_left] > array[nr_right]) {
                if (array[nr_left] > largest) swap( &array[nr_left], &array[nr] );
            } else {
                if (array[nr_right] > largest) swap( &array[nr_right], &array[nr] );
            }
        }
        else {
            if (array[nr_left] > largest) swap(&array[nr_left], &array[nr]);
        }
    }
    else {
        if (nr_right <= size_heap - 1) {
            if (array[nr_right] > largest) swap(&array[nr_right], &array[nr]);
        }
    }
}

void heapsort ( int *array, int size_heap ) {
    int nr = size_heap - 1;
    int saved_number;
    while ( nr > 0 ) {

        while ( (2 * nr + 1) > (size_heap - 1) )   nr--;
        saved_number = nr;

        while (nr != -1) {
            heapify ( array, size_heap, nr );
            nr--;
        }

        nr = 1;
        while (nr != saved_number + 1) {
            heapify (array, size_heap, nr);
            nr++;
        }

        swap ( &array[0], &array[size_heap-1] );
        size_heap--;
        nr = size_heap - 1;
    }
}