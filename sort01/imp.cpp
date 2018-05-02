#include <iostream>
#include "dec.h"
using namespace std;


void data ( student *students, int n ){

  cout << "\n\nPodawaj dane:\n";
  for ( int i = 0; i < n; i++ ){
    cout << "\nPodaj nr indeksu " << i + 1 << " studenta\n";
    cin >> students[i].nr;
    while ( students[i].nr < 1 ){
      cout << "Podales niedodatni nr indeksu. Podaj nr indeksu jeszcze raz\n";
      cin >> students[i].nr;
    }
    cout << "\nPodaj ocene z egzaminu " << i + 1 << " studenta\n";
    cin >> students[i].deg;
    while ( students[i].deg != 2 && students[i].deg != 3 && students[i].deg != 3.5 && students[i].deg != 4 && students[i].deg != 4.5 && students[i].deg != 5 ){
        cout << "Podales nieprawidlowa ocene. Podaj ocene jeszcze raz: ";
        cin >> students[i].deg;
        cout << endl;
    }
  }
}


int sort01 ( student *students, int n ){

  int l = 0, r = n-1;
  student temp;
  while ( l < r ){
    while ( students[l].deg >= 3 )
      l++;
    while ( students[r].deg == 2 )
      r--;
    if ( l < r ){
      temp = students[l];
      students[l] = students[r];
      students[r] = temp;
    }
  }

  if ( students[r].deg == 2 )
    return r - 1;

  return r;
}


void print ( student *students, int n, int result ){

  int i = 0;

  if ( result != -1 ){
    cout << "\n\n\nZdali egzamin:\n";
    while ( i <= result ){
      cout << endl;
      cout << students[i].nr << " - " << students[i].deg;
      i++;
    }
  }

  if ( i != n ){
    cout << "\n\n\nNie zdali egzaminu:\n";
    while ( i < n ){
      cout << endl;
      cout << students[i].nr << " - " << students[i].deg;
      i++;
    }
  }

  cout << "\n\n\n";
}
