#include <iostream>
#include "dec.h"
using namespace std;


int main(){

  int n, result;

  cout << "Podaj liczbe studentow\n";
  cin >> n;

  while ( n < 1 ) {
    cout << "\nPodales niedodatnia liczbe. Podaj ilosc studentow jeszcze raz\n";
    cin >> n;
  }

  student students[n];

  data ( students, n );

  result = sort01 ( students, n );

  print ( students, n, result );

  return 0;
}
