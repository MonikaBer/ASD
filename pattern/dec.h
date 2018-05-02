#ifndef DEC_H
#define DEC_H

void data ( char *text, char *pattern );
void naive ( char *text, char *pattern, int *result, int &quantity_of_results );
int horner ( int * t, int length_of_pattern );
void kr ( char *text, char *pattern, int *result, int &quantity_of_results );
void print ( int *result, int &quantity_of_results );

#endif
