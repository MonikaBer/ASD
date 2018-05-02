#include <iostream>
#include "dec.h"
using namespace std;

int main(){

  int n;
  cout << "Podaj ilosc punktow plaszczyzny\n";
  cin >> n;
  while ( n < 1 ){
    cout << "Podales niedodatnia lub niewlasciwa liczbe. Podaj ilosc punktow jeszcze raz\n";
    cin >> n;
  }
  point points[n];
  int in1 = 0, in2 = 0, in3 = n;

  data ( points, n );

  sort012 ( points, n, in1, in2, in3 );

  print ( points, n, in1, in2, in3 );

  return 0;
}
