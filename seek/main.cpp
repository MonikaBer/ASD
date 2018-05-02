#include <iostream>
#include "dec.h"
using namespace std;

void data ( int *t, int n );

int main() {
  int n, a, linear_result, binary_i_result, binary_r_result;
  cout << "Podaj liczbe elementow tablicy" << endl;
  cin >> n;

  while ( n <= 0 ) {
    cout << "\nPodales niedodatnia liczbe elementow tablicy\n";
    cout << "Podaj rozmiar tablicy jeszcze raz\n";
    cin >> n;
  }

  int t[n];
  data ( t, n );

  cout << endl << "Podaj szukany element: ";
  cin >> a;

  linear_result = linear_seek ( t, n, a );
  cout << endl << "Wyszukiwanie liniowe" << endl;
  if ( linear_result == -1 )
    cout << "Brak szukanego elementu w tablicy" << endl;
  else
    cout << "Indeks szukanego elementu wynosi " << linear_result << endl;


  binary_i_result = binary_i_seek ( t, n, a );
  cout << "\nWyszukiwanie bisekcyjne iteracyjne (nierekurencyjne)" << endl;
  if ( binary_i_result == -1 )
    cout << "Brak szukanego elementu w tablicy" << endl;
  else
    cout << "Indeks szukanego elementu wynosi " << binary_i_result << endl;


  binary_r_result = binary_r_helper ( t, n, a );
  cout << "\nWyszukiwanie bisekcyjne rekurencyjne" << endl;
  if ( binary_r_result == -1 )
    cout << "Brak szukanego elementu w tablicy" << endl;
  else
    cout << "Indeks szukanego elementu wynosi " << binary_r_result << endl;

  return 0;
}

void data ( int *t, int n ) {

  cout << "\nPodawaj elementy tablicy posortowane rosnaco";
  for ( int i = 0; i < n; i++ ) {
    cout << "\nPodaj " << i + 1 << " element tablicy: ";
    cin >> t[i]; }
}
