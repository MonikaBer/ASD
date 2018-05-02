#include <iostream>
#include <cassert>
#include "dec.h"
using namespace std;


void test1(){

  const size_t n = 1;
  int result;
  student students[n] = { (student){11, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test2(){

  const size_t n = 1;
  int result;
  student students[n] = { (student){42, 3} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test3(){

  const size_t n = 2;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test4(){

  const size_t n = 2;
  int result;
  student students[n] = { (student){11, 5}, (student){44, 2}, };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test5(){

  const size_t n = 3;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 2}, (student){55, 5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test6(){

  const size_t n = 3;
  int result;
  student students[n] = { (student){11, 5}, (student){33, 5}, (student){55, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test7(){

  const size_t n = 3;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 5}, (student){55, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test8(){

  const size_t n = 3;
  int result;
  student students[n] = { (student){11, 3}, (student){33, 2}, (student){55, 4} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test9(){

  const size_t n = 3;
  int result;
  student students[n] = { (student){11, 4}, (student){33, 3}, (student){55, 5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test10(){

  const size_t n = 3;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 2}, (student){55, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test11(){

  const size_t n = 4;
  int result;
  student students[n] = { (student){11, 2}, (student){77, 2}, (student){33, 2}, (student){55, 5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test12(){

  const size_t n = 4;
  int result;
  student students[n] = { (student){11, 5}, (student){77, 3.5}, (student){33, 4}, (student){55, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test13(){

  const size_t n = 4;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 2}, (student){55, 4}, (student){88, 4.5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test14(){

  const size_t n = 4;
  int result;
  student students[n] = { (student){11, 4}, (student){33, 3.5}, (student){55, 2}, (student){44, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test15(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 2}, (student){14, 3}, (student){12, 4}, (student){33, 4.5}, (student){55, 5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test16(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 2}, (student){11, 4}, (student){33, 4.5}, (student){55, 5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test17(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 2}, (student){11, 2}, (student){33, 4.5}, (student){55, 5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test18(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 2}, (student){11, 2}, (student){33, 2}, (student){55, 5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test19(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 5}, (student){33, 5}, (student){11, 3}, (student){33, 4.5}, (student){55, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test20(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 4}, (student){33, 4}, (student){11, 4}, (student){33, 2}, (student){55, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test21(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 3}, (student){33, 2}, (student){11, 5}, (student){33, 2}, (student){55, 4} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test22(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 3}, (student){11, 2}, (student){33, 4}, (student){55, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test23(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 2}, (student){33, 2}, (student){11, 5}, (student){33, 2}, (student){55, 4} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test24(){

  const size_t n = 5;
  int result;
  student students[n] = { (student){11, 5}, (student){33, 5}, (student){11, 2}, (student){33, 4}, (student){55, 2} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
}


void test25(){

  const size_t n = 6;
  int result;
  student students[n] = { (student){17, 2}, (student){11, 2}, (student){33, 2}, (student){11, 5}, (student){33, 4}, (student){55, 3.5} };

  result = sort01 ( students, n );

  int i = 0;
  while ( i <= result ){
    assert ( students[i].deg >= 3 );
    i++;
  }
  while ( i < n ){
    assert ( students[i].deg < 3 );
    i++;
  }

  print ( students, n, result );
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
    test21();
    test22();
    test23();
    test24();
    test25();

    return 0;
}
