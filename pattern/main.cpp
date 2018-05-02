#include <iostream>
#include "dec.h"
using namespace std;


int main(){

  int quantity_of_results = 0;
  int choice = 0, result[100];
  char pattern[100], text[100];

  data ( text, pattern );

  while ( choice != 1 && choice != 2 ){
    cout << "\nWybierz jeden z dwoch algorytmow wyszukiwania wzorca w tekscie:\n";
    cout << "[1] - algorytm naiwny\n";
    cout << "[2] - algorytm Karpa-Rabina\n\n";
    cin >> choice;
    if ( choice == 1 ) {
      naive ( text, pattern, result, quantity_of_results ); }
    else if ( choice == 2 ) {
      kr ( text, pattern, result, quantity_of_results ); }
    else {
      cout << "Bledny wybor. Wybierz algorytm jeszcze raz.\n\n"; }
  }

  print ( result, quantity_of_results );

  return 0;
}
