#ifndef DEC_H
#define DEC_H

int get_size_array();
void get_data ( int *array, int size_array );
void print_array ( int *array, int size_array );

void swap ( int *a, int *b );
void heapify ( int *array, int size_heap, int nr );
void heapsort ( int *array, int size_heap );

#endif