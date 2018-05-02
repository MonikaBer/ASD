#ifndef DEC_H
#define DEC_H

struct point {
  float x;
  float y;
};

void data ( point *points, int n );
void sort012 ( point *points, int n, int &in1, int &in2, int &in3 );
void print ( point *points, int n, int &in1, int &in2, int &in3 );

#endif
