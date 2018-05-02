#ifndef DEC_H
#define DEC_H

void data ( int *t, int n, int &r );
int sort01 ( int *t, int n );
int partition ( int *t, int left, int right );
void quick_sort ( int *t, int left, int right );
void initialization_and_quick_sort_call ( int *t, int result );
int find_range ( int *t, int result, int r );
void print ( int beginning_of_final_range, int r );

#endif
