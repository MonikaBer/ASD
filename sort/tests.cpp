#include <iostream>
#include <cassert>
#include "dec.h"
using namespace std;

 int if_sort ( int *t, int n ) {
  for ( int i = 1; i < n; i++ ) {
    if ( t[i-1] > t[i] )
      return 0;
  }
  return 1;
}


void test1() {
  int b, i, s;

  int t1[10] = { 10, 3, 5, 2, 1, 7, 12, 0, 11, 4 };
  bubble_sort ( t1, 10 );
  b = if_sort ( t1, 10 );

  int t2[10] = { 10, 3, 5, 2, 1, 7, 12, 0, 11, 4 };
  insert_sort( t2, 10 );
  i = if_sort ( t2, 10 );

  int t3[10] = { 10, 3, 5, 2, 1, 7, 12, 0, 11, 4 };
  select_sort( t3, 10 );
  s = if_sort ( t3, 10 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

void test2() {
  int b, i, s;

  int t1[11] = { 13, 3, 1, 12, 0, 5, 7, 6, 42, 33, 77 };
  bubble_sort ( t1, 11 );
  b = if_sort ( t1, 11 );

  int t2[11] = { 13, 3, 1, 12, 0, 5, 7, 6, 42, 33, 77 };
  insert_sort( t2, 11 );
  i = if_sort ( t2, 11 );

  int t3[11] = { 13, 3, 1, 12, 0, 5, 7, 6, 42, 33, 77 };
  select_sort( t3, 11 );
  s = if_sort ( t3, 11 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

void test3() {
  int b, i, s;

  int t1[1] = { 0 };
  bubble_sort ( t1, 1 );
  b = if_sort ( t1, 1 );

  int t2[1] = { 0 };
  insert_sort( t2, 1 );
  i = if_sort ( t2, 1 );

  int t3[1] = { 0 };
  select_sort( t3, 1 );
  s = if_sort ( t3, 1 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

void test4() {
  int b, i, s;

  int t1[10] = { 70, 23, 5, 1, 7, 0, 100, 33, 33, 55 };
  bubble_sort ( t1, 10 );
  b = if_sort ( t1, 10 );

  int t2[10] = { 70, 23, 5, 1, 7, 0, 100, 33, 33, 55 };
  insert_sort( t2, 10 );
  i = if_sort ( t2, 10 );

  int t3[10] = { 70, 23, 5, 1, 7, 0, 100, 33, 33, 55 };
  select_sort( t3, 10 );
  s = if_sort ( t3, 10 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

void test5() {
  int b, i, s;

  int t1[11] = { 33, 33, 33, 1, 1, 1, 1, 1, 1, 1, 3 };
  bubble_sort ( t1, 11 );
  b = if_sort ( t1, 11 );

  int t2[11] = { 33, 33, 33, 1, 1, 1, 1, 1, 1, 1, 3 };
  insert_sort( t2, 11 );
  i = if_sort ( t2, 11 );

  int t3[11] = { 33, 33, 33, 1, 1, 1, 1, 1, 1, 1, 3 };
  select_sort( t3, 11 );
  s = if_sort ( t3, 11 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

void test6() {
  int b, i, s;

  int t1[10] = { 4, 4, 4, 5, 7, 2, 3, 6, 0, 0 };
  bubble_sort ( t1, 10 );
  b = if_sort ( t1, 10 );

  int t2[10] = { 4, 4, 4, 5, 7, 2, 3, 6, 0, 0 };
  insert_sort( t2, 10 );
  i = if_sort ( t2, 10 );

  int t3[10] = { 4, 4, 4, 5, 7, 2, 3, 6, 0, 0 };
  select_sort( t3, 10 );
  s = if_sort ( t3, 10 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

void test7() {
  int b, i, s;

  int t1[11] = { 0, -1, 3, -2, -5, -5, 2, 10 -100, 0, 1 };
  bubble_sort ( t1, 11 );
  b = if_sort ( t1, 11 );

  int t2[11] = { 0, -1, 3, -2, -5, -5, 2, 10 -100, 0, 1 };
  insert_sort( t2, 11 );
  i = if_sort ( t2, 11 );

  int t3[11] = { 0, -1, 3, -2, -5, -5, 2, 10 -100, 0, 1 };
  select_sort( t3, 11 );
  s = if_sort ( t3, 11 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

void test8() {
  int b, i, s;

  int t1[2] = { 0, -1 };
  bubble_sort ( t1, 2 );
  b = if_sort ( t1, 2 );

  int t2[2] = { 0, -1 };
  insert_sort( t2, 2 );
  i = if_sort ( t2, 2 );

  int t3[2] = { 0, -1 };
  select_sort( t3, 2 );
  s = if_sort ( t3, 2 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

void test9() {
  int b, i, s;

  int t1[3] = { -2, -7, -10 };
  bubble_sort ( t1, 3 );
  b = if_sort ( t1, 3 );

  int t2[3] = { -2, -7, -10 };
  insert_sort( t2, 3 );
  i = if_sort ( t2, 3 );

  int t3[3] = { -2, -7, -10 };
  select_sort( t3, 3 );
  s = if_sort ( t3, 3 );

  assert ( b == 1 );
  assert ( i == 1 );
  assert ( s == 1 );
}

int main() {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}
