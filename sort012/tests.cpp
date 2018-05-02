#include <iostream>
#include <cassert>
#include "dec.h"
using namespace std;

void test1(){
  const size_t n = 1;
  int in1 = 0, in2 = 0, in3 = n;
  point points[1] = { (point){0,1} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test2(){
  const size_t n = 1;
  int in1 = 0, in2 = 0, in3 = n;
  point points[1] = { (point){-2,3} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test3(){
  const size_t n = 1;
  int in1 = 0, in2 = 0, in3 = n;
  point points[1] = { (point){2,3} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test4(){
  const size_t n = 2;
  int in1 = 0, in2 = 0, in3 = n;
  point points[3] = { (point){-2,3}, (point){0,1} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test5(){
  const size_t n = 2;
  int in1 = 0, in2 = 0, in3 = n;
  point points[2] = { (point){0,1}, (point){-2,3} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test6(){
  const size_t n = 2;
  int in1 = 0, in2 = 0, in3 = n;
  point points[2] = { (point){0,1}, (point){2,3} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test7(){
  const size_t n = 2;
  int in1 = 0, in2 = 0, in3 = n;
  point points[2] = { (point){2,3}, (point){0,1} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test8(){
  const size_t n = 2;
  int in1 = 0, in2 = 0, in3 = n;
  point points[2] = { (point){-2,3}, (point){2,3} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test9(){
  const size_t n = 2;
  int in1 = 0, in2 = 0, in3 = n;
  point points[2] = { (point){2,3}, (point){-2,3} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test10(){
  const size_t n = 2;
  int in1 = 0, in2 = 0, in3 = n;
  point points[2] = { (point){-2,3}, (point){-2,3}, };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test11(){
  const size_t n = 0;
  int in1 = 0, in2 = 0, in3 = n;
  point points[0] = { };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test12(){
  const size_t n = 3;
  int in1 = 0, in2 = 0, in3 = n;
  point points[3] = { (point){-2,3}, (point){0,1}, (point){2,3} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test13(){
  const size_t n = 3;
  int in1 = 0, in2 = 0, in3 = n;
  point points[3] = { (point){0,1}, (point){2,3}, (point){-2,3} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test14(){
  const size_t n = 3;
  int in1 = 0, in2 = 0, in3 = n;
  point points[3] = { (point){-2,3}, (point){2,3}, (point){0,1} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test15(){
  const size_t n = 3;
  int in1 = 0, in2 = 0, in3 = n;
  point points[3] = { (point){2,3}, (point){-2,3}, (point){0,1} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test16(){
  const size_t n = 4;
  int in1 = 0, in2 = 0, in3 = n;
  point points[4] = { (point){-2,3}, (point){0,1}, (point){2,3}, (point){0,0}, };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test17(){
  const size_t n = 4;
  int in1 = 0, in2 = 0, in3 = n;
  point points[4] = { (point){-2,3}, (point){0,1}, (point){2,3}, (point){-1,-1} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test18(){
  const size_t n = 4;
  int in1 = 0, in2 = 0, in3 = n;
  point points[4] = { (point){0,0}, (point){0,0}, (point){0,0}, (point){0,0} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x > 0 && points[i].y < 0) || (points[i].x < 0 && points[i].y > 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test19(){
  const size_t n = 5;
  int in1 = 0, in2 = 0, in3 = n;
  point points[5] = { (point){-2,3}, (point){0,1}, (point){2,3}, (point){-2,0}, (point){-1,-5} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
}


void test20(){
  const size_t n = 6;
  int in1 = 0, in2 = 0, in3 = n;
  point points[6] = { (point){-2,-4}, (point){5,5}, (point){0,0}, (point){0,0}, (point){3,-4}, (point){-1,7} };
  sort012 ( points, n, in1, in2, in3 );
  int i = 0;
  while ( i < in1 ){
    assert ( points[i].x == 0 || points[i].y == 0 );
    i++;
  }
  while ( i < in3 ){
    assert ( (points[i].x < 0 && points[i].y > 0) || (points[i].x > 0 && points[i].y < 0) );
    i++;
  }
  while ( i < n ){
    assert ( (points[i].x > 0 && points[i].y > 0) || (points[i].x < 0 && points[i].y < 0) );
    i++;
  }
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
