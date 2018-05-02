#include <iostream>
#include <random>
#include <cassert>
#include "dec.h"
using namespace std;

void array_initialization ( int *t, int n, int from, int to );
void is_array_sorted_into_even_and_odd_numbers ( int *t, int n, int result );
void are_even_numbers_sorted ( int *t, int result );
void print_sorted_even_numbers ( int *t, int result );
void test ( int n, int from, int to, int r );


void test1(){

  test ( 50, -100, 100, 25 );
}

void test2(){

  test ( 140, -200, 200, 35 );
}

void test3(){

  test ( 1, -100, 100, 30 );
}

void test4(){

  test ( 7, 1, 5, 2 );
}

void test5(){

  test ( 100, 0, 100, 25 );
}

void test6(){

  test ( 50, -100, 100, 30 );
}

void test7(){

  test ( 1000, -100, 100, 40 );
}

void test8(){

  test ( 2000, -1000, 1000, 250 );
}

void test9(){

  test ( 100, -10, -1, 2 );
}

void test10(){

  test ( 100, -10, -1, 1 );
}

void test11(){

  test ( 50, 0, 100, 29 );
}

void test12(){

  test ( 70, -100, 100, 24 );
}

void test13(){

  test ( 100, 0, 150, 20 );
}

void test14(){

  test ( 50, 10, 110, 9 );
}

void test15(){

  test ( 14, 0, 50, 5 );
}

void test16(){

  test ( 10, 0, 15, 4 );
}

void test17(){

  test ( 20, 1, 100, 20 );
}

void test18(){

  test ( 40, 0, 300, 30 );
}

void test19(){

  test ( 9, 0, 20, 3 );
}

void test20(){

  test ( 10, 1, 30, 15 );
}


int main(){

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();
  test12();
  test13();
  test14();
  test15();
  test16();
  test17();
  test18();
  test19();
  test20();

  return 0;
}



void array_initialization ( int *t, int n, int from, int to ){

    random_device generator;
    uniform_int_distribution <int> distribution ( from, to );

    for ( int i = 0; i < n; i++ )
        t[i] = distribution (generator);
}


void is_array_sorted_into_even_and_odd_numbers ( int *t, int n, int result ){

  int i = 0;
  while ( i <= result ){
    assert ( t[i] % 2 == 0 );
    i++;
  }
  while ( i < n ){
    assert ( t[i] % 2 != 0);
    i++;
  }
}


void are_even_numbers_sorted ( int *t, int result ){

  for ( int i = 0; i < result; i++ )
      assert ( t[i] <= t[i+1] );
}


void print_sorted_even_numbers ( int *t, int result ){

  cerr << "\nParzyste po qs:\n";
  for ( int i = 0; i <= result; i++ )
    cerr << t[i] << "  ";

  cerr << "\n\n";
}


void test ( int n, int from, int to, int r ){

    int t[n];
    int result;
    array_initialization ( t, n, from, to );

    result = sort01 ( t, n );
    is_array_sorted_into_even_and_odd_numbers ( t, n, result );
    initialization_and_quick_sort_call ( t, result );
    are_even_numbers_sorted ( t, result );
    print_sorted_even_numbers ( t, result );

    cerr << "\n.............\n";
}
