#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "dec.h"

void if_sorted ( int *array, int size_array ){
    int i = 0;
    for ( ; i < size_array-1; i++ )  assert ( array[i] <= array[i+1] );
}


void test_simple(){
    int size_array = 10;
    int array [10] = { 37, 29, 40, 8, 13, 20, 90, 3, 50, 12 };
    int size_heap = size_array;

    heapsort ( array, size_heap );
    if_sorted ( array, size_array );
    print_array ( array, size_array );
}

void test(){
    srand ( time (NULL) );
    int size_array = rand() % 51;
    int array [size_array];
    int i = 0;
    for ( ; i < size_array; i++ )  array[i] = rand() % 101;
    int size_heap = size_array;

    heapsort ( array, size_heap );
    if_sorted ( array, size_array );
    print_array ( array, size_array );
}


int main(){

    test_simple();
    test();

    return 0;
}