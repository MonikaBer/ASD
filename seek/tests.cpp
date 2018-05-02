#include <cassert>
#include <iostream>
#include "dec.h"
using namespace std;

void test_simple() {
  int t[10] = { -5, -3, -1, 0, 5, 11, 12, 13, 17, 20 };
  int a = 0, l, b, r;

  l = linear_seek ( t, 10, a );       //result of linear_seek
  b = binary_i_seek ( t, 10, a );     //result of binary_i_seek
  r = binary_r_helper ( t, 10, a );     //result of binary_r_seek
  cout << l << endl << b << endl << r << endl;
  assert ( l == 3 );
  assert ( l == b );
  assert ( l == r );
}

void test_2() {
  int t[13] = { -5, -3, -1, 0, 5, 11, 12, 13, 17, 20, 22, 24, 26 };
  int a = 24, l, b, r;

  l = linear_seek ( t, 13, a );
  b = binary_i_seek ( t, 13, a );
  r = binary_r_helper ( t, 13, a );
  cout << l << endl << b << endl << r << endl;
  assert ( l == 11 );
  assert ( l == b );
  assert ( l == r );
}

void test_3() {
  int t[0];
  int a = 2, l, b, r;

  l = linear_seek ( t, 0, a );
  b = binary_i_seek ( t, 0, a );
  r = binary_r_helper ( t, 0, a );
  cout << l << endl << b << endl << r << endl;
  assert ( l == -1 );
  assert ( l == b );
  assert ( l == r );
}

void test_4() {
  int t[1];
  t[0] = 3;
  int a = 3, l, b, r;

  l = linear_seek ( t, 1, a );
  b = binary_i_seek ( t, 1, a );
  r = binary_r_helper ( t, 1, a );
  cout << l << endl << b << endl << r << endl;
  assert ( l == 0 );
  assert ( l == b );
  assert ( l == r );
}

void test_5() {
  int t[1] = {5};
  int a = 3, l, b, r;

  l = linear_seek ( t, 1, a );
  b = binary_i_seek ( t, 1, a );
  r = binary_r_helper ( t, 1, a );
  cout << l << endl << b << endl << r << endl;
  assert ( l == -1 );
  assert ( l == b );
  assert ( l == r );
}

void test_6() {
  int t[5] = { 2, 3, 5, 7, 10 };
  int a = 10, l, b, r;

  l = linear_seek ( t, 5, a );
  b = binary_i_seek ( t, 5, a );
  r = binary_r_helper ( t, 5, a );
  cout << l << endl << b << endl << r << endl;
  assert ( l == 4 );
  assert ( l == b );
  assert ( l == r );
}

void test_7() {
  int t[5] = { 2, 3, 5, 7, 10 };
  int a = 2, l, b, r;

  l = linear_seek ( t, 5, a );
  b = binary_i_seek ( t, 5, a );
  r = binary_r_helper ( t, 5, a );
  cout << l << endl << b << endl << r << endl;
  assert ( l == 0 );
  assert ( l == b );
  assert ( l == r );
}

void test_8() {
  int t[8] = { 2, 3, 5, 7, 10, 11, 15, 22 };
  int a = 22, l, b, r;

  l = linear_seek ( t, 8, a );
  b = binary_i_seek ( t, 8, a );
  r = binary_r_helper ( t, 8, a );
  cout << l << endl << b << endl << r << endl;
  assert ( l == 7 );
  assert ( l == b );
  assert ( l == r );
}

void test_9() {
  int t[8] = { -2, 3, 5, 7, 10, 12, 14, 17 };
  int a = -2, l, b, r;

  l = linear_seek ( t, 8, a );
  b = binary_i_seek ( t, 8, a );
  r = binary_r_helper ( t, 8, a );
  cout << l << endl << b << endl << r << endl;
  assert ( l == 0 );
  assert ( l == b );
  assert ( l == r );
}

int main()
{
  test_simple();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  test_7();
  test_8();
  test_9();

  return 0;
}
